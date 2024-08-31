#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void* wrapper_malloc(size_t n)
{
    void *pd = malloc(n * sizeof(int)); 
    if(!pd){
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    return pd;
}


void set_random_array(int* pd, size_t len)
{
    for(size_t i = 0; i < len; ++i)
    {
        pd[i] = rand();
    }
}

void set_print_array(int* pd, size_t len)
{
    for(size_t i = 0; i < len; ++i)
    {
       printf("pd[%zu] = %d \n", i, pd[i]);
    }
}

int main(void)
{
    size_t n;
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%zu", &n);

    int *pd = (int*)wrapper_malloc(n);

    set_random_array(pd, n);
    set_print_array(pd, n);

    free(pd); 

    return 0;
}
