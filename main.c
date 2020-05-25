
#include <stdio.h> 
#include <stdlib.h> 

typedef struct listNode {
	int node_value;
	struct listNode *next_node;
}listNode;




//function used to print the elements inside nodes
void listNodePrint(listNode *node_element)
{
	printf("The nodes contain the following elements:\n");
	while(node_element != NULL) {
		printf("%d\n", node_element->node_value);
		node_element = node_element->next_node;
	}
}


// Function to delete every other element from a singly linked list
void deleteNodeElement(listNode *head)
{
	// node initializiation for head + linker
	listNode *current = head;
	listNode *linker = head->next_node;

	while (linker != NULL)
	{
		current->next_node = linker->next_node; // skips every other
		current = current->next_node; // ensures updates current
		linker = current->next_node; // updates linker
	}
}

int main()
{
	// Node heap allocation using malloc
	listNode *head = (listNode*)malloc(sizeof(listNode)); 
	listNode *second = (listNode*)malloc(sizeof(listNode));
	listNode *third = (listNode*)malloc(sizeof(listNode));
	listNode *fourth = (listNode*)malloc(sizeof(listNode));
	listNode *fifth = (listNode*)malloc(sizeof(listNode));
	// node element assigmment and next node link
	head->node_value = 1; 
	head->next_node = second; 
	second->node_value =2; 
	second->next_node = third;
	third->node_value = 3; 
	third->next_node = fourth;
	fourth->node_value = 4;
	fourth->next_node = fifth;
	fifth->node_value = 5;
	fifth->next_node = NULL;

	listNodePrint(head);
	deleteNodeElement(head);
	listNodePrint(head);

	return 0;
}
