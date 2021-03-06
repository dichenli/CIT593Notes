#include <stdio.h>

/*
 * This program is supposed to read file1 and file2 and print the contents of each, 2 bytes at a time.
 * Every time it read 2 bytes, it also checks if that number is odd or even, keeping a count of that.
 * But it is full of bugs and doesn't work! Using GDB, try to detect every single of the bugs
 * and fix this program. When fixing this program, it would be ideal that you refrain from using
 * global variables to improve your knowledge of C.
 */

void updateEvenAndOdd(int read_file1, int read_file2, int * evenOddCount) {
	evenOddCount[read_file1 % 2]++;
	evenOddCount[read_file2 % 2]++;
}

void openFiles(FILE * file1, FILE * file2) {
	file1 = fopen("file1.obj", "rb");
	file2 = fopen("file2.obj", "rb");
}

/*
 * This method does an absurd number of useless operations to encourage you to use
 * more break points instead of stepping around too much
 */
void tonsOfUselessOperations() {
	int i;
	int j;
	for (i = 0; i < 1000; i++) {
		j = i;	
	}
}

int main() {
	int read_file1;
	int read_file2;
	int evenOddCount[2]; //evenOddCount[0] holds count of even, evenOddCount[1] holds count of odd
	FILE * file1 = NULL;
	FILE * file2 = NULL;
	openFiles(file1, file2);
	tonsOfUselessOperations();
	while (feof(file1) && feof(file2)) {
		fread(&read_file1, 1, 1, file1);
		fread(&read_file2, 1, 1, file2);
		printf("File 1: %0X, File 2: %0X\n", read_file1, read_file2);
		updateEvenAndOdd(read_file1, read_file2, evenOddCount);
		tonsOfUselessOperations();
	}
	printf("Number of even bytes: %d\n", evenOddCount[0]);
	printf("Number of odd bytes: %d\n", evenOddCount[1]);
	//are we forgetting to do something here?
	return 0;
}

