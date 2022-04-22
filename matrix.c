#include "matrix.h"
#include <stdio.h>



Matrix matrix_construction(void){
    Matrix m = bstree_ini();
    return m;
}


unsigned char matrix_isin(Matrix m, Index index1, Index index2){
    Key k = key_gen (index1, index2);
    Value *v = bstree_search(m,k);
    
    /* NOT SURE*/
    key_free(k);
    
    if (v== NULL){
        return '0';
    }
    return '1';
    
    
}
Value *matrix_get(Matrix m, Index index1, Index index2){
    Key k = key_gen (index1, index2);
    Value *v = bstree_search (m,k);
    return v;
}


void matrix_set(Matrix m, Index index1, Index index2, Value value){
 
    unsigned char present =  matrix_isin(m, index1, index2);
  /* index pair not in matrix*/
  Key k = key_gen (index1, index2);
  
  if (present == '0'){
      Data d = data_gen(value);
      bstree_insert(m, k ,d);}
 else{
    data_set(bstree_search(m,k),value);
     key_free(k);
  }}

/*If location (index1, index2) is defined in Matrix m, then increase
 *  *  the associated value by value. Otherwise, report error.*/
void matrix_inc(Matrix m, Index index1, Index index2, Value value){
    unsigned char present =  matrix_isin(m, index1, index2);
    if (present == '0'){
        printf("Indexe is not defined in the matrix");
    }
    else{
        Key k = key_gen (index1, index2);
        Data d = bstree_search(m,k);
        *d = *d + value;
    }
    
}
/*Print indices and values in the Matrix m (with bstree traversal())*/
void matrix_list(Matrix m){
    bstree_traversal(m);  
}
void matrix_destruction(Matrix m){
    bstree_free(m);
}
