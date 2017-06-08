#include <stdio.h>
char magic_num;
int col, row, max_colour, i, j, new_num, new_col, new_row;

/*
* Read the header of the standard input ppm
*/
void read_header()
{	
	// Read the user input 
	scanf("%s %d %d %d", &magic_num, &col, &row, &max_colour);
	// Print out the header
	printf("%s %d %d %d ", "P3", col, row, max_colour);
	printf("\n");
	return;
}

/*
* Read an image from the standard input and set the red value of each pixel to
* zero.
*/
void remove_red()
{	
	// Call the helper function to read the header
	read_header();
	// Loop over every row 
	for (i = 0; i < row; i++) {
		// Then going through every column
		for (j = 0; j < col*3; j++) {
			// Grab each pixel and if it's divisible by three
			// we know its a R pixel, hence change it to 0 as required
			scanf("%d", &new_num);
			if (j % 3 == 0) {
				printf("0 ");
			}
			// If it's not R pixel then leave it as it is
			else
			{
				printf("%d ",new_num);
			}
		}
	}
	printf("\n");
}

/*
* Read an image from the standard input and convert it from colour to black and white.
*/
void convert_to_black_and_white()
{
	// Call the helper function to read the header
	read_header();
	int red_num, green_num, blue_num;
	// Go through each row and then through each column and read the RGB pixel
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%d %d %d", &red_num, &green_num, &blue_num);
			// Add the all three numbers and get the average
			new_num = (red_num + green_num + blue_num) / 3;
			printf("%d %d %d ", new_num, new_num, new_num);
		}
	}
	printf("\n");
}

/*
* Read an image from the standard input and convert it to a square image.
*/
void instagram_square()
{
	
	scanf("%s %d %d %d", &magic_num, &col, &row, &max_colour);
	if (col > row) {
		new_col = row;
		printf("%s %d %d %d ", "P3", new_col, row, max_colour);
		for (i = 0; i < row; i++) {
			for (j = 0; j < col*3; j++) {
				scanf("%d", &new_num);
				if (j < new_col * 3) {
					printf("%d ", new_num);
				}
			}
		}
		printf("\n");
	}
	else {
		new_row = col;
		printf("%s %d %d %d ", "P3", col, new_row, max_colour);
		for (i = 0; i < row; i++) {
			for (j = 0; j < col*3; j++) {
				scanf("%d", &new_num);
				if (i < new_row) {
					printf("%d ", new_num);
				}
			}
		}
	}
}
