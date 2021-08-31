#include <stdio.h>
void update(int* a, int* b) {//!the function that update a and b 
    int temp = *a;
    *a += *b;
    *b -= temp;
    if (*b < 0)
    {
        (*b) *= -1;
    }
}
int main() {
    int a, b;
    int* pa = &a, * pb = &b;
    scanf("%d %d", &a, &b);
    update(pa, pb);//!calling function
    printf("%d\n%d", a, b);
    return 0;
}