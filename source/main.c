// main.c 
// folder home
#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
	// Initialize front and rear 
	int rear, front;
	// Circular Queue 
	int size;
	int* arr;
}Queue;
 
void create( int s, Queue* q)
{
	q->front = -1;
	q->rear = -1;
	q->size = s;
	if(((q->arr =(int*)malloc(s * sizeof(int)))) == NULL)
	{
		printf("Allocation error.");
		exit(0);
	}
}
 
/* Function to create Circular queue */
void enQueue(int value, Queue* q)
{
	if ((q->front == 0 && q->rear == q->size - 1) ||
		(q->rear == (q->front - 1) % (q->size - 1)))
	{
		printf("\nQueue is Full");
		return;
	}
 
	else if (q->front == -1) /* Insert First Element */
	{
		q->front = 0;
		q->rear = 0;
		*(q->arr + q->rear) = value;
	}
 
	else if (q->rear == q->size - 1 && q->front != 0)
	{
		q->rear = 0;
		*(q->arr + q->rear) = value;
	}
 
	else
	{
		q->rear++;
		*(q->arr + q->rear) = value;
	}
}
 
// Function to delete element from Circular Queue 
int deQueue(Queue* q)
{
	if (q->front == -1)
	{
		printf("\nQueue is Empty");
		return NULL;
	}
 
	int data = *(q->arr + q->front);
	*(q->arr + q->front) = -1;
	if (q->front == q->rear)
	{
		q->front = -1;
		q->rear = -1;
	}
	else if (q->front == q->size - 1)
		q->front = 0;
	else
		q->front++;
 
	return data;
}
 
// Function displaying the elements 
// of Circular Queue 
void displayQueue(Queue* q)
{
	if (q->front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (q->rear >= q->front)
	{
		for (int i = q->front; i <= q->rear; i++)
			printf("%d ", *(q->arr + i));
	}
	else
	{
		for (int i = q->front; i < q->size; i++)
			printf("%d ", *(q->arr + i));
 
		for (int i = 0; i <= q->rear; i++)
			printf("%d ", *(q->arr + i));
	}
}

void delete (Queue *q)
{
	free(q->arr);
}
 
/* Driver of the program */
int main()
{
	Queue first_q;
	Queue second_q;
	//create
	create(10, &first_q);
	create(10, &second_q);
	// Inserting elements in Circular Queue 
	enQueue(14, &first_q);
	enQueue(22, &first_q);
	enQueue(13, &first_q);
	enQueue(-6, &first_q);

	enQueue(1, &second_q);
	enQueue(2, &second_q);
	enQueue(3, &second_q);
	enQueue(-4, &second_q);
 
	// Display elements present in Circular Queue 
	displayQueue(&first_q);
	displayQueue(&second_q);
 
	// Deleting elements from Circular Queue 
	printf("\nDeleted value = %d", deQueue(&first_q));
	printf("\nDeleted value = %d", deQueue(&first_q));
	printf("\nDeleted value = %d", deQueue(&second_q));
	printf("\nDeleted value = %d", deQueue(&second_q));

    // Display elements present in Circular Queue 
	displayQueue(&first_q);
	displayQueue(&second_q);

	// Inserting elements in Circular Queue 
	enQueue(9, &first_q);
	enQueue(20, &first_q);
	enQueue(5, &first_q);

	enQueue(11, &second_q);
	enQueue(12, &second_q);
	enQueue(13, &second_q);
 
	// Display elements present in Circular Queue 
	displayQueue(&first_q);
	displayQueue(&second_q);

	// test for full queue
	enQueue(14, &second_q);
	enQueue(15, &second_q);
	enQueue(16, &second_q);
	enQueue(17, &second_q);
	enQueue(18, &second_q);
	enQueue(19, &second_q);
	return 0;
}