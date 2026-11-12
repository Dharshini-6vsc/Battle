#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void run_experiment(void);

static void print_student(const Student *s) {
    printf("\nStudent found!\n");
    printf("ID         : %d\n", s->id);
    printf("Name       : %s\n", s->name);
    printf("Department : %s\n", s->department);
    printf("CGPA       : %.2f\n", s->cgpa);
}

static void print_header(void) {
    printf("\n%-6s %-14s %-8s %s\n", "ID", "NAME", "DEPT", "CGPA");
    printf("------------------------------------------\n");
}

int main(void) {
    BSTNode *bst = NULL;
    AVLNode *avl = NULL;
    HashTable hash;
    int i, choice, id, comparisons, probes, inserted;
    Student found;

    hash_init(&hash);

    /* Build all three structures with exactly the same dataset/order. */
    for (i = 0; i < DATASET_SIZE; i++) {
        int ignored_bst = 0, ignored_avl = 0;
        bst = bst_insert(bst, students[i], &ignored_bst);
        avl = avl_insert(avl, students[i], &ignored_avl);
        hash_insert(&hash, students[i]);
    }

    do {
        printf("\n============================================\n");
        printf("       STUDENT RECORD SEARCH SYSTEM\n");
        printf("============================================\n");
        printf("Dataset loaded: %d student records\n", DATASET_SIZE);
        printf("1. Insert a new student\n");
        printf("2. Search using BST\n");
        printf("3. Search using AVL Tree\n");
        printf("4. Search using Hashing (Linear Probing)\n");
        printf("5. Display BST inorder traversal\n");
        printf("6. Display AVL inorder traversal\n");
        printf("7. Display occupied hash table slots\n");
        printf("8. Run mini experiment and comparison\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1: {
                Student s;
                printf("Enter student ID: ");
                scanf("%d", &s.id);
                printf("Enter student name (one word): ");
                scanf("%49s", s.name);
                printf("Enter department (e.g., CSE): ");
                scanf("%19s", s.department);
                printf("Enter CGPA: ");
                scanf("%f", &s.cgpa);

                /* Prevent duplicate IDs in all three structures. */
                comparisons = 0;
                if (bst_search(bst, s.id, &comparisons) != NULL) {
                    printf("Student ID already exists. Record not inserted.\n");
                    break;
                }
                comparisons = 0;
                bst = bst_insert(bst, s, &comparisons);
                comparisons = 0;
                avl = avl_insert(avl, s, &comparisons);
                inserted = hash_insert(&hash, s);
                if (inserted) {
                    printf("Record inserted into BST, AVL and Hashing.\n");
                } else {
                    printf("Hash table insertion failed. Check table capacity.\n");
                }
                break;
            }
            case 2:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                comparisons = 0;
                {
                    BSTNode *result = bst_search(bst, id, &comparisons);
                    if (result) print_student(&result->data);
                    else printf("Student not found.\n");
                    printf("BST key comparisons: %d\n", comparisons);
                }
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                comparisons = 0;
                {
                    AVLNode *result = avl_search(avl, id, &comparisons);
                    if (result) print_student(&result->data);
                    else printf("Student not found.\n");
                    printf("AVL key comparisons: %d\n", comparisons);
                }
                break;
            case 4:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                if (hash_search(&hash, id, &found, &probes))
                    print_student(&found);
                else
                    printf("Student not found.\n");
                printf("Hash table probes: %d\n", probes);
                break;
            case 5:
                print_header();
                bst_inorder(bst);
                break;
            case 6:
                print_header();
                avl_inorder(avl);
                break;
            case 7:
                hash_display(&hash);
                break;
            case 8:
                run_experiment();
                break;
            case 9:
                printf("Thank you for using the Student Record Search System.\n");
                break;
            default:
                printf("Invalid choice. Please select 1-9.\n");
        }
    } while (choice != 9);

    bst_free(bst);
    avl_free(avl);
    return 0;
}
