#include <stdio.h>
#include <stdlib.h>

/*
* Include the function prototypes of all those functions implemented in image_processing.c.
* Do not remove or modify them in any way.
*/

void remove_red();
void convert_to_black_and_white();
void instagram_square();

int main(int argc, char *argv[]) {
	/* Task 1 needs to be completed here: Make sure that the command line arguments are correct. In case an error exists,
	* print the error message and terminate the program. Otherwise, invoke the corresponding
	* image processing function. */
	// If exactly two arguments are not present or either: 1,2 or 3 is not in the second argument then display error msg
	if (argc != 2) {
		printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.\n");
		// Exit the function immediately
		return 1;
	}
	else {
		// Command line contains no errors and call the corresponding image processing function
		// Call red removal function if 1
		char cmd_arg = *argv[1];
		if (cmd_arg == '1') {
			remove_red();
		}
		// Call black and white conversion if 2
		else if (cmd_arg == '2') {
			convert_to_black_and_white();
		}
		// Call instagram function if 3
		else if (cmd_arg == '3') {
			instagram_square();
		}
		// Proper number is not entered (i.e. 1,2,3 has not been entered, hence invalid)
		else {
			printf("Error: Expecting one command-line argument, which needs to be either 1, 2, or 3.\n");
			return 1;
		}

	}
	return 0;
}