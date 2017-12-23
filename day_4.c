#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 0
#define FAIL 1

int fibonacci_one(int);
int fibonacci_two(int);
int find_pairs_sum(int*,int,int); 
int is_valid_ip(char*); 
int is_valid_digit(char*);

int main()
{
	/** 
	Test find_pairs_sum() function 
	**/

    /*
	int size, sum;
	int i;
	printf("Please Enter the size of the array: \n");
	scanf("%d", &size);
	int arr_elements[size];
	printf("Please Insert %d integers: \n",size );
	for (i = 0; i < size; ++i)
	{
		scanf("%d",&arr_elements[i]);
	}
	printf("Please Enter the sum: \n");
	scanf("%d", &sum);
	find_pairs_sum(arr_elements, size, sum);
	*/


	/** 
	Testing is_valid_ip() function 
	**/

    /*
	char ip[] = "192.168.256.1"; // invalid ip
	char ip1[] = "192.168.1.1"; // valid ip
	char ip2[] = "A.B.C.D"; // invalid ip
	char ip3[] = "192.168.12.2D"; // invalid ip
	if(is_valid_ip(ip1)) {
		printf("Valid IP\n");
	} else {
		printf("Invalid IP\n");
	}
   */

	/** 
	Testing fibonacci_one() function 
	**/

	/*
	printf("%d\n",fibonacci_one(12) );
	*/

	/** Testing fibonacci_two() function **/
	/*
     printf("%d\n",fibonacci_two(12) );
    */



	
	
	
	return 0;
}

/*
 * Function:  find_pairs_sum
 * --------------------
 *  finds all the unique pairs of elements (a,b), whose sum is equal to a given sum.
 *    
 *  arr_elements: the array that contains the elements
 *  arr_size : the length of the array  
 *  sum: the sum of the pair
 *
 *  returns: SUCCESS, which means that the pair has been found, or 
 *           FAIL, if the pair does not exist in the array
 */
int find_pairs_sum(int* arr_elements, int arr_size, int sum)
{
	int i, j;
	int found = 0; /* assume no pair sums up to sum*/
	for (i = 0; i < arr_size; i++) {
    		for (j = i; j < arr_size; j++) {
      				if (arr_elements[i] + arr_elements[j] == sum) {
      					found = 1;
        				printf("[%d, %d]\n",arr_elements[i], arr_elements[j] );;
      				}
    		}
  	}
  	if (found == 1) {
  		return SUCCESS;
  	} else {
  		return FAIL;
  	}

}

/*
 * Function:  is_valid_ip 
 * --------------------
 *  parses and validates an ip address
 *    
 *  ip: the ip address to be parsed and validated passed as a string
 *
 *  returns: true(1), which indicates that the ip is valid, or 
 *           false(0) if the ip is not valid
 */

int is_valid_ip(char* ip)
{
	/* after strtok, assign the tokens to it*/
    char *ip_tokens; 
 
    if (ip == NULL)
        return 0;
 
    /* delimeter: (.) */
    ip_tokens = strtok(ip, "."); 
 
    if (ip_tokens == NULL)
        return 0;
 
    int ip_part, num_of_dots;
    while (ip_tokens) {
        /* after parsing string, it must contain only digits */
        if (!is_valid_digit(ip_tokens))        
            return 0;

        /* convert each poctet(part) of the ip to integer */
        ip_part = atoi(ip_tokens);        

        if (ip_part >= 0 && ip_part <= 255) {
            /* parse remaining string */
            ip_tokens = strtok(NULL, "."); 
           		 if (ip_tokens != NULL) {
                		++num_of_dots;
            		}
         		
    			} else {
            		return 0;
        		}
    }
 
    /* valid IP string must contain 3 dots */
    if (num_of_dots != 3)
        return 0;
    return 1;

}

/*
 * Function:  is_valid_digit 
 * --------------------
 *  checks if a string contains only digits
 *    
 *  ip_as_str: the ip (as string) to be validated
 *
 *  returns: true(1), which indicates that the ip string contains only digits, or 
 *           false(0) if the ip string contains other than digits
 */

int is_valid_digit(char* ip_as_str)
{
	while(*ip_as_str) {
		if (*ip_as_str >= '0' && *ip_as_str <= '9') {
			ip_as_str++;
		} else {
			return 0;
		}
	}
	return 1;

}

/*
 * Function:  fibonacci_one
 * --------------------
 *  finds the Fibonacci series number that corresponds to a given index in the series
 *    
 *  index: the series index.
 *
 *  returns: the Fibonacci series number.
 */
int fibonacci_one(int index)
{
	  int series[index+1];

      int i;
 
 		 /* 0th and 1st number of the series are 0 and 1*/
 		 series[0] = 0;
 		 series[1] = 1;
 
 	 for (i = 2; i <= index; i++)
 		 {
  		    /* Add the previous 2 numbers in the series
  		      and store it */
    		  series[i] = series[i-1] + series[i-2];
 		 }
 
  return series[index];


}


/*
 * Function:  fibonacci_one
 * --------------------
 *  finds the Fibonacci series number that corresponds to a given index in the series
 *    
 *  index: the series index.
 *
 *  returns: the Fibonacci series number.
 */
int fibonacci_two(int index)
{
	int first_index = 0;
	int second_index = 1;

	if (index == 0) {
		return first_index;
	}
	int sum, /* sum two previous elements */
	    i;
	for ( i = 2; i <= index; i++) {
		sum = first_index + second_index;
		first_index = second_index;
		second_index = sum;
	}

	return second_index;


}



/*
 store the fib. series in an array and return the element i the specified index
*/
/*
int fibonacci_one(int* series,int length,int index)
{
	  int temp_series[length];
	  series = temp_series; 

	  series[length+1];
      int i;
 
 		 // 0th and 1st number of the series are 0 and 1
 		 series[0] = 0;
 		 series[1] = 1;
 
 	 for (i = 2; i <= length; i++)
 		 {
  		    // Add the previous 2 numbers in the series
  		   //   and store it 
    		  series[i] = series[i-1] + series[i-2];
 		 }
 
  return series[index];


}
*/
