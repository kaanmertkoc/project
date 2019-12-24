#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

//Kaan Mert Koç 041801122
//This method finds the size of the file, it's input is char pointer
//named dir, i used dirent.h library. I create a DIR type pointer named dp and a pointer object
//named ent. Then i opened the directory and count the files in it. Because of 
// readdir function's first two line is .. and . in order to prevent that i added an if block on line 16.

int fileSize(char *dir) {
	DIR *dp;
	struct dirent *ent;
	int counter = 0;
	if((dp = opendir (dir)) != NULL) {
		while((ent = readdir(dp)) != NULL) {
			if(strcmp(".", ent->d_name) == 0 || strcmp("..", ent->d_name) == 0)
				continue;
			counter++;
		}
	}
	closedir(dp);
	return counter;
}
//my search method takes one double pointer array type of character that is a 2D array that i stored files names
//other input is element that wanted to be searched, third input is the size of 2d array.
//by using strcmp i compare the element in array with element that is the input.
//If it is found it says it is found and prints it's location.
void search(char **example, char *element, int size) {
	
	for(int i = 0; i< size; i++) {
		if(strcmp(example[i], element) == 0) {
			
			printf("Found the file named %s under  desktop! \n", element);
			return;
		}
		
	}
	printf("There is no file named %s try to change directory or search something else. \n", element);
	
}
// my read file method is like file size, only difference is first it opens the 2d array using malloc
// also it opens the all arrays that stored in the first index. Then fills it with file names that into directory.

char** readFile(char *dir) {
	int size = fileSize(dir);
	char **fileNames = malloc(size * sizeof(char *));
	for (int i = 0; i < 200; i++)
	{
		fileNames[i] = malloc(200 * sizeof(char *));
	}
	DIR *dp;
	struct dirent *ent;
	int counter = 0;
	if((dp = opendir(dir)) != NULL) {
		while((ent = readdir(dp)) != NULL) {
			if(strcmp(".", ent->d_name) == 0 || strcmp("..", ent->d_name) == 0)
				continue;
			char str[200];
			strcpy(str, ent->d_name);
			for(int i = 0; i < 200; i++) {
				fileNames[counter][i] = str[i];
			}
			counter++;
		}
	}
	return fileNames;
}