#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LINE 80

extern int errno;
char* fileCharBuffer;
char date[MAX_LINE];
char competition[MAX_LINE];
int fileLength = 0;
int amountOfLines = 0;

typedef struct line{
    char lineData[MAX_LINE];
}line;

typedef struct node {
    char name[50];
    char address[50];
    char phone[40];
    int competitorId;
    float lengthOfCucumberInInches;
    float lengthOfCarrotInInches;
    float lengthOfRunnerBeanInInches;

    struct node* right;
    struct node* left;

} parent;

FILE* open(){
    FILE* data;
    data = fopen("/home/def/hort_2014.txt", "r");
    return data;
}

FILE* loadFile() {
    int errnum;
    FILE* data;
    char fileLocation[200];
    
    do {
        printf("Enter the location of the file: ");
        scanf("%s", fileLocation);
        data = fopen(fileLocation, "r");
        if (data == NULL) {
            errnum = errno;
            if (errnum == 2)
                printf("Cannot find specified file, Please enter a correct path\n");
            if (errnum == 13)
                printf("File Permission Denied\n");
        } else {
            return data;
        }
    } while (!data);
    return NULL;
}


int getFileSize(FILE* input) {
    int positionInFile;
    fseek(input, 0, SEEK_END);
    positionInFile = ftell(input);
    fseek(input, 0, SEEK_SET);
    return positionInFile;
}

void createFileBuffer(int fileSize) {
    fileCharBuffer = malloc(sizeof (char) * fileSize);
}

void createLineBuffer(){
    //fileLineBuffer = malloc(sizeof(line) * amountOfLines);
}

void fillLineBuffer(){
    char lines[amountOfLines][MAX_LINE];
}

void loadFileIntoBuffer(FILE* input, int filesize) {
    char c;
    int i = 0;
    while((c = fgetc(input)) != EOF){
        fileCharBuffer[i] = c;
        i++;    
    }
    fclose(input);
}

//char* newLineBreak(){
//    char line[MAX_LINE];
//    for(int i = 0; i < fileLength; i++){
//        if(fileBuffer[i] != '\n')
//            line[i] = fileBuffer[i];
//    }
//    return line;
//}

void getTitleAndDate(){
    sscanf(fileCharBuffer, "%[^\n] %[^\n]", competition, date);
}

void getAmountOfLines(){
    for(int i = 0; i < fileLength; i++)
        if(fileCharBuffer[i] == '\n')
            amountOfLines++;
    
}

int main() {
    fileLength = getFileSize(open());
    createFileBuffer(fileLength);
    loadFileIntoBuffer(open(), fileLength);
    getTitleAndDate();
    getAmountOfLines();
    fillLineBuffer();
    
    printf("comp: %s\ndate: %s\n", competition, date);
    printf("lines: %d", amountOfLines);
    
    return 0;
}
