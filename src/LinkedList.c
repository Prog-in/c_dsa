#include "LinkedList.h"
#include <stdlib.h>

Node* initList(T_DATA *defaultValue)
{
    Node *list = malloc(sizeof(Node));
    if (list != NULL)
    {
        list->next = NULL;
        list->value = defaultValue;
    }
    return list;
}

Node* addNode(Node *head, T_DATA *v)
{
    Node *newHead = initList(v);
    newHead->next = head;
    return newHead;
}

Node* removeNode(Node *head, T_DATA *v)
{
    if (head != NULL && head->value == v)
    {
        Node *new_head = head->next;
        free(head);
        return new_head;
    }

    Node *prev = head, *p = head;
    while (p != NULL && p->value != v) 
    {
        prev = p;
        p = p->next;
    }

    if (p != NULL)
    {
        prev->next = p->next;
        free(p);
    }

    return head;
}

Node* searchNode(Node *head, T_DATA *v)
{
    while (head != NULL && head->value != v)
    {
        head = head->next;
    }
    return head;
}