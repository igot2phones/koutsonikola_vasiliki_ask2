#include <stdio.h>
#include <stdlib.h> // gia na min paraponietai o compiler gia tin exit(0); stin grammh 41
#define MAX_FILE_NAME 500
#define MAX_LENGTH 101

FILE *f;

void open();
void close();
void read();    
void write();

int main(){
    char choice;
    printf("Welcome to to the file managment programme\n");
    printf("To begin an action please type one of the letters shown bellow :\n");
    printf("Option (o) : To open/create the file\n");
    printf("option (w) : To write a file\n");
    printf("option (r) : To read a file\n");
    printf("option (c) : To close a file\n");
    printf("option (e) : To exit the programe\n");

    while (1) {
        printf("\nEnter your choice : ");
        scanf("%s", &choice);
        switch (choice)
        {
        case 'o':
            open();
            break;
        case 'w':
            write();
            break;
        case 'r':
            read();
            break;
        case 'c':
            close();
            break;
        case 'e':
            exit(0);
            break;
        default:
            printf("Wrong input !!!! \nPlease select one of the following !!!!\n");
            break;
        }
        
    }
    

}

void open(){
    char file_name[MAX_FILE_NAME];
    printf("Please enter the file name to open or create: ");
    while ((getchar()) != '\n');  // Clear input buffer gia na min mou exei problima
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

void close(){
    if (f == NULL){
        printf("There isn't any file open");
    } else {
        fclose(f);
    }
}

void read(){
    if (f == NULL){
        printf("There is no open file please open one first !!\n");
    } else {
        char xaraktires[MAX_LENGTH]; // 100 + 1 gia to \0
        fread(xaraktires, sizeof(char), 100, f); // diavazei 100 xaraktires apo to arxeio kai ta apothikeuei sto xaraktires
        printf("%s", xaraktires);
    }
}

void write(){
    if (f == NULL){
        printf("There is no open file to read please open a file first\n");
    } else {
        char xaraktires_to_wr[MAX_LENGTH];
        printf("Grapse 100 xaraktires\n");
        while ((getchar()) != '\n');  // Clear input buffer gia na min mou exei problima
        fgets(xaraktires_to_wr, MAX_LENGTH, stdin);
        fwrite(xaraktires_to_wr, sizeof(char), MAX_LENGTH, f);
    }
}