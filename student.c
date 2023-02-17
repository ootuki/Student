#include <stdio.h>
// Using structures
typedef struct {
	
	// name. TODO let it be String instead of char
	char name;
	// age
	int age;
	// roll number
	int rolln;
	// overall score
	float score;
}user_input;
// function declarations
user_input getUserInput();
int fileWrt (char , int , int , float );

// main function
int main (void)
{
	// structure
	// input tmp values as my text book says that
	// "setting values to a structure at the time of initiation is a good manner "
	user_input ui;
//	ui.flt1 = 1.1;
	
	char name;
	int age;
	int rolln;
	float score;
	
	// Boolean mentions file handle failed or not (0: not failed(success) 1: fail)
	int failed = 0;
	
	ui = getUserInput();

	// prepare some valuables to stock values in "ui" structure. 
	// Otherwise a duplicated structure declaration is mandatory inside the fileWrt function.
	// TODO ask Pranav san that which is the good manner. 
	// Prepare a temp storages or again declare in another function, which one is better.
	name = ui.name;
	age = ui.age;
	rolln = ui.rolln;
	score = ui.score;
		
	// write the result to the file.
	failed = fileWrt(name, age, rolln, score);
	// if filehandling get failed, print the error.
	if (failed == 1) {
		perror("failed on file handling. \n");
	}
		
	return 0;
}
user_input getUserInput() 
{
	user_input ui;

	// name
	printf("Name:\n");
	// getchar() gets a char from standard input, and returns its value. 
	// Here it is used for waste a line break code (\LF\CR or \CR)
	//getchar();
	scanf("%s", &ui.name);
	// age
	printf("Age:\n");
	scanf("%d", &ui.age);
	// roll number
	printf("Roll No.:\n");
	scanf("%d", &ui.rolln);
	// score
	printf("Score:\n");
	scanf("%f", &ui.score);

	return ui;
}

// file handle function. Add results to the file.
// TODO let the input values be a structure.
int fileWrt (char name, int age, int rolln, float score)
{
	// file write success or not. Boolean
	int failed = 0;
	
	// File and data
	FILE *fp;
	fp = fopen ("result.txt", "a");

	// check the file existance
	if (fp == NULL) {
		failed = 1; 
	}
	else {
		// operation to the file.
		// write file the users input
		fprintf(fp, "%c %d %d %f\n", name, age, rolln, score );
		
		fclose(fp);
		
		failed = 0;
	}	
	
	return failed;
}

