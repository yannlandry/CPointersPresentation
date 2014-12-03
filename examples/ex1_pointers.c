/*****************************
 * EXAMPLE 1
 *
 * Basic pointer declaration,
 * operation and deletion.
 *****************************/


#include "stdio.h"
#include "stdlib.h"


int main() {
	
	// Just a first line
	printf("Hello World!\n");

	// Allocating space on the free store
	// ptr contains the address of the space allocated on the free store
	int* ptr = malloc( sizeof(int) );

	// I may also create another pointer which points to the same spot on the free store
	int* anotherptr = ptr;
	
	// Change the value of the variable on the free store to 3
	*ptr = 3;

	// Print the variable on the free store
	printf("Number %d\n", *ptr);

	// If I print using anotherptr I get the same thing
	printf("Number %d\n", *anotherptr);

	// Good idea to free the memory
	// You don't need to free anotherptr because it was pointing on the same variable
	free(ptr);

	// Another good idea is to set pointers to zero once they're freed. These guys are crazy.
	ptr = 0;
	anotherptr = 0;

	return 0;
}