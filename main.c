#include <stdio.h>
#include "matrix.h"
#include <string.h>
#include <stdlib.h>

int main(void){

   /* declare all variables and struct types */
    char index1[100], index2[100] ,  str[200];

   /* initialize tree */
    Matrix m;
    m = matrix_construction();

   /* get key and data pair from stdin */
    while(1){
        printf ("Please enter index pair, or E to exit\n ");
        fgets(str, 200, stdin);

        /* exit loop if enf of file or user exits with "E" */
        if ( feof(stdin) | str[0] == 'E')
                break;

        /* if not at the end, break str from stdin into tokens */
        strcpy(index1, strtok(str, " "));
        strcpy(index2, strtok (NULL, " "));
        
        unsigned char c = matrix_isin(m, index1, index2);
        Value v = 1;
        if (c == '0')
            matrix_set(m, index1, index2, v);
        else
            matrix_inc(m, index1, index2,v);
           

    }
   printf("\n");

   /* transverse tree then free allocated memory */
printf("String1\t\tString2\n");   
matrix_list(m);
   matrix_destruction(m);
}
