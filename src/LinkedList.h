#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// type of the data in Node
#define T_DATA int

typedef struct Node {
    struct Node *next;
    T_DATA *value;
} Node;

/*  */
Node* initList(T_DATA *defaultValue);

/*  */
Node* addNode(Node *head, T_DATA *v);

/*  */
Node* removeNode(Node *head, T_DATA *v);

/*  */
Node* searchNode(Node *head, T_DATA *v);

#endif // LINKED_LIST_H