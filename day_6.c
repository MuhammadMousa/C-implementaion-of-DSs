#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 100
#define SUCCESS 0
#define FAIL 1
struct entry_t
{
	int last_update;  /* or double or long */
	int value;
};

struct my_structure
{
	int update;
	struct entry_t* all_values;
	struct entry_t* entries[ARRAY_SIZE];
};

/**/
int get_value(struct my_structure*, int, int*);
/**/
int set_value(struct my_structure*, int, int);
/**/
int set_all(struct my_structure*, int);
/**/
struct entry_t* entry_init(int);
/**/
struct my_structure* struct_init(struct my_structure*);

struct entry_t* node = NULL;
int main()
{
	int value;
	struct my_structure *table = struct_init(table);  
	node = (struct entry_t*)malloc(sizeof(struct entry_t));
	

	printf("%d\n",t);

	return 0;
}

/*
 * Function:  get_value
 * --------------------
 *  
 *    
 *  arr_elements: the array that contains the elements
 *  arr_size : the length of the array  
 *  sum: the sum of the pair
 *
 *  returns: SUCCESS, which means that the value is returned successfuly, or 
 *           FAIL, if the value failed to return
 */
int get_value(struct my_structure *table, int index, int *returned_value)
{
	if ((table->all_values->last_update) > (table->entries[index]->last_update)) {
		*returned_value = table->all_values->value;
		return SUCCESS;
	} else {
		*returned_value = table->entries[index]->value;
		return SUCCESS;
	}
	return FAIL;
}

/*
 * Function:  set_value
 * --------------------
 *  
 *    
 *  arr_elements: the array that contains the elements
 *  arr_size : the length of the array  
 *  sum: the sum of the pair
 *
 */
int set_value(struct my_structure *table, int index, int value)
{
	table->entries[index]->value = value;
	table->entries[index]->last_update = table->update++;
}


/*
 * Function:  set_all
 * --------------------
 *  
 *    
 *  arr_elements: the array that contains the elements
 *  arr_size : the length of the array  
 *  sum: the sum of the pair
 *
 */
int set_all(struct my_structure *table, int value)
{
	table->all_values->value = value;
	table->all_values->last_update = table->update++;
}


/*
 * Function:  struct_init
 * --------------------
 *  
 *    
 *  arr_elements: the array that contains the elements
 *  arr_size : the length of the array  
 *  sum: the sum of the pair
 *
 */
struct my_structure* struct_init(struct my_structure *table)
{
	table = (struct my_structure*) malloc(sizeof(struct my_structure));
	table->all_values = (struct entry_t*) malloc(sizeof(struct entry_t));
	int i;
	for ( i = 0 ; i< ARRAY_SIZE; i++) {
		table->entries[i] = (struct entry_t*) malloc(sizeof(struct entry_t));
	}

}

