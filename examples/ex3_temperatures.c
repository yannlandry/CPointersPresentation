/*****************************
 * EXAMPLE 3
 *
 * More advanced concepts
 * using struct and pointers
 * to structs.
 *****************************/


#include "stdio.h"
#include "stdlib.h"


struct TemperatureRecord {
	int year;
	int month;
	int day;

	float minimum;
	float maximum;
};


int main() {

	// Pointer to a TemperatureRecord		We allow 3 continuous spaces for TemperatureRecord
	struct TemperatureRecord* temperatures = malloc(3 * sizeof(struct TemperatureRecord));

	// Just dummy data, if we had a lot of these going for the free store would be mandatory
	// Data record #0
	temperatures[0].year = 2014;
	temperatures[0].month = 12;
	temperatures[0].day = 2;
	temperatures[0].minimum = -15.5;
	temperatures[0].maximum = -6.7;

	// Data record #1
	temperatures[1].year = 2014;
	temperatures[1].month = 12;
	temperatures[1].day = 1;
	temperatures[1].minimum = -10.2;
	temperatures[1].maximum = 1.3;

	// Data record #2
	temperatures[2].year = 2014;
	temperatures[2].month = 11;
	temperatures[2].day = 30;
	temperatures[2].minimum = -5.0;
	temperatures[2].maximum = 7.4;

	// Small variables on the stack
	float min = 0, max = 0, avg = 0;

	// Process, etc etc.
	for(int i = 0; i < 3; ++i) {

		if(temperatures[i].minimum < min)
			min = temperatures[i].minimum;

		if(temperatures[i].maximum > max)
			max = temperatures[i].maximum;

		avg+= (temperatures[i].minimum + temperatures[i].maximum) / 2;
	}

	// Finalize average
	avg/= 3;

	// Print stuff
	printf("Minimum temperature: %f || Maximum temperature: %f || Average temperature: %f\n", min, max, avg);

	// Free and put to zero
	free(temperatures);
	temperatures = 0;

	return 0;
}