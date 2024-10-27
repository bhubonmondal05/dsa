#include <stdio.h>
int main() {
    int a[] = {3, 1, 4, 5, 2}, i, j, t;
    for (i = 0; i < 5; i++) for (j = i + 1; j < 5; j++) if (a[i] > a[j]) t = a[i], a[i] = a[j], a[j] = t;
    for (i = 0; i < 5; i++) printf("%d ", a[i]);
}
