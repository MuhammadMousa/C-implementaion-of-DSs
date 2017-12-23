#include <stdio.h>
#include <stdlib.h> 
#define SUCCESS 0
#define FAIL 1

struct node_t
{
	int data;
	struct node_t* next;
 	
};

struct linked_list
{
	struct node_t *head;
	
};

int insert(struct node_t**, struct node_t*);
int insert_after(struct node_t**,struct node_t*, int);
int delete(struct node_t**,struct node_t*);
int is_empty(struct node_t**);
int insert_to_last(struct node_t**,struct node_t*);
struct node_t* creat_node_t(int); /* create the node_t to be inserted */
void print_list(struct node_t**);
struct linked_list* create_list();


int has_intersection(struct node_t**, struct node_t**);
int is_palindrome(struct node_t**);
int find_second_largest(struct node_t**, int*);
int find_k_largest(struct node_t**, int, int*);

/* utility functions */
int copy_list(struct node_t**, struct node_t**);
int is_euqal(struct node_t**, struct node_t**);
int num_of_nodes(struct node_t**);
void sort_descending(struct node_t**);
struct node_t* fill_array(struct node_t**); /* get the head of the list and return array of the nodes in that list */

void bubbleSort(struct node_t**);




int main()
{
	
    struct linked_list *list_1 = create_list();
    struct linked_list *list_2 = create_list();
    struct linked_list *list_3 = create_list();
    struct node_t *n1, *n2, *n3, *n4, *n5;
    struct node_t *n6, *n7, *n8, *n9, *n10;
    
    

    n1 = creat_node_t(25);
    n2 = creat_node_t(77);
    n3 = creat_node_t(36);
    n4 = creat_node_t(102);
    n5 = creat_node_t(540);

    n6 = creat_node_t(25);
    n7 = creat_node_t(77);
    n8 = creat_node_t(36);
    n9 = creat_node_t(102);
    n10 = creat_node_t(540);

   insert(&list_1->head,n1);
   insert(&list_1->head,n2); 
   insert(&list_1->head,n3); 
   insert(&list_1->head,n4); 
   insert(&list_1->head,n5);

   insert(&list_2->head,n6);
   insert(&list_2->head,n7); 
   insert(&list_2->head,n8); 
   insert(&list_2->head,n9); 
   insert(&list_2->head,n10);

   printf("%x %x\n",n1,n1->next);
   


	return 0;
}


/*
 *is_empty() check if the list is empty or not 
 *returns 1 if it is empty and 0 otherwise.
*/
int is_empty(struct node_t **list_head)
{
	if (*list_head == NULL) {
		return 1;
	} else {
		return 0;
	}
}



/*
 *the function insert inserts a node_t on top of the list(at first).
 *return success code(0) if the node_t was inserted successfully , otherwise fail(1).
*/
int insert(struct node_t** list_head, struct node_t* new_node)
{

	if (is_empty(list_head)) {
		*list_head= new_node;
		return SUCCESS;
	} else {
		struct node_t* temp = new_node;
		temp->next = *list_head;
		*list_head = temp;
		return SUCCESS;
	}

}



int insert_after(struct node_t **list_head, struct node_t* new_node, int node_key)
{
	struct node_t* temp = *list_head;
	struct node_t* temp2 = NULL;
	if (is_empty(list_head)) {
		printf("Sorry, List is Empty!\n");
		return FAIL;
	} else if (temp->next == NULL) { /* the list only contains one element */
		if (temp->data == node_key) {
    		temp->next = new_node;
    		new_node->next = NULL;
    		return SUCCESS;	
    	} 
	} else {
    while(temp != NULL) {
    	temp2 = temp->next;
    	if (temp->data == node_key) {
    		temp->next = new_node;
    		new_node->next = temp2;	
    		return SUCCESS;
    	} 
    	temp = temp->next;
    	}
 	}

}



