#include <stdint.h>

enum NodeColor { BLACK, RED };

typedef struct RBNode {
    struct RBNode* left;
    struct RBNode* right;
    struct RBNode* parent;
    enum NodeColor color;
    uint64_t       key;
} RBNode;

typedef struct RBTree {
    RBNode* root;
    RBNode* nil;
} RBTree;

RBTree* rb_tree_create() {
    RBTree* tree = malloc(sizeof(RBTree));
    tree->nil = malloc(sizeof(RBNode));
    tree->nil->color = BLACK;
    tree->nil->left = tree->nil;
    tree->nil->right = tree->nil;
    tree->nil->parent = tree->nil;
    tree->root = tree->nil;
    return tree;
}

void rb_tree_destroy(RBTree* tree) {
    free(tree->nil);
    free(tree);
}

void rb_tree_rotate_left(RBTree* tree, RBNode* node) {
    RBNode* right = node->right;
    node->right = right->left;
    if (right->left != tree->nil) {
        right->left->parent = node;
    }
    right->parent = node->parent;

    if (node->parent == tree->nil) {
        tree->root = right;
    } else if (node == node->parent->left) {
        node->parent->left = right;
    } else {
        node->parent->right = right;
    }

    right->left = node;
    node->parent = right;
}

void rb_tree_rotate_right(RBTree* tree, RBNode* node) {
    RBNode* left = node->left;
    node->left = left->right;
    if (left->right != tree->nil) {
        left->right->parent = node;
    }
    left->parent = node->parent;

    if (node->parent == tree->nil) {
        tree->root = left;
    } else if (node == node->parent->left) {
        node->parent->left = left;
    } else {
        node->parent->right = left;
    }

    left->right = node;
    node->parent = left;
}

void rb_tree_insert_fixup(RBTree* tree, RBNode* node) {
    while (node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            RBNode* uncle = node->parent->parent->right;
            if (uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rb_tree_rotate_left(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rb_tree_rotate_right(tree, node->parent->parent);
            }
        } else {
            RBNode* uncle = node->parent->parent->left;
            if (uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rb_tree_rotate_right(tree, node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rb_tree_rotate_left(tree, node->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}

void rb_tree_insert(RBTree* tree, RBNode* node) {
    RBNode* y = tree->nil;
    RBNode* x = tree->root;
    while (x != tree->nil) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    node->parent = y;
    if (y == tree->nil) {
        tree->root = node;
    } else if (node->key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }
    node->left = tree->nil;
    node->right = tree->nil;
    node->color = RED;
    rb_tree_insert_fixup(tree, node);
}