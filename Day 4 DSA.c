

#include <stdio.h>

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    int arr[n];
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int left = 0, right = n - 1;
    while (left < right) {
        
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
  
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}