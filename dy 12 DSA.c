#include <stdio.h>

int main() {
    int n, i, j, flag = 1;

    printf("Enter the order of the square matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) { 
            if (matrix[i][j] != matrix[j][i]) {
                flag = 0; 
                break;
            }
        }
        if (flag == 0) break;
    }

    if (flag == 1) {
        printf("\nThe matrix is symmetric.\n");
    } else {
        printf("\nThe matrix is NOT symmetric.\n");
    }

    return 0;
}
