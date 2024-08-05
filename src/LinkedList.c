#include "LinkedList.h"
#include <stdlib.h>

Node* initList(T_DATA defaultValue)
{
    Node *head = malloc(sizeof(Node));
    if (head != NULL)
    {
        head->next = NULL;
        head->value = defaultValue;
    }
    return head;
}

void destroyList(Node *head)
{
    while (head != NULL)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

Node* addNode(Node *head, T_DATA v)
{
    Node *newHead = initList(v);

    if (newHead == NULL)
    {
        return head;
    }

    newHead->next = head;
    return newHead;
}

Node* removeNode(Node *head, T_DATA v)
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

Node* searchNode(Node *head, T_DATA v)
{
    while (head != NULL && head->value != v)
    {
        head = head->next;
    }
    return head;
}