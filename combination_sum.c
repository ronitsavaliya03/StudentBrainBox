// Problem Statement:
// Given an array and a target, find all combinations (not necessarily continuous subarrays) of elements (you can reuse elements) such that the sum equals the target.

#include <stdio.h>

#define MAX 100

void printCombination(int comb[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", comb[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

void findCombinations(int arr[], int n, int target, int comb[], int index, int start) {
    if (target == 0) {
        printCombination(comb, index);
        return;
    }

    for (int i = start; i < n; i++) {
        if (arr[i] <= target) {
            comb[index] = arr[i]; 
            findCombinations(arr, n, target - arr[i], comb, index + 1, i); // reuse the same element
        }
    }
}

int main() {
    int arr[] = {2, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int comb[MAX]; 

    printf("Combinations that sum to %d:\n", target);
    findCombinations(arr, n, target, comb, 0, 0);

    return 0;
}


// target = 7, start = 0
// Try arr[0] = 2
// -> comb = [2]
// -> call findCombinations(..., target = 5, index = 1)

// target = 5, start = 0
// Try arr[0] = 2 again
// -> comb = [2, 2]
// -> call findCombinations(..., target = 3, index = 2)

// target = 3, start = 0
// Try arr[0] = 2 again
// -> comb = [2, 2, 2]
// -> call findCombinations(..., target = 1, index = 3)

// target = 1, start = 0
// Try arr[0] = 2 again -> target becomes -1 -> discard this path
// Backtrack to comb = [2, 2]

// Now try arr[1] = 3
// -> comb = [2, 2, 3]
// -> target = 0 -> Valid! Print: [2, 2, 3]
// Backtrack

// Back to comb = [2]
// Try arr[1] = 3
// -> comb = [2, 3]
// -> target = 2 -> go deeper
// Try arr[1] = 3 again -> target = -1 -> invalid -> backtrack

// Try arr[2] = 6 -> comb = [2, 6] -> target = 1 -> invalid -> backtrack

// Try arr[3] = 7 -> comb = [7] -> target = 0 -> Valid! Print: [7]

