
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "search3.h"


int main() {
	//first input is the path to the directory second is the element that wanted to be search
	// While input is not q program keeps running if it is null exits the program.
		char path[100], fileName[200];

		while(strcmp("q",path) != 0) {
		printf("Enter a path to directory that this file wanted to be searched. Or press q to quit.\n");

		scanf("%s",path);
		if(strcmp("q",path) != 0) {
			printf("Enter a file name ");
			scanf("%s",fileName);
			char **example;
			example = readFile(path);
			int size = fileSize(path);
			char *element = malloc(sizeof(char *));
			element = fileName;
			search(example, element,size);
		}
		
	}
	return 0;
	
}