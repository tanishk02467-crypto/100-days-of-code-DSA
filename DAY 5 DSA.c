

#include <stdio.h>

int main() {
    int p, q, i, j;
    
    scanf("%d", &p);
    int log1[p];
    for (i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    scanf("%d", &q);
    int log2[q];
    for (i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    int merged[p + q];
    i = 0; 
    j = 0; 
    int k = 0; 
    
  
    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    
    while (i < p) {
        merged[k++] = log1[i++];
    }
    while (j < q) {
        merged[k++] = log2[j++];
    }
    
    
    for (i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");
    
    return 0;
}