#include <stdio.h>
#include <string.h>
int main() {
    char s[] = "madam"; 
    int i, len = strlen(s), f = 1;
    for (i = 0; i < len / 2; i++) if (s[i] != s[len - i - 1]) f = 0;
    printf(f ? "It's a Palindrome" : "It's not Palindrome");
}
