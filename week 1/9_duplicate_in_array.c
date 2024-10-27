#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 2}, i, j, f = 0;
    for (i = 0; i < 5; i++) for (j = i + 1; j < 5; j++) if (a[i] == a[j]) f = 1;
    printf(f ? "Duplicate found" : "No duplicate");
}
