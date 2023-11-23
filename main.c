#include <stdio.h>
#define MAX_FILE_NAME 100

FILE *f;

void open();
void close();
void read();    
void write();

int main(){
    open();
    open();
}

void open(){
    char file_name[MAX_FILE_NAME];
    printf("Please enter the file name to open or create: ");
    fgets (file_name, MAX_FILE_NAME, stdin);
    f = fopen(file_name, "rb+");
    if (f == NULL ) {
        f = fopen(file_name, "wb");
        if (f == NULL) {
            printf("Cannot open file %s\n", file_name);
        } else {
            printf("File created successfully!\n");
        }
    } else {
        printf("File opened successfully!\n");
    }
}