#include <stdio.h>
#include <stdlib.h>
#include "student.h"

static int max_int(int a, int b) { return a > b ? a : b; }
static int node_height(AVLNode *node) { return node == NULL ? 0 : node->height; }

static AVLNode *new_node(Student data) {
    AVLNode *node = (AVLNode *)malloc(sizeof(AVLNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed while inserting into AVL.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

static AVLNode *right_rotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = 1 + max_int(node_height(y->left), node_height(y->right));
    x->height = 1 + max_int(node_height(x->left), node_height(x->right));
    return x;
}

static AVLNode *left_rotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = 1 + max_int(node_height(x->left), node_height(x->right));
    y->height = 1 + max_int(node_height(y->left), node_height(y->right));
    return y;
}

static int balance_factor(AVLNode *node) {
    return node == NULL ? 0 : node_height(node->left) - node_height(node->right);
}

AVLNode *avl_insert(AVLNode *root, Student data, int *comparisons) {
    if (root == NULL) return new_node(data);

    (*comparisons)++;
    if (data.id < root->data.id) {
        root->left = avl_insert(root->left, data, comparisons);
    } else if (data.id > root->data.id) {
        root->right = avl_insert(root->right, data, comparisons);
    } else {
        return root;
    }

    root->height = 1 + max_int(node_height(root->left), node_height(root->right));
    int balance = balance_factor(root);

    /* LL */
    if (balance > 1 && data.id < root->left->data.id)
        return right_rotate(root);
    /* RR */
    if (balance < -1 && data.id > root->right->data.id)
        return left_rotate(root);
    /* LR */
    if (balance > 1 && data.id > root->left->data.id) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    /* RL */
    if (balance < -1 && data.id < root->right->data.id) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

AVLNode *avl_search(AVLNode *root, int id, int *comparisons) {
    while (root != NULL) {
        (*comparisons)++;
        if (id == root->data.id) return root;
        root = (id < root->data.id) ? root->left : root->right;
    }
    return NULL;
}

void avl_inorder(AVLNode *root) {
    if (root == NULL) return;
    avl_inorder(root->left);
    printf("%-6d %-14s %-8s %.2f\n",
           root->data.id, root->data.name,
           root->data.department, root->data.cgpa);
    avl_inorder(root->right);
}

int avl_height(AVLNode *root) {
    return node_height(root);
}

void avl_free(AVLNode *root) {
    if (root == NULL) return;
    avl_free(root->left);
    avl_free(root->right);
    free(root);
}
