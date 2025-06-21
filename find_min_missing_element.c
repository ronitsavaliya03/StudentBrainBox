#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 3
#define MAX 100

int findMinMissing(int matrix[ROWS][COLS]) {
    bool present[MAX + 1] = {false};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int val = matrix[i][j];
            if (val > 0 && val <= MAX) {
                present[val] = true;
            }
        }
    }

    // for (int i = 1; i <= MAX; i++) {
    //     printf("%d", present[i]);
    // }

    for (int i = 1; i <= MAX; i++) {
        if (!present[i])
            return i;
    }

    return MAX + 1; 
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 3, 5},
        {2, 11, 4},
        {7, 8, 10}
    };

    int missing = findMinMissing(matrix);
    printf("Minimum missing element is: %d\n", missing);

    return 0;
}
