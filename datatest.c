#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>
void main(){
    char *a , *b, *c, *d, *a1, *b1, *c1;
    
    a= "hello";
    b= "hella";
    c= "bye";
    
     printf("Testing string-dup... \n");
     d= string_dup(a);
     printf("Should print Hello : %s\n", d);
     free(d);
 
    printf("Testing key_gen... \n");
    Key k1 = key_gen(a,c);
    Key k2 = key_gen(b,c);
    Key k3 = key_gen(b,c);
    
    printf("Testing key_comp... \n");
    int x = key_comp (k1,k2);
    printf("Should print positive: %d\n", x);
    x= key_comp (k2,k1);
    printf("Should print negative: %d\n", x);
    x= key_comp (k2,k3);
    printf("Should print zero: %d\n", x);
    
    printf("Testing key_print...\n");
    key_print(k1);
    key_print(k2);
    key_print(k3);
    
    printf("Testing key_free...\n");
    key_free(k1);
    key_free(k2);
    key_free(k3);
    
    printf("KEY TESTS COMPLETED\n\n\n");
    
    
    printf("Testing data_gen and data print \n" );
    Data d1 = data_gen(5);
     printf("Should print five: ");
	data_print(d1);
     
     printf("Testing data_set... \n" );
     data_set(d1,10);
     printf("Should print ten: ");
	data_print(d1);
     
    printf("Testing data_free... \n" );
    data_free(d1);
    printf("data TESTS COMPLETED\n\n\n");
}
