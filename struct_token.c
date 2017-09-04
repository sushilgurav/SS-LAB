#include <stdio.h>
#include <string.h>

int main() {
/* Define a opcodedata structure */
        typedef struct {
                char label[10];
                char opcode[10]; char operend[10];
                } opcodedata ;
        opcodedata record[30];
        FILE * filehandle;
        char lyne[121];

        char *item;
        int reccount = 0;
        int k;

        /* Here comes the actions! */
        /* open file */

        filehandle = fopen("sam.txt","r");

        /* Read file line by line */

        while (fgets(lyne,120,filehandle)) {
              //  printf("\n%s",lyne);

                item = strtok(lyne," ");
                strcpy(record[reccount].label,item);

                item = strtok(NULL," ");
                strcpy(record[reccount].opcode,item);

                item = strtok(NULL,"\n");
                strcpy(record[reccount].operend,item);

         //       printf("%s\n",record[reccount].opcode);
                reccount++;
                }

        /* Close file */

        fclose(filehandle);

        /* Loop through and report on data */

    FILE *f;
    f = fopen("contacts.txt", "w");

    for (k=0; k<reccount; k++) {
                printf("%s\n",record[k].label);
                fprintf(f,"%s\n",record[k].label);
                }


    fclose(f);

       // printf("\n\noperend Record\n");


        }
