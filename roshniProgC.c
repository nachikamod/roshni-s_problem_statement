/* C Program to implement a queue using two stacks */
#include <stdio.h> 
#include <stdlib.h> 

int planted = 0;

/* structure of a stack node */
struct sNode { 
	int data; 
	struct sNode* next; 
}; 

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data); 

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref); 

/* structure of queue having two stacks */
struct queue { 
	struct sNode* stack1; 
	struct sNode* stack2; 
}; 

/* Function to enqueue an item to queue */
void enQueue(struct queue* q, int x) 
{ 
    planted++;
	push(&q->stack1, x); 
} 

/* Function to deQueue an item from queue */
int deQueue(struct queue* q) 
{ 
	int x; 

	/* If both stacks are empty then error */
	if (q->stack1 == NULL && q->stack2 == NULL) { 
		printf("Q is empty"); 
		getchar(); 
		exit(0); 
	} 

	/* Move elements from stack1 to stack 2 only if 
	stack2 is empty */
	if (q->stack2 == NULL) { 
		while (q->stack1 != NULL) { 
			x = pop(&q->stack1); 
			push(&q->stack2, x); 
		} 
	} 

    planted--;
	x = pop(&q->stack2); 
	return x; 
} 

/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data) 
{ 
	/* allocate node */
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode)); 
	if (new_node == NULL) { 
		printf("Stack overflow \n"); 
		getchar(); 
		exit(0); 
	} 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*top_ref); 

	/* move the head to point to the new node */
	(*top_ref) = new_node; 
} 

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref) 
{ 
	int res; 
	struct sNode* top; 

	/*If stack is empty then error */
	if (*top_ref == NULL) { 
		printf("Stack underflow \n"); 
		getchar(); 
		exit(0); 
	} 
	else { 
		top = *top_ref; 
		res = top->data; 
		*top_ref = top->next; 
		free(top); 
		return res; 
	} 
} 

int main() 
{ 
	struct queue* q = (struct queue*)malloc(sizeof(struct queue)); 
	q->stack1 = NULL; 
	q->stack2 = NULL; 

    int k, m, v = 2;

    printf("k : ");scanf("%d",&k);
    printf("m : ");scanf("%d",&m);

    for (int toBeCutted = 0; toBeCutted < k; toBeCutted++)
    {

        if (planted != 0)
        {
            v = deQueue(q);
        }
        for (int toBePlanted = 0; toBePlanted < (v+1)%m; toBePlanted++)
        {
            enQueue(q, toBePlanted);
        }
        
    }
    

    printf("%d\n", planted); 

	return 0; 
} 
