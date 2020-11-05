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
	//maloc
	int array[s];
	if(((q->arr =(int*)malloc(sizeof(array)))) == NULL)
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
	Queue q;
	Queue* pointer = &q;

	Queue second_q;
	Queue* second_pointer = &second_q;
	//create
	create(10, pointer);
	create(10, second_pointer);
	// Inserting elements in Circular Queue 
	enQueue(14, pointer);
	enQueue(22, pointer);
	enQueue(13, pointer);
	enQueue(-6, pointer);

	enQueue(1, second_pointer);
	enQueue(2, second_pointer);
	enQueue(3, second_pointer);
	enQueue(-4, second_pointer);
 
	// Display elements present in Circular Queue 
	displayQueue(pointer);
	displayQueue(second_pointer);
 
	// Deleting elements from Circular Queue 
	printf("\nDeleted value = %d", deQueue(pointer));
	printf("\nDeleted value = %d", deQueue(pointer));
	printf("\nDeleted value = %d", deQueue(second_pointer));
	printf("\nDeleted value = %d", deQueue(second_pointer));

    // Display elements present in Circular Queue 
	displayQueue(pointer);
	displayQueue(second_pointer);

	// Inserting elements in Circular Queue 
	enQueue(9, pointer);
	enQueue(20, pointer);
	enQueue(5, pointer);

	enQueue(11, second_pointer);
	enQueue(12, second_pointer);
	enQueue(13, second_pointer);
 
	// Display elements present in Circular Queue 
	displayQueue(pointer);
	displayQueue(second_pointer);

	// test for full queue
	enQueue(14, second_pointer);
	enQueue(15, second_pointer);
	enQueue(16, second_pointer);
	enQueue(17, second_pointer);
	enQueue(18, second_pointer);
	enQueue(19, second_pointer);
	return 0;
}