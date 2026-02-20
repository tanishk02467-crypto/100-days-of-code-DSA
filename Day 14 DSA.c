#include <stdio.h>

int main() {
    int n, i, j, val;

    printf("Enter order: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &val);
            
            if ((i == j && val != 1) || (i != j && val != 0)) {
                printf("Not an Identity Matrix.\n");
                return 0; 
            }
        }
    }

    printf("It is an Identity Matrix.\n");
    return 0;
}
