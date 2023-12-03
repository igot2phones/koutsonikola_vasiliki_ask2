#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#define MAX_FILE_NAME 100

FILE *f; // global variable gia na mporw na to xrisimopoihsw kai stin printFileProperties 

void printFileProperties(char f_name[MAX_FILE_NAME]);


int main(){
    char file_name[MAX_FILE_NAME];
    int retry = 1;
    while (retry) { // edw ekane replace thn goto loop pou eixa giti den einai kalo na xrisimopoieitai ;)
        printf("Please enter the file name to open: ");
        fgets (file_name, MAX_FILE_NAME, stdin);
        f = fopen(file_name, "rb+");
        if (f == NULL){
            printf("File does not exist\n");
        } else {
            retry = 0; // an to arxeio yparxei tote den xreiazetai na to ksanaprotinw kai kanw to retry = 0 gia na proxwrisei 
        }
    }
    printFileProperties(file_name);
}

void printFileProperties(char f_name[]){
    struct stat sfile; // struct gia na apothikeyw ta statistika tou arxeiou
    stat (f_name, &sfile); // apothikeyw ta statistika tou arxeiou stin struct sfile to sfile einai pointer gia na mporw na to perasw stin stat
    printf("File permissions: %o\n", sfile.st_mode & 0777); // emfanisi twn dikaiomaton tou arxeiou se oktadiko (ex. 0600)

    char creation_date[11]; // 11 giati to 10o einai to \0

    //apothikeyei tin imerominia dimiourgias tou arxeiou kai tin kainei se morfh YYYY-MM-DD 
    //(to gmtime einai gia na einai se morfh GMT kai mesa tou exw to sfile.st_ctime pou einai i imerominia dimiourgias tou arxeiou se morfh time_t)
    strftime(creation_date, 11, "%Y-%m-%d", gmtime(&(sfile.st_ctime)));
    printf("File creation date (GMT): %s\n", creation_date); // emfanisi tis imerominias dimiourgias tou arxeiou

    char modification_date[11]; // 11 giati to 10o einai to \0
    strftime(modification_date, 11, "%Y-%m-%d", gmtime(&(sfile.st_mtime))); //apothikeyei tin imerominia tis teleutaias epeksergasias tou arxeiou kai tin kainei se morfh YYYY-MM-DD
    printf("File last modified date (GMT): %s\n", modification_date);  // emfanisi tis imerominias tis teleutaias epeksergasias tou arxeiou
}
