#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

/* Allocate memory of type BStree node*, set the value to NULL
 *  * , and return a pointer to the allocated memory.*/






BStree bstree_ini(void){
    BStree bst;
    bst = (BStree)malloc (sizeof(BStree_node*));
    *bst = NULL;
    return bst;
}

/* Helpers */

/*Create a pointer using key & data
 *  *Allocate space for children, and make them point to NULL*/

BStree_node* new_node (Key key, Data data){
    BStree_node *p;
    p = (BStree_node*)malloc(sizeof(BStree_node));
    p ->key = key;
    p->data = data;
    p->left = (BStree_node*)malloc(sizeof(BStree_node));
    p->right= (BStree_node*)malloc(sizeof(BStree_node));
    p->left=p->right=NULL;
    return p;
}

/*Insert data with key into bst. If key is in bst, 
 *  * then do nothing.*/
void bstree_insert(BStree bst, Key key, Data data){
    
    if (*bst == NULL){
	printf("\n key inserted successfully \n");
        *bst = new_node(key, data);
    }
    else{
        int x = key_comp(key, (*bst)->key);
        if (x==0)
            printf("\nkey already in tree\n");
        else{
     
        if (x<0)
            bstree_insert(&(*bst)->left, key , data);
        else 
             bstree_insert(&(*bst)->right, key , data);
    }
    }}


Data bstree_search(BStree bst, Key key){
    BStree_node **current;
    current = bst;
    int x;
    while(1){
        if (*current == NULL)
            return NULL;
        int x = key_comp (key,(*current)->key);
        if (x==0)
            return (*current)->data;
        if (x<0)
            current = &((*current)->left);
        else
          current = &((*current)->right);  
    }
    
}





/* helper function for transversal*/
void print_node(BStree_node *node){
    key_print(node->key);
    data_print(node->data);
    printf("\n");
}

void inorder_print(BStree_node *node){
    if(node -> left != NULL)
        inorder_print(node->left);
    print_node(node);
    if(node -> right != NULL)
         inorder_print(node->right);
    
}

void bstree_traversal(BStree bst){
    
    inorder_print(*bst);
}



void free_nodes(BStree_node *bt){
    if (bt == NULL)
        return;
    free_nodes(bt->left);
    free_nodes(bt->right);
    data_free(bt->data);
    key_free(bt->key);
    free(bt);
    
}


void bstree_free(BStree bst){
    free_nodes(*bst);
    free(bst);
    
}

