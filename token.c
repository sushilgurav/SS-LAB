#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

int main(){
    FILE *testFile = fopen("file.txt", "r");
    char buffer[BUFFER_SIZE];
    char *delim = ",";
    char *lastToken;
    char *holder[50][50];
    int i, i2;

    if(testFile == NULL){
        printf("Error!");
    } else {

    i = 0;
    while(fgets(buffer, BUFFER_SIZE, testFile) != NULL){
        i2 = 0;
        lastToken = strtok(buffer, delim);
        while(lastToken != NULL){
            holder[i][i2] = lastToken;
            printf("holder[%i][%i] - %s\n", i, i2, holder[i][i2]);
            lastToken = strtok(NULL, delim);
            i2++;
        }
        i++;
    }
    fclose(testFile);

    } //if file is opened (endif)

    printf("%s\n", holder[0][2]);

    return 0;
}
