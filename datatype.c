#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

/* Duplicate string pointed to by str with dynamic memory allocation. */
char * string_dup(char *str){
    
    /*create new pointer*/
    char *s;
    /* allocate mempry for parameter and make it point to str*/
    s = strdup(str);
    return s;
}

/*Generate a key with dynamic memory allocation*/
Key key_gen(char *skey1, char *skey2){
    /* allocate memory for a key instance*/
    Key k;
    k = (Key_struct*)malloc(sizeof(Key_struct));
    char *a= string_dup(skey1);
	char *b = string_dup(skey2);
    /* set members of the key instance to point to parameters */
    k->skey1 = a;
    k->skey2= b;
    return k;
    
}


/*If key1->skey1 and key2->skey1 are different then they determine the comparison result. 
 *  * If key1->skey1 and key2->skey1 are the same, then key1->skey2 and key2->skey2 determine
 *   *   result.*/
int key_comp(Key key1, Key key2){
    /*compare string 1*/
    int x = strcmp (key1->skey1, key2->skey1);
    if (x != 0)
        return x;
    x = strcmp (key1->skey2, key2->skey2);
    return x;
}

/*Print a key.*/
void key_print(Key key){
    printf ("%s\t\t%s", key->skey1, key ->skey2);
}

/*Free memory allocated for key.*/
void key_free(Key key){
    free(key ->skey1);
    free(key->skey2);
	free(key);
}

/*Generate a data with dynamic memory allocation.*/
Data data_gen(int idata){
    Data p;
    p = (int*)malloc(sizeof(int));
    *p = idata;   
}

/*Assign data with idata.*/
void data_set(Data data, int idata){
    *data = idata;
}

/*Print a data*/
void data_print(Data data){
    printf ("Occurence : %d",*data);
    printf("\n");
}

/*Free memory allocated for data*/
void data_free(Data data){
    free (data);
}
