#include <stdio.h>

int main() {
    int n;
    printf("Enter odd size (n >= 5): ");
    scanf("%d", &n);

    if (n < 5 || n % 2 == 0) {
        printf("Please enter an odd number greater than or equal to 5.\n");
        return 0;
    }

    int mid = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // Top-left arm
            if ((i < mid && j == 0) || (i == 0 && j >= mid)) 
                printf("* ");
            
            // Middle row and column
            else if (i == mid || j == mid) 
                printf("* ");

            // Bottom-right arm
            else if ((i == n - 1 && j <= mid) || (j == n - 1 && i > mid)) 
                printf("* ");
            
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}
