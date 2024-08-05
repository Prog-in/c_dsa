#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// type of the value member of the Node
#define T_DATA int

typedef struct Node {
    struct Node *next;
    T_DATA value;
} Node;

/*  */
Node* initList(T_DATA defaultValue);

/* Warning: if the nodes values were malloc'ed, you need to free them manually! */
void destroyList(Node *head);

/*  */
Node* addNode(Node *head, T_DATA v);

/*  */
Node* removeNode(Node *head, T_DATA v);

/*  */
Node* searchNode(Node *head, T_DATA v);

#endif // LINKED_LIST_H