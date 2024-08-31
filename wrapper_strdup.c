#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

char* wrapper_strdup(const char* p) {
    if (p == NULL) {
        return NULL; 
    }

    char* pd = (char*)malloc(strlen(p) + 1);
    if (!pd) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    return strcpy(pd, p);
}

int main(void) {
    char str[SIZE];

    printf("Enter a string: ");
    if (scanf("%999s", str) != 1) {
        fprintf(stderr, "Failed to read input.\n");
        return EXIT_FAILURE;
    }

    printf("Original string: (%s)\n", str);

    char* pd = wrapper_strdup(str);

    free(pd);


    return 0;
}
