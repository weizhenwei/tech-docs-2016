#include <stdio.h>

void function(int *pnValue) {
    pnValue = 0000000000;
    *pnValue = 8;
}

int main() {
    int *p = NULL;

    function(p);

    printf("%p, %d\n", p, *p);

    return 0;
}



