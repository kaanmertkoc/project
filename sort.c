#include <stdio.h>
#include <limits.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
//Arif Dikkanat
//041801098
char** readFile(char *dir) {
    //reading the info inside the directory
    int size = fileSize(dir);
    // creating a double char pointer with malloc in order to add my file names under directory into it
    char **fileNames = malloc(size * sizeof(char *));
    //creating each index of filenames with malloc
    for (int i = 0; i < 200; i++)
    {
        fileNames[i] = malloc(200 * sizeof(char *));
    }
    //using DIR to get the informations(file names) in the directory
    DIR *dp;
    struct dirent *ent;
    int counter = 0;
    if((dp = opendir(dir)) != NULL) {
        while((ent = readdir(dp)) != NULL) {
            if(strcmp(".", ent->d_name) == 0 || strcmp("..", ent->d_name) == 0)
                continue;
            //creating a char array to put the names of the files in the directory line by line 
            char str[200];
            strcpy(str, ent->d_name);
            for(int i = 0; i < 200; i++) {
                //adding file names into filenames
                fileNames[counter][i] = str[i];
            }
            counter++;
        }
    }
    return fileNames;
}
//doing the same operations in the readfile and trying to get the size by creating a counter and returning it
int fileSize(char *dir){
    //getting the directory and finding the size 
    DIR *dp;
    struct dirent *ent;
    int counter = 0;
    if((dp = opendir(dir)) != NULL) {
        while((ent = readdir(dp)) != NULL) {
            if(strcmp(".", ent->d_name) == 0 || strcmp("..", ent->d_name) == 0)
                continue;
            counter++;
        }
    }
    return counter;
}
void sort(char** names, int n) 
{ 
    int i, j; 
  
    // Performing the  sort operation with using bubble sort
    //using a nested loop in order to perform my bubble sort
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++) 
            //comparing each char with each other and do the neccesary changes with the usage of temp 
            if (strcmp(names[j], names[j + 1]) > 0) { 
                char* temp; 
                temp = (char*)calloc(30, sizeof(char)); 
                strcpy(temp, names[j]); 
                strcpy(names[j], names[j + 1]); 
                strcpy(names[j + 1], temp); 
            } 
} 