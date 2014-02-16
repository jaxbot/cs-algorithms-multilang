#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} node;

node *createNode(int data)
{
	node *nodeptr = malloc(sizeof(node));

	nodeptr->data = data;
	nodeptr->next = NULL;

	return nodeptr;
}

// O(n)
void appendNode(node *head, int data)
{
	if (head->next != NULL)
		appendNode(head->next, data);
	else
		head->next = createNode(data);
}

// O(n)
void printNodes(node *head)
{
	if (head == NULL) return;

	printf("%d\n", head->data);

	printNodes(head->next);
}

int main(void) 
{
	int i;
	node *list = createNode(0);

	for (i = 0; i < 20; i++)
		appendNode(list, i);

	printNodes(list);

	return 0;
}

