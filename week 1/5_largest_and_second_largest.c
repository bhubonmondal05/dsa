#include <stdio.h>
int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int first = -2147483648, second = -2147483648;
    int i;
    for(i = 0; i < size; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    printf("%d %d\n", first, second);
}
