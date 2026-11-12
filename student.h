#ifndef STUDENT_H
#define STUDENT_H

#define DATASET_SIZE 40
#define HASH_SIZE 67

typedef struct {
    int id;
    char name[50];
    char department[20];
    float cgpa;
} Student;

typedef struct BSTNode {
    Student data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct AVLNode {
    Student data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

typedef struct {
    int occupied;
    Student data;
} HashEntry;

typedef struct {
    HashEntry entries[HASH_SIZE];
    int insertion_collisions;
} HashTable;

/* Dataset */
extern Student students[DATASET_SIZE];
void load_dataset(Student records[], int count);

/* BST */
BSTNode *bst_insert(BSTNode *root, Student data, int *comparisons);
BSTNode *bst_search(BSTNode *root, int id, int *comparisons);
void bst_inorder(BSTNode *root);
int bst_height(BSTNode *root);
void bst_free(BSTNode *root);

/* AVL */
AVLNode *avl_insert(AVLNode *root, Student data, int *comparisons);
AVLNode *avl_search(AVLNode *root, int id, int *comparisons);
void avl_inorder(AVLNode *root);
int avl_height(AVLNode *root);
void avl_free(AVLNode *root);

/* Hashing with linear probing */
void hash_init(HashTable *table);
int hash_insert(HashTable *table, Student data);
int hash_search(const HashTable *table, int id, Student *found, int *probes);
void hash_display(const HashTable *table);

#endif
