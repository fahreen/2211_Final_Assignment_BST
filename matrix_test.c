#include "matrix.h"
#include <stdio.h>

void main(){
    char *index1, *index2, *index3, *index4;
    index1= "Hello";
    index2= "Hella";
    index3= "bye";
    index4="zye";
    
    printf("Testing matric construction\n");
    Matrix m = matrix_construction();
    Value v1, v2, v3;
    v1=5;
    v2=10;
    v3=15;
    Value *v4, *v5, *v6;
    
    
    printf("Testing matrix set and get  \n");
    
    matrix_set(m,index1,index2, v1);
    v4= matrix_get(m,index1,index2);
    printf("Should print 5 : %d\n", *v4);
    
    matrix_set(m,index1,index2, v2);
    v4= matrix_get(m,index1,index2);
    printf("Same index is called after changing data, Should print 10 : %d\n", *v4);
    
    
    matrix_set(m,index3,index4, v3);
    v5= matrix_get(m,index3,index4);
     
     printf("Should print 15 : %d\n", *v5);
    
     v6 =matrix_get(m,index1,index3);

     /*printf("Should print null : %d", *v6);*/
     
     printf("\nTesting matrix inc, add 3 to 10\n");
     matrix_inc(m, index1, index2, 3);
v4= matrix_get(m,index1,index2);
     printf("Should print 13 : %d\n", *v4);
printf("Should print ERROR: ");
	matrix_inc(m, index1, index4, 4);
     
     printf("\nTesting matrix list \n");
     matrix_list(m);
    
 printf("Testing matrix_isin\n");
unsigned char c;
c = matrix_isin(m, index1, index2);
printf("Should print 1: %c\n", c);
c = matrix_isin(m, index1, index4);
printf("Should print 0: %c\n", c);

 
     printf("\nTesting matrix destruction \n");

matrix_destruction(m);}
