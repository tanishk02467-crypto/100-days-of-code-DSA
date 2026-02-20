#include <stdio.h>

int main() {
    int n, i, j, val, sum = 0;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &val);
            
            if (i == j) {
                sum += val;
            }
        }
    }

    printf("Sum of primary diagonal: %d\n", sum);
    return 0;
}
