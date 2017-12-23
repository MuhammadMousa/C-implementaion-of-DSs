#include <stdio.h>
#define STACK_SIZE 100

int push(int);
int pop(int*);
int is_full();
int is_empty();
void test_print();

int gTop = -1;
int gStack[STACK_SIZE];

typedef struct Stack {
  int *array;

}Stack;

int main()
{

    int value;
    int status;
    int data;
      Stack s;
      int i;
      int n;
      i = 2;
      printf("%d  %d  %d",i,i,++i);



	return 0;
}


int is_empty()
{
	if(gTop == -1) {
		return 1;
	} else {
        return 0;
	}

}


int is_full()
{
	if(gTop == (STACK_SIZE - 1)) {
		return 1;
	} else {
        return 0;
	}

}

int push(int data)
{
	if(is_full()) {
		printf("Stack Overflow\n");
		return 0;
	} else {
		gTop++;
		gStack[gTop] = data;
		return 1;
	}

}


int pop(int* data)
{
	if(is_empty()) {
		printf("Sorry, the Stack is empty\n");
		return 0;
	} else {
		*data = gStack[gTop];
		gTop--;
		return 1;
	}

}

void test_print()
{
	printf("Stack Content is: ");
	int i ;
	for (i = 0; i <= gTop; ++i){
	    printf("%d >",gStack[i]);

	}
	printf("\n");

}


