
#include <stdio.h> 
#include <stdlib.h> 


/*
Question 1: Write a function that removes every other node (starting with the second node) from a list
*/

typedef struct listNode {
	int node_value;
	struct listNode *next_node;
}listNode;

//function used to print the elements inside nodes
void listNodePrint(listNode* node_element)
{
	printf("The nodes contain the following elements:\n");
	while (node_element != NULL) {
		printf("%d\n", node_element->node_value);
		node_element = node_element->next_node;
	}
	printf("\n");
}

// Function to delete every other element from a singly linked list
void deleteNodeElement(listNode *head)
{
	// node initializiation for head + linker
	listNode *current = head;
	listNode *linker = head->next_node;

	while (linker != NULL) // 
	{
		current->next_node = linker->next_node; // skips every other
		current = current->next_node; // ensures updates current
		linker = current->next_node; // updates linker
	}
	listNodePrint(head);
}

/*
Question 2: Implement a stack (stack structure, push function, pop function) using an array.
*/

#define SIZE 5 // stack size defintion for array based stack
int stack[SIZE]; // stack size 5
int top = -1; // stack not yet initialized so make number negative for now

// function to print popped elements from the stack
//void printArrayStack()
//{
//	printf("ok this prints");
//	int i;
//	for (i = 0; i <= 3; i++)
//	{
//		printf("%d\n", stack[i]);
//	}
//}
//function to push elements to the stack
void pushElement(int element_value)
{
	if (top < 0) /*if top is neg, then add element value to first 
					 array position (index) and make top 0*/
		{
			stack[0] = element_value;
			top = 0;
			printf("\nThe element value of %d has been pushed to the index of the array stack.\n", element_value);
		}
		else /* if there is an element in index, move over top + n*/
		{
			stack[top + 1] = element_value;
			top++ ;
			printf("\nThe element value of %d has been pushed to the array stack.\n", element_value);
		}
	
}

//function to pop elements from the stack
void popElement()
{
	int x = stack[top];
	printf("\nThe element with the value of %d has been popped from the Array Stack\n", stack[top]);
	top = top - 1;
	
	
}

/*
Question 3: Implement a stack (stack structure, push function, pop function) using a list.
*/

typedef struct nodeStack
{
	int value; // node->data (node.data)
	struct nodeStack* next; // node->next (node.next)
}nodeStack;


nodeStack* top_node = NULL; // pointer to the top of the stack



void listStackPush(int val)
{

	nodeStack* temp_node; // a new temp node 
	temp_node = malloc(sizeof(nodeStack)); // runtime heap allocation for new node
	temp_node->value = val; // whatever the value is its stored in tmp->data
	temp_node->next = top_node; // the next of temp is top (tmp created to the left of top)
	top_node = temp_node; // top and temp are now the same
}


void listStackPop()
{
	int temp_node_data; // new variable to hold temp->data portion
	nodeStack* temp_node; // new temp node
	temp_node = top_node; //the new temp node now points to the top of the stack
	temp_node_data = temp_node->value; // assign the value of n to tem->data portion
	top_node = top_node->next; //the top node is now the node next to top (top->next)
	free(temp_node); //release the temp node

}


int main()
{
/*
Question 1 main:
*/
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
	listNodePrint(head); // prints nodes before delete
	deleteNodeElement(head); // call to the delete Node function
/*
Question 2 main:
*/
	pushElement(4);
	pushElement(6);
	popElement();
	pushElement(8);
	pushElement(7);
	pushElement(10);
	popElement();
	//printArrayStack();

/*
Question 3 main:
*/
	listStackPush(1);
	listStackPush(29);
	listStackPush(3);
	listStackPush(100);
	printf("\n");
	printf("The element at the top of the stack is: %d\n", top_node->value);
	listStackPop();
	printf("The element at the top of the stack is: %d\n", top_node->value);
	return 0;;
}
