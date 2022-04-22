#include "bstree.h"
#include <stdio.h>

void main(){
    char *a, *b, *c, *d;
    a= "Hello";
    b= "Hella";
    c="bye";
    d = "zye";
    
    Key k1 = key_gen(a,c);
    Key k2 = key_gen(b,c);
    Key k3 = key_gen(b,c);
    Key k4 = key_gen(a,d);
    
    Data d1 = data_gen(5);
    Data d2 = data_gen(10);
    Data d3 = data_gen(15);
    Data d4 = data_gen(20);
    
    printf("Testing bstree initialization...\n");
    BStree bst = bstree_ini();
    
    printf("Testing bstree insert...\n");
    bstree_insert(bst, k1, d1);
    bstree_insert(bst, k2, d2);
    bstree_insert(bst, k3, d3); /* should print not inserted*/
    bstree_insert(bst, k4, d4);
    
    printf("Testing order with transversal...\n");
    printf("Should print (Hella, bye - 10)(Hello, bye - 5)(Hello, zye - 20)\n");
    bstree_traversal(bst);
    
    printf("Testing bst search...\n");
    
    Data d5 = bstree_search (bst, k1);
    printf("Should print five : ");
    data_print(d5);
    
    d5 = bstree_search (bst, k2);
    printf("Should print ten : ");
    data_print(d5);
    
    printf("Testing bstree free \n");
    bstree_free(bst);
}
