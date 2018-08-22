#include <stdio.h>
#include "mymalloc.h"
int main() {
    my_init();
    int *p = (int *)malloc(sizeof(int));
    return 0;
}