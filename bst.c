#include <stdio.h>
#include <stdlib.h>
#include "student.h"

BSTNode *bst_insert(BSTNode *root, Student data, int *comparisons) {
    if (root == NULL) {
        BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
        if (node == NULL) {
            fprintf(stderr, "Memory allocation failed while inserting into BST.\n");
            exit(EXIT_FAILURE);
        }
        node->data = data;
        node->left = node->right = NULL;
        return node;
    }

    (*comparisons)++;
    if (data.id < root->data.id) {
        root->left = bst_insert(root->left, data, comparisons);
    } else if (data.id > root->data.id) {
        root->right = bst_insert(root->right, data, comparisons);
    }
    return root; /* Duplicate IDs are ignored. */
}

BSTNode *bst_search(BSTNode *root, int id, int *comparisons) {
    while (root != NULL) {
        (*comparisons)++;
        if (id == root->data.id) return root;
        root = (id < root->data.id) ? root->left : root->right;
    }
    return NULL;
}

void bst_inorder(BSTNode *root) {
    if (root == NULL) return;
    bst_inorder(root->left);
    printf("%-6d %-14s %-8s %.2f\n",
           root->data.id, root->data.name,
           root->data.department, root->data.cgpa);
    bst_inorder(root->right);
}

int bst_height(BSTNode *root) {
    if (root == NULL) return 0;
    int left_height = bst_height(root->left);
    int right_height = bst_height(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

void bst_free(BSTNode *root) {
    if (root == NULL) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}
