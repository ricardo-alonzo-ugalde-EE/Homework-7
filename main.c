
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
		printf("%d\n", node_element->node_value); //prints the value at node element node_element.nodevalue
		node_element = node_element->next_node; // node element is now the next to element nodee_element.nextnode
	}
	printf("\n");
}

// Function to delete every other element from a singly linked list
void deleteNodeElement(listNode *head)
{
	// node initializiation for head + linker
	listNode *current = head;
	listNode *linker = head->next_node; // links node next to head head.next

	while (linker != NULL) // stops if there are no other nodes to link to
	{
		current->next_node = linker->next_node; // both point to next node
		current = current->next_node; // current is now next node
		linker = current->next_node; // updates the link to the new next node
	}
	listNodePrint(head);
}

/*
Question 2: Implement a stack (stack structure, push function, pop function) using an array.
*/

 // stack size defintion for array based stack
int stack[5]; // stack size 5
int top = -1; // stack not yet initialized so common technique to use negative

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
	if (top < 0) /*if top is negative (stack doesnt exist), then add element value to first 
					 array position (index) and make top 0*/
		{
			stack[0] = element_value;
			top = 0;
			printf("\nThe element value of %d has been pushed to the index of the array stack.\n", element_value);
		}
		else // if there is an element in index (stack exists already), start from top + n
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
	int value; // node->value (node.value)
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
/*
Question 4:
*/

// a new list node structure
typedef struct listNode1
{
	int value;
	struct listNode1* next;
}listNode1;


// a new queue line structure
typedef struct queue
{
	int q_line_count; // variable to keep track of count
	listNode1* front; // a node for the front of the q line
	listNode1* rear;  // a node for the rear of the q line
}queue;




// function for enqueue
void enqueueLine(queue* q_line, int data_value)
{
	listNode1* temp_node; // adds a new temporary node
	temp_node = malloc(sizeof(listNode1)); // alocates heap space for new temp node
	temp_node->value = data_value; // assign a value to the data portion of temp temo->data  is a value (temp.data is a value)
	temp_node->next = NULL; // point the next node of temp NULL temp->next is NULL (temp.next is NULL)

	// executes if the q line is not empty (queue line exists )
	if (q_line->rear != NULL)
	{
		q_line->rear->next = temp_node; // if the q line empty then point to both front and rear (right now rear->next is front)
		q_line->rear = temp_node; //  q rear is also empty
	}
	else
	{
		q_line->front = q_line->rear = temp_node;
	}
	q_line->q_line_count++; // increment the q line count by 1
}

void dequeueLine(queue* q_line)
{
	listNode1* temp_node; // temp node
	int temp_node_data = q_line->front->value; // temp variable to hold temp->data value
	temp_node = q_line->front; // temp nod holds q line->front (qline.front)
	q_line->front = q_line->front->next; // move qlist-> front to point to qlist ->next (element removed from qline)
	q_line->q_line_count--; // decrease teh count of the qline by 1
	free(temp_node); // releseas temp_node

}


int main()
{
/*
Question 1 main:
*/	printf("**********QUESTION 1 ***************\n");
	// Node heap initialization and allocation using malloc
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
	printf("\n**********QUESTION 2 ***************");
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
	printf("\n**********QUESTION 3 ***************");
	listStackPush(1);
	listStackPush(29);
	listStackPush(3);
	listStackPush(100);
	printf("\n");
	printf("The element at the top of the stack is: %d\n", top_node->value);
	listStackPop();
	printf("The element at the top of the stack is: %d\n", top_node->value);


/*
Question 4 main:
*/	printf("\n**********QUESTION 4 ***************\n");
	queue* q_line; // new queue 
	q_line = malloc(sizeof(queue)); // allocate mem to q_line
	q_line->q_line_count = 0; // the current q line count is zero
	q_line->front = NULL; // the front of the q line is zero
	q_line->rear = NULL; // the rear of the q line is zero
	enqueueLine(q_line, 33);
	enqueueLine(q_line, 23);
	printf("The value at the front of the queue line before dequeuing is: %d\n", q_line->front->value);
	enqueueLine(q_line, 36);
	dequeueLine(q_line);
	printf("The value at the front of the queue line after dequeuing is: %d\n", q_line->front->value);

	return 0;
}
