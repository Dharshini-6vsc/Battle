#include <stdio.h>
#include "student.h"

void hash_init(HashTable *table) {
    int i;
    table->insertion_collisions = 0;
    for (i = 0; i < HASH_SIZE; i++) {
        table->entries[i].occupied = 0;
    }
}

int hash_insert(HashTable *table, Student data) {
    int start = data.id % HASH_SIZE;
    int i;

    for (i = 0; i < HASH_SIZE; i++) {
        int index = (start + i) % HASH_SIZE;
        if (!table->entries[index].occupied) {
            table->entries[index].data = data;
            table->entries[index].occupied = 1;
            return 1;
        }
        if (table->entries[index].data.id == data.id) {
            return 0; /* Duplicate key. */
        }
        table->insertion_collisions++;
    }
    return 0; /* Table is full. */
}

int hash_search(const HashTable *table, int id, Student *found, int *probes) {
    int start = id % HASH_SIZE;
    int i;

    *probes = 0;
    for (i = 0; i < HASH_SIZE; i++) {
        int index = (start + i) % HASH_SIZE;
        (*probes)++;
        if (!table->entries[index].occupied) return 0;
        if (table->entries[index].data.id == id) {
            if (found != NULL) *found = table->entries[index].data;
            return 1;
        }
    }
    return 0;
}

void hash_display(const HashTable *table) {
    int i;
    printf("\nHASH TABLE (occupied slots only)\n");
    printf("%-8s %-8s %-14s %-8s %-6s\n",
           "INDEX", "ID", "NAME", "DEPT", "CGPA");
    for (i = 0; i < HASH_SIZE; i++) {
        if (table->entries[i].occupied) {
            Student s = table->entries[i].data;
            printf("%-8d %-8d %-14s %-8s %.2f\n",
                   i, s.id, s.name, s.department, s.cgpa);
        }
    }
}
