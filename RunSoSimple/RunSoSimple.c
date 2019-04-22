#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char* argv[])
{
    void* handle;
    int (*func) (int);
    char* error;

    handle = dlopen(argv[1], RTLD_NOW);
    if (handle == NULL)
    {
        printf("Open library %s error: %s\n", argv[1], dlerror());
        return -1;
    }
    
    func = dlsym(handle, "foobar");
    if ((error = dlerror()) != NULL)
    {
        printf("Symbol sin not found: %s\n", error);
        goto exit_runso;
    }
    printf("%d\n", func(2));

    exit_runso:
    dlclose(handle);
}
