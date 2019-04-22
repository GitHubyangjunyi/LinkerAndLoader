#include <stdio.h>
#include <pthread.h>

int pthread_create(pthread_t *__restrict __newthread,
			   const pthread_attr_t *__restrict __attr,
			   void *(*__start_routine) (void *),
			   void *__restrict __arg)__attribute__((weak));

int main()
{
    if (pthread_create) {
        printf("This is multi-thread version!\n");

    }
    else
    {
        printf("This is single-thread version!\n");
    }
    
    return 0;
}
