#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define FAIL 1
#define TABLE_SIZE 100



struct hash_entry
{
	char* name;
	char* phone_number;
	struct hash_entry* next;
	
};

struct hash_table
{
	struct hash_entry* linked_hash_table[TABLE_SIZE];
};


void hash_table_init(struct hash_table*);
struct hash_entry* hash_entry_inti(struct hash_entry*);

/* function to compare two strings */
int compare(char*, char*);
struct hash_entry* creat_hash_entry(char*, char*);
struct hash_table* creat_hash_table();

/* returns the hashcode(integer value) of a given name */
int get_name_hashcode(char*); 
/* insert an entry to the hash table */
void set_entry(struct hash_table*, char*, char*);
/* return a specific entry from the hash table*/
struct hash_entry* get_entry(struct hash_table*, char*);
/* search someone's phone number by his name and print the results on the screen */
void get_phone_number(struct hash_table*, char*);






int main()
{
	struct hash_table *table = (struct hash_table*)malloc(sizeof(struct hash_table));
	//table->linked_hash_table[0] = (struct hash_entry*)malloc(sizeof(struct hash_entry));
	//table->linked_hash_table[0]->name = "Mohammad";
	//table->linked_hash_table[0]->phone_number = "002-225336";
	//table->linked_hash_table[0]->next = NULL;
	//printf("%s\n",table->linked_hash_table[1]->name);
    
	//hash_table_init(table);
	//printf("%s\n",table->linked_hash_table[0]->name);
    /*
    printf("%d\n",get_name_hashcode("Mohammad"));
    printf("%d\n",get_name_hashcode("Rashad"));
    */


    set_entry(table, "Mohammad", "002-215335");
    set_entry(table, "Rashad", "002-326597");
   //printf("%s\n",get_entry(table, "Mohammad"));
    //printf("%s\n",get_entry(table, "Rami") );
    get_phone_number(table, "Mohammad");
    get_phone_number(table, "Rashad");
   


   


	 
   
	return 0;
}


/*
 * Function:  compare
 * --------------------
 *  compares two strings
 *    
 *  first_string: pointer to the first string
 *  second_string: pointer to the second string   
 *  
 *
 *  returns: 1, if the two lists or one of them is empty
 *           0, if the first string is larger than the second string
 *     	    -1, if the second string is larger than the first string 
 *          
 */
int compare(char *first_string, char *second_string)
{
	int status = 0; /*no empty input */
	if (*first_string == '\0') {
		status = 1; /* empty detected */
	} else if (*second_string == '\0') {
		status = 1; /* empty detected */
	}

	if (status == 1) {
		printf("Sorry!, you are comparing two lists at least one of them is empty\n");
		return 1;
	} else {
		while(*first_string == *second_string) {
			if (*first_string == '\0' || *second_string == '\0') { /**/
				break;
			} else {
				*first_string++;
				*second_string++;
			}
		}

		if (*first_string == '\0') {
			return -1;
		} else { /* if *second_string == '\0' */
			return 0;
		}

	}	
}


/*
 * Function:  hash_table_init
 * --------------------
 *  initilizes a hash table with an array of entries
 *    
 *  hash_table: pointer to the address of the hash table
 *
 */
void hash_table_init(struct hash_table *hash_table)
{

	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		hash_table->linked_hash_table[i] = hash_entry_inti(hash_table->linked_hash_table[i]);		
	}

}


/*
 * Function:  hash_entry_init
 * --------------------
 *  initilizes a hash entry to be inserted in the hash table
 *    
 *  hash_entry: pointer to the address of the entry
 *
 *  returns: the address of the allocated entry in the memory 
 *
 */
struct hash_entry* hash_entry_inti(struct hash_entry* hash_entry)
{
	hash_entry = (struct hash_entry*)malloc(sizeof(struct hash_entry));

	hash_entry->name = "";
	hash_entry->phone_number = "";
	hash_entry->next = NULL;

	return hash_entry;

}




/*
 * Function:  get_name_hashcode
 * --------------------
 *  calculates the index of an entry in the hashtable 
 *    
 *  name: the name which the hashcode is generated from
 *
 *  returns: an index of the hash table array
 *
 */
int get_name_hashcode(char* name)
{
	int sum_of_chars = 0;
	while(*name != '\0') {
		sum_of_chars += (int)*name; /* sum of the ascii code for each character in the name */
		*name++;

	}
	return (sum_of_chars % TABLE_SIZE);
}



/*
 * Function:  set_entry
 * --------------------
 *  adds an entry to the table
 *    
 *  table: pointer to the address of the hashtable
 *  name : the name stored in the entry  
 *  phone_number: the phone number stored in the entry
 *
 */
void set_entry(struct hash_table* table, char* name, char* phone_number)
{
	/* the hashcode is an integer represents the index in the hash table array */
	int index = get_name_hashcode(name);
	/* initilize an entry ro be inserted */
	struct hash_entry* entry = hash_entry_inti(entry); 
	entry->name = name;
	entry->phone_number = phone_number; 

	if (table->linked_hash_table[index] == NULL) {
		table->linked_hash_table[index] = entry;
	} else {
		while(table->linked_hash_table[index]->next != NULL) {
			table->linked_hash_table[index] = table->linked_hash_table[index]->next;
		}
		table->linked_hash_table[index]->next = entry;
	}
}


/*
 * Function:  get_entry
 * --------------------
 *  gets an entry from the hash table 
 *    
 *  table: pointer to the address of the hashtable
 *  name: the name stored in the entry
 *
 *  returns: a particular entry in the hashtable based on the name

 */
struct hash_entry* get_entry(struct hash_table* table, char* name)
{
	int index = get_name_hashcode(name);
	return table->linked_hash_table[index];

}



/*
 * Function:  get_phone_number
 * --------------------
 *  search someone’s phone number using his name and print the result on the screen 
 *    
 *  table: pointer to the address of the hashtable
 *  name: the name stored in the entry
 *
 */
void get_phone_number(struct hash_table* table, char* name)
{
	int index = get_name_hashcode(name);

    if (table->linked_hash_table[index] == NULL) {
    	printf("Sorry!,No number has been found for %s \n", name);	
    } else {
    	while(table->linked_hash_table[index] != NULL) {
    		printf("%s :%s\n",name, table->linked_hash_table[index]->phone_number);
    		table->linked_hash_table[index] = table->linked_hash_table[index]->next;
    	}
    }
}






