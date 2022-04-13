#include "../src/xor-list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/** Construct a new XOR list node struct */
StructXORListNode(Node, int);

/** use as callback function of traverse */
void print_node(Node* node) {
    if (node) {
        printf("Node %p: \n\tval = %d\n\tbeacon = %p\n", node, node->val, node->beacon);
    } else {
        printf("No Node\n");
    }
}

typedef struct {
    double x;
    double y;
} Point;
StructXORListNode(PointNode, Point);

int main() {
    // create nodes
    Node* n1 = create_Node(1);
    Node* n2 = create_Node(2);
    Node* n3 = create_Node(3);
    Node* n4 = create_Node(4);
    Node* n5 = create_Node(5);
    Node* n6 = create_Node(6);

    // link nodes
    n2->insert(n2, n1, NULL);
    n3->insert(n3, n2, NULL);
    n4->insert(n4, n3, NULL);
    n5->insert(n5, n4, NULL);
    n6->insert(n6, n5, NULL);

    printf("Traversing forward:\n");
    printf("Count = %zu\n\n", n1->traverse(n1, n2, &print_node));

    printf("n3 removed\n\n");
    n3->remove(n3, n4);

    printf("Traversing backward:\n");
    printf("Count = %zu\n\n", n6->traverse(n6, n5, &print_node));

    printf("n3 inserted\n\n");
    n3->insert(n3, n5, n6);

    printf("Traversing forward:\n");
    printf("Count = %zu\n\n", n1->traverse(n1, n2, &print_node));

    return 0;
}
