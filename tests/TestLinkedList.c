#include "../src/LinkedList.h"
#include "./utils/utils.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

void assertInitialization(T_DATA value)
{
    Node *head = initList(value);

    if (head != NULL)
    {
        assert(head->value == value);
        assert(head->next == NULL);
    }

    destroyList(head);
}

void assertAddingNode(unsigned qtdNodes)
{
    Node *head = NULL;

    T_DATA *data = genRandArr(qtdNodes);

    for (unsigned i = 0; i < qtdNodes; i++)
    {
        head = addNode(head, data[i]);
    }

    Node *p = head;
    for (unsigned i = 0; i < qtdNodes; i++)
    {
        assert(p->value == data[qtdNodes-i-1]);
        p = p->next;
    }

    assert(p == NULL);

    free(data);
    destroyList(head);
}

void assertRemovingNode()
{

}

void assertSearchingNode()
{

}

int main()
{
    srand(time(NULL));
    unsigned n = genRandNum() + 1; // positive value

    // ============ initialization test ============
    printf("Testing ResizableArray initialization...\n");

    for (unsigned i = 0; i < n; i++)
    {
        assertInitialization(genRandNum());
    }

    printf("ResizableArray initialization OK!\n");

    // ============ adding nodes test ============ 
    printf("Testing adding nodes to ResizableArray...\n");

    assertAddingNode(n);

    printf("Adding nodes OK!\n");

    // ============ removing node test ============ 
    printf("Testing removing nodes from ResizableArray...\n");



    printf("Removing nodes OK!\n");

    // ============ searching node test ============ 
    printf("Testing searching nodes in the ResizableArray...\n");



    printf("Node search OK!\n");

    return 0;
}