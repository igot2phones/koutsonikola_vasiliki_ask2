#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#define MAX_FILE_NAME 100

FILE *f;

void printFileProperties(char f_name[MAX_FILE_NAME]);


int main(){
    char file_name[MAX_FILE_NAME];
    retry:
    printf("Please enter the file name to open: ");
    fgets (file_name, MAX_FILE_NAME, stdin);
    f = fopen(file_name, "rb+");
    if (f == NULL){
        printf("File does not exist\n");
        goto retry;
    }
    printFileProperties(file_name);
}

void printFileProperties(char f_name[]){
    struct stat sfile;
    stat (f_name, &sfile);
    printf("st_mode: = %o\n", sfile.st_mode);
}