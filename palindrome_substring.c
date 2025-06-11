#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    char str[] = "abcba";
    int len = strlen(str);

    printf("Palindrome substrings are:\n");

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (isPalindrome(str, i, j)) {
                for (int k = i; k <= j; k++)
                    printf("%c", str[k]);
                printf("\n");
            }
        }
    }

    return 0;
}
