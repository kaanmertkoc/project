#include <stdio.h>
#include <limits.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"
//Arif Dikkanat 
//041801098
int main() {
char str[100];
//getting a directory with path in order to do my operation(sort)
printf("Give a Directory name (path) to sort or press q to quit\n");   
        while(strcmp("q",str)!=0){
        //creating the double char pointer
        char **fileNames;
        scanf("%s",str); 
        //reading the filenames into the filenames with readFile method
        fileNames = readFile(str);
        //getting size with fileSize method
        int size = fileSize(str);
        //using my sort method in order sort the file names
        sort(fileNames,size);
    //printing the names in sorted way
    for(int i = 0; i< size; i++)
        printf("%s\n", fileNames[i]);
    //doing file operation and creating a new txt file and adding sorted file names line by line to it
    FILE *fp;
    fp = fopen("SortedFileNames.txt","w");
    for(int i = 0; i < size;i++){ 
       fprintf (fp, fileNames[i],i + 1);
       fprintf (fp, "\n","");
   }
       
         fclose(fp);
    


    }
    return 0;
}