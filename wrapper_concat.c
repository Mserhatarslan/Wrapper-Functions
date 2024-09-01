#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

char* wrapper_concat(const char *p1, const char *p2) {
    char *pd = (char*)malloc(strlen(p1) + strlen(p2) + 1);
    if (!pd) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    return strcat(strcpy(pd, p1), p2);
}

int main(void) {
    char s1[SIZE];
    char s2[SIZE];

    printf("Enter the first string: ");
    if (fgets(s1, sizeof(s1), stdin) != NULL) {
        s1[strcspn(s1, "\n")] = '\0';
    } else {
        fprintf(stderr, "Failed to read input.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the second string: ");
    if (fgets(s2, sizeof(s2), stdin) != NULL) {
        s2[strcspn(s2, "\n")] = '\0';
    } else {
        fprintf(stderr, "Failed to read input.\n");
        return EXIT_FAILURE;
    }

    char* p = wrapper_concat(s1, s2);
    if (p != NULL) {
        printf("(%s) + (%s) = (%s)\n", s1, s2, p);

        free(p);
    } else {
        fprintf(stderr, "Failed to concatenate strings.\n");
    }

    return 0;
}
