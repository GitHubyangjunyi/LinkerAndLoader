#include <stdio.h>
#include <dlfcn.h>
#define SETUP_STACK     \
i = 2;                  \
while (++i < argc - 1)  \
{                       \
    switch (argv[i][0]) \
    {                   \
    case 'i':           \
        asm volatile("push %0" :: "r"(atoi(&argv[i][1])));  \
        esp += 4;                                           \
        break;                                              \
    case 'd':                                               \
        atof(&argv[i][1]);                                  \
        asm volatile("subl $8, %esp\n"                      \
                     "fstpl (%esp)");                       \
        esp += 8;                                           \
        break;                                              \
    case 's':                                               \
        asm volatile("push %0" :: "r"(&argv[i][1]));        \
        esp += 4;                                           \
        break;                                              \
    default:                                                \
        printf("error argument type");                      \
        goto exit_runso;                                    \
    }                                                       \
}

#define RESTORE_STACK asm volatile("add %0,%%esp":: "r"(esp))

int main(int argc, char* argv[])
{
    int i;
    int esp=0;
    void* handle;
    char* error;
    void* func;

    handle = dlopen(argv[1], RTLD_NOW);
    if (handle == NULL)
    {
        printf("Can't find library %s\n", argv[1]);
        return -1;
    }
    printf("Library open successed!\n");

    func = dlsym(handle, argv[2]);
    if ((error = dlerror()) != NULL)
    {
        printf("Find symbol %s error: %s\n", argv[1]);
        goto exit_runso;
    }
    printf("Find symbol successed!\n");

    switch (argv[argc - 1][0])
    {
    case 'i':
        {
            int (*func_int)() = func;
            SETUP_STACK;
            int ret = func_int();
            RESTORE_STACK;
            printf("int ret = %d\n", ret);
            break;
        }
    case 'd':
        {
            double (*func_double)() = func;
            SETUP_STACK;
            double ret = func_double();
            RESTORE_STACK;
            printf("double ret = %f\n", ret);
            break;
        }
    case 's':
        {
            char* (*func_str)() = func;
            SETUP_STACK;
            char* ret = func_str();
            RESTORE_STACK;
            printf("string ret = %s\n", ret);
            break;
        }
    case 'v':
        {
            void (*func_void)() = func;
            SETUP_STACK;
            func_void();
            RESTORE_STACK;
            printf("void ret = void");
            break;
        }
    }

    exit_runso:
    dlclose(handle);
}
