#include <stdio.h>

int main() {
    int n = 6;
    int start = 1;

    for (int i = 1; i <= n; i++) {
        int value = start;
        
        for (int j = 1; j <= i; j++) {
            printf("%02d ", value);
            value = value - (n - j);
        }

        start = start + (n - i); 
        printf("\n");
    }

    return 0;
}
