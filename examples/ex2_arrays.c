/*****************************
 * EXAMPLE 2
 *
 * Creating arrays on the
 * free store and accessing
 * their items.
 *****************************/


#include "stdio.h"
#include "stdlib.h"


int main() {
	
	// sizeof(int) is always 4, but for some types of variables it's hard to tell the size or you may just be too lazy to Google it
	// or you may be on a different (but rare) machine where sizeof(int) is 2. That's why we ALWAYS use sizeof.

	// Okay, so now we're going to create an ARRAY of ints on the free store
	// Which is in fact just a bunch of ints in a continuous space
	int* array = malloc(3 * sizeof(int)); // The size of an int is 4 so to create 3 ints I have to request 12 spaces or 3 * sizeof(int)

	// Let's put values into our array on the free store
	// Now be careful: when you add 1 to an int* (pointer to an int), it's actually going to add 4 because the size of an int is 4
	*array			= 2; 	// Just like *(array + 0)
	*(array + 1) 	= 4;
	*(array + 2) 	= 8;

	// Time to print
	printf("%d %d %d\n", *array, *(array + 1), *(array + 2));

	// You can use the [] notation as a shortcut
	printf("%d %d %d\n", array[0], array[1], array[2]);

	// Essentially,
	// array[n] = *(array + n)

	// Free & put to zero
	free(array);
	array = 0;

	return 0;
}