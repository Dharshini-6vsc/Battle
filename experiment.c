#include <stdio.h>
#include "student.h"

void run_experiment(void) {
    BSTNode *bst = NULL;
    AVLNode *avl = NULL;
    HashTable hash;
    int bst_insert_comparisons = 0, avl_insert_comparisons = 0;
    int i, bst_success = 0, avl_success = 0, hash_success = 0;
    int bst_fail = 0, avl_fail = 0, hash_fail = 0;
    Student found;

    hash_init(&hash);

    for (i = 0; i < DATASET_SIZE; i++) {
        bst = bst_insert(bst, students[i], &bst_insert_comparisons);
        avl = avl_insert(avl, students[i], &avl_insert_comparisons);
        hash_insert(&hash, students[i]);
    }

    /* Successful search: use an existing key from the shared dataset. */
    int successful_id = students[19].id;
    bst_search(bst, successful_id, &bst_success);
    avl_search(avl, successful_id, &avl_success);
    hash_search(&hash, successful_id, &found, &hash_success);

    /* Unsuccessful search: key is deliberately absent from the dataset. */
    int unsuccessful_id = 9999;
    bst_search(bst, unsuccessful_id, &bst_fail);
    avl_search(avl, unsuccessful_id, &avl_fail);
    hash_search(&hash, unsuccessful_id, &found, &hash_fail);

    printf("\n================ MINI EXPERIMENT ================\n");
    printf("Dataset size              : %d records\n", DATASET_SIZE);
    printf("Successful search key     : %d\n", successful_id);
    printf("Unsuccessful search key   : %d\n", unsuccessful_id);
    printf("\n%-30s %-10s %-10s %-10s\n",
           "PARAMETER", "BST", "AVL", "HASHING");
    printf("---------------------------------------------------------------\n");
    printf("%-30s %-10d %-10d %-10s\n",
           "Successful search comparisons", bst_success, avl_success, "-");
    printf("%-30s %-10s %-10s %-10d\n",
           "Successful search probes", "-", "-", hash_success);
    printf("%-30s %-10d %-10d %-10s\n",
           "Unsuccessful search comparisons", bst_fail, avl_fail, "-");
    printf("%-30s %-10s %-10s %-10d\n",
           "Unsuccessful search probes", "-", "-", hash_fail);
    printf("%-30s %-10d %-10d %-10d\n",
           "Insertion comparisons/collisions",
           bst_insert_comparisons, avl_insert_comparisons,
           hash.insertion_collisions);
    printf("%-30s %-10d %-10d %-10s\n",
           "Tree height", bst_height(bst), avl_height(avl), "N/A");

    printf("\nInsertion observation:\n");
    printf("BST insertion key comparisons : %d\n", bst_insert_comparisons);
    printf("AVL insertion key comparisons : %d\n", avl_insert_comparisons);
    printf("Hash insertion collisions     : %d\n", hash.insertion_collisions);

    printf("\nInterpretation:\n");
    printf("- BST height depends on insertion order and may become skewed.\n");
    printf("- AVL maintains balance through rotations.\n");
    printf("- Hashing uses linear probing; each occupied slot encountered\n");
    printf("  during insertion is counted as a collision.\n");
    printf("- Compare the measured values before declaring a winner.\n");

    bst_free(bst);
    avl_free(avl);
}
