#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EMPTY -1
#define DELETED -2

typedef struct {
    int *table;
    int size;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

int hashFunction(int key, int m) {
    int r = key % m;
    return (r < 0) ? r + m : r;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    int hash = hashFunction(key, m);
    
    for (int i = 0; i < m; i++) {
        int index = (hash + i * i) % m;
        
        if (ht->table[index] == EMPTY || ht->table[index] == DELETED) {
            ht->table[index] = key;
            return;
        }
    }
}

bool search(HashTable* ht, int key) {
    int m = ht->size;
    int hash = hashFunction(key, m);
    
    for (int i = 0; i < m; i++) {
        int index = (hash + i * i) % m;
        
        if (ht->table[index] == EMPTY) {
            return false;
        }
        if (ht->table[index] == key) {
            return true;
        }
    }
    return false;
}

int main() {
    int m, q;
    if (scanf("%d", &m) != 1) return 0;
    if (scanf("%d", &q) != 1) return 0;

    HashTable* ht = createTable(m);

    for (int i = 0; i < q; i++) {
        char command[10];
        int key;
        if (scanf("%s %d", command, &key) != 2) break;

        if (strcmp(command, "INSERT") == 0) {
            insert(ht, key);
        } else if (strcmp(command, "SEARCH") == 0) {
            if (search(ht, key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}
