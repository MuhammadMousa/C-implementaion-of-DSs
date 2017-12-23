#include <stdio.h>
#define Q_SIZE 100

int enqueue(int);
int dequeue(int*);
int is_full();
int is_empty();


int gFront = -1; /* the end from the data will be removed(degQueued) */
int gRear = -1;  /* the end from the data will be inserted(engQueued) */
int gQueue[Q_SIZE]; /* a Queue with a predefined size */


int main()
{

	/* Testing ... */

	    int value;   /* the address of returned value */
      int status;  /* successful or not */
      int data;    /* to be inserted */
      enqueue(10);
      enqueue(200);
      dequeue(&value);
      printf("%d\n",value);



	return 0;
}

int is_empty()
{
	if(gFront == -1 && gRear == -1) {
		return 1;
	} else {
		return 0;
	}
}

int is_full()
{
  if((gRear + 1) % Q_SIZE == gFront) {
  	return 1;
  } else {
  	return 0;
  }
}

int enqueue(int data)
{
	if (is_full()) {
		printf("Sorry, Queue is full\n");
		return 0;
	} else if(is_empty()) {
		gFront = gRear = 0;
		gQueue[gRear] = data;
		return 1;
	} else {
		gRear = (gRear + 1) % Q_SIZE;
		gQueue[gRear] = data;
		return 1;
	}
}


int dequeue(int* data) /*  *data: the value to be returned  */
{
    if (is_empty()) {
    	printf("Sorry, Queue is Empty\n");
    	return 0;
    } else if(gFront == gRear) { /* if the gQueue contains one element only */
    	*data = gQueue[gFront];
    	gFront = gRear = -1;
    	return 1;
    } else {
        *data = gQueue[gFront];
        gFront = (gFront+1) % Q_SIZE ;
        return 1;
    }
}


