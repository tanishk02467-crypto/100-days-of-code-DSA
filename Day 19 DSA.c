#include <stdio.h>

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = 6;
    int i, j, sum, min_sum, a, b;

    a = arr[0];
    b = arr[1];
    min_sum = a + b;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            sum = arr[i] + arr[j];

            int current_dist = (sum < 0) ? -sum : sum;
            int best_dist = (min_sum < 0) ? -min_sum : min_sum;

            if (current_dist < best_dist) {
                min_sum = sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("Closest pair: %d and %d\n", a, b);
    printf("Sum: %d\n", min_sum);

    return 0;
}