int delete(struct node_t **list_head, struct node_t* target_node_t)
{
	struct node_t* temp;
	struct node_t* temp2;

	temp = *list_head;
	if (is_empty(list_head)) {   /* the list is empty*/
		printf("Sorry, list is empty!\n");
		return FAIL;
	} else if (temp->data == target_node_t->data) {
			temp = temp->next;
		    return SUCCESS;	
	} else {  /*otherwise...*/
		while(temp != NULL) {
			if (temp->next->data == target_node_t->data) {
				temp2 = temp->next;
				temp->next = temp2->next;
				return SUCCESS;	
			}
			temp = temp->next;
		}
		printf("Sorry, node_t to be Deleted is not found!\n");
		return FAIL;
	}

}




/*
 *the function insert_to_last takes the new node_t to be inserted and 
 *and return a value (0 or 1 ), to check if the insertion was successful or not.(0: success, 1: fail).
*/
int insert_to_last(struct node_t **list_head, struct node_t* new_node)
{
	struct node_t* temp ;
	temp = *list_head;
	if (temp == NULL) {
		*list_head = new_node;
		return SUCCESS;
	} else if (temp->next == NULL) {
		temp->next = new_node;
		return SUCCESS;
	} else {
		while(temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = new_node;
	return SUCCESS;

	}
	
}



/*
 *the function reverse take a list as a parameter by passing the head of it,
 *and return a fail code(1) if the reverse can't be done, or success code (0)
 *if the list was reversed successfully.
 *it takes the head of the list as parameter.
*/
int reverse(struct node_t **list_head)
{
	struct node_t* temp = *list_head;
	struct node_t *current, /* points to current node_t */
	            *previous, /* points to previous node_t */
	            *next;     /* points to next node_t */

	if (temp == NULL) {
		return FAIL;
	} else if (temp->next == NULL) {
		return SUCCESS;
	} else {
		current = temp;
	    previous = NULL;
	    while(current != NULL) {
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		*list_head = previous;
		return SUCCESS;
	}	
}




/*
  *the function has_loop return 1 if the list has loop or 0 otherwise.
  *it takes the head of the list as a parameter. 
*/
int has_loop(struct node_t **list_head)
{

	struct node_t *once,  /* move one node_t at a time */
	              *twice; /* move two node_ts at a time */
	once = *list_head;
	twice = *list_head;
	int found = 0; /* assume that the list has no loop */

    if (once == NULL || once->next == NULL) { /* if there is no elements in the list or it contains only one element */
    	found = 0;
    } else {
    	while(once && twice) {   /* while the two pointers not equal NULL; keep moving...*/
    		once = once->next;
    		twice = twice->next->next;
    		if (once == twice) { /* if they meet (pointing to the same node_t) then a loop has been detected */
    			found = 1;
    		}

    	}
    }
    return found;	
}





struct linked_list* create_list()
{
	struct linked_list* l_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	l_list->head = NULL;
	return l_list;
}





/*
 *the function creat_node_t allocate memory for the new node_t to be inserted.
 *it takes int data as a parameter.(input)
 *it returns a pointer(reference) to the allocated node_t in the memory.(output)
*/
struct node_t* creat_node_t(int data)
{
	struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
	new_node->data = data;
	new_node->next = NULL;
	return new_node; /* return the address of the allocated node_t */

}



/* 
  print_list to show the elements in the list, it takes the head of the list as an input 
  and print the list .
*/
void print_list(struct node_t **list_head)
{
    struct node_t* temp = *list_head;
	while(temp != NULL) {
		printf(" %d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL");
	printf("\n");

}



/*
* this function takes the hede of the list to be checked as a parameter and return whether it is a palindrome or not
* it returns true (1) if it is palindrome , otherwise it returns false(0).
*/
int is_palindrome(struct node_t **list)
{

    struct node_t *original_list = *list;
	struct linked_list *to_be_reversed_list = create_list();
    
    copy_list(&original_list, &to_be_reversed_list->head);
	reverse(&to_be_reversed_list->head);
    return is_euqal(&original_list, &to_be_reversed_list->head);

}


/*
 * this function takes the heads of two lists as paremeters and return whether an intersection has been detected or not.
 * it returns true (1) if there is an intersection , otherwise it returns false(0).
*/
int has_intersection(struct node_t** list_1, struct node_t** list_2)
{
	struct node_t *head1 = *list_1;
	struct node_t *head2 = *list_2;
	while(head1->next != NULL) {
		head1 = head1->next;
	}

	while(head2->next != NULL) {
		head2 = head2->next;
	}

	if (head1 == head2) {
		return 1;
	} else {
		return 0;
	}

}


/**
 * this is the deinition of find_second_largest function which takes the head of a list and returns the second largest 
 * number in the list
**/
int find_second_largest(struct node_t** list_head, /* head of the list */
                              int *largest_second) /* points to the returned value */
{

	/**
	 * sort the list in descending order
     * after sorting; the second largest element is the second element in the list
	**/
	struct node_t *head = *list_head;
	bubbleSort(&head);
	int i;
	for ( i = 0; i < 1; ++i)
	{
		head = head->next;
	}
	*largest_second = head->data;
}


/*
* a function for counting number of nodes in a list
*/
int num_of_nodes(struct node_t **list_head)
{
	int count = 0;
	struct node_t* temp = *list_head;

	while(temp != NULL) {
		count++;
		temp = temp->next;
	} 
	return count;
}

/*
 * a function that checks if two lists are equal or not
*/
int is_euqal(struct node_t **list_1_head, struct node_t **list_2_head)
{
	struct node_t *first_list_ptr = *list_1_head;
	struct node_t *second_list_ptr = *list_2_head;

	while(first_list_ptr && second_list_ptr) {
		if (first_list_ptr->data == second_list_ptr->data) {
			first_list_ptr = first_list_ptr->next;
			second_list_ptr = second_list_ptr->next;
		} else {
			return 0;
		}

	}
    /* it is empty or we reached here after the while loop finished */
	if (first_list_ptr == NULL && second_list_ptr == NULL)  {
		return 1;
	}
    /* if at the end one is null and one is not then they are not equal , and we will reach here */
	return 0;

}

/*
 * this is a utility function to copy a linked list to another
*/
int copy_list(struct node_t **source, struct node_t **destination)
{
	struct node_t *source_list = *source;
	struct node_t *destination_list = *destination;
	int count = num_of_nodes(&source_list);
    struct node_t* nodes_copy[count]; /* this array contains a copy of the source list */
    if (source_list == NULL) {
    	printf("Sorry!, the source list is empty!\n");
    	return FAIL;
    }
    int i ;
    for (i = 0; i < count; i++)  /* fill the array with the nodes from the source list */
    {
    	nodes_copy[i] = creat_node_t(source_list->data);
    	source_list = source_list->next;
    }
    int j;
    for (j = 0; j < count; j++) /* insert the nodes from the array to the destination list */
    {
    	insert_to_last(&destination_list, nodes_copy[j]);
 
    }
    *destination = nodes_copy[0];
    return SUCCESS;


}


/* Bubble sort the given linked lsit */
void bubbleSort(struct node_t **list_head)
{
    struct node_t *temp_head = *list_head;
    struct node_t *temp2_head = *list_head;

	int count = num_of_nodes(&temp_head); 
	struct node_t* nodes_copy[count]; 
	struct node_t* temp_node;

	int k;
    for (k = 0; k < count; k++)  
    {
    	nodes_copy[k] = creat_node_t(temp_head->data);
    	temp_head = temp_head->next;
    }

    int iter = count - 1;
    int temp; /* for swapping */
    int sorted, i;

    /* do the swap */
    do {
		sorted = 0;
		i = 0;
			for(; i < iter; ++i) {
				if (nodes_copy[i + 1]->data > nodes_copy[i]->data) {
					sorted = 1;
					temp = nodes_copy[i+1]->data;
					nodes_copy[i+1]->data = nodes_copy[i]->data;
					nodes_copy[i]->data = temp;
				}
			}
			--iter;
	} while (sorted);



    int j;
    for (j = 0; j < count; j++) /* insert the nodes from the array to the destination list */
    {
    	insert_to_last(&temp2_head, nodes_copy[j]);
 
    }
    *list_head = nodes_copy[0];


}
 

int find_k_largest(struct node_t **list_head, int k, int* k_largest)
{

	/**
	 * sort the list in descending order
     * after sorting; the k largest element is the k element in the list
	**/
	struct node_t *head = *list_head;
	bubbleSort(&head);
	int i;
	for ( i = 0; i < (k-1); ++i)
	{
		head = head->next;
	}
	*k_largest = head->data;
	printf("%d\n",head->data );



}
