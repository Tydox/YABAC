/* ADITIONAL INFORMATION */
/*
    -If(pointer) is checking whether the pointer is NULL or not.
*/
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include "bm.h"

/* Function Declarations */

BM* bm_make(int r_size, int c_size){
    /*
    The function attempts to construct a Matrix structure, allocating memory for its rows, and columns and initializing its entries.
    If any memory allocation fails or the sizes of its row or columns are negative or zero the function returns a NULL pointer.  
        */
    
    BM* M = NULL;
    if(0 < r_size && 0 < c_size){
        M = (BM*) malloc(sizeof(BM));
        if(M){
            M->c_size = c_size;
            M->rows = (float**) malloc(r_size*sizeof(float*)); 
            if(M->rows){            
                for(int r_index = 0; r_index < r_size; r_index++){
                    *(M->rows+r_index) = (float*) calloc(c_size,sizeof(float));
                    M->r_size = r_index+1;
                    if(!(*(M->rows+r_index))){ // if is null
                        r_index = r_size+10;
                        bm_destroy(M);
                    }
                }
            }
            else{
                free(M);
                M = NULL;
                M->r_size = 0;
                M->c_size = 0;
            }
        }
    }

    return M;   
}
void bm_destroy(BM* M){
    /*
    The function checks for NULL pointers, if the pointer isn't NULL then its values are set to zero, its memory is freed and its value set to NULL.
    */
    if(M){//not a null pointer
        if(M->rows){
            for(int r_index = 0; 0 < M->r_size && r_index < M->r_size; r_index++){
                if(*(M->rows+r_index)){ // not a null pointer
                    for(int c_index = 0; 0 < M->c_size && c_index < M->c_size; c_index++){
                        *(*(M->rows+r_index)+c_index) = 0;
                    }
                    //printf("index: %d %p\n ", r_index, *(M->structure+r_index));
                    free(*(M->rows+r_index));
                    *(M->rows+r_index) = NULL;
                }
            }
            free(M->rows);
            M->rows = NULL;
        }
        free(M);
        M = NULL;
    }
}
void bm_write(BM* M, int r_pos, int c_pos, float data){
    /*
    The function writes the given value to M[r_pos][c_pos] == *(*(M->rows + r_pos) + c_pos) Matrix entry as long as there're no NULL pointers before reaching that destination.
    */
    if(M && M->rows && 0 < r_pos && 0 < c_pos && M->r_size && M->c_size && r_pos <= M->r_size && *(M->rows + r_pos-1) && c_pos <= M->c_size){ //no null pointers and position value inside BM size limits
        *(*(M->rows + r_pos-1) + c_pos-1) = data;
    }
}
float bm_read(BM* M, int r_pos, int c_pos){
    /*
    The function reads the given value to M[r_pos][c_pos] == *(*(M->rows + r_pos) + c_pos) Matrix entry as long as there're no NULL pointers before reaching that destination.
    */
    float storage = rand();
    if(M && M->rows && 0 < r_pos && 0 < c_pos && M->r_size && M->c_size  && r_pos <= M->r_size && *(M->rows + r_pos-1) && c_pos <= M->c_size){ //no null pointers and position value inside BM size limits
        storage = *(*(M->rows + r_pos-1) + c_pos-1);
    }
    return storage;
}
void brow_swap(BM* M, int f_row, int s_row){ //f -> first s -> second
    /*
    The function swaps the Matrix f_row with s_row (commutatively) as long as those aren't NULL pointers nor the Matrix or the address containing it are.
    */
    float storage = 0;
    if(M && 0 < f_row && 0 < s_row && 0 < M->r_size && 0 < M->c_size  && f_row <= M->r_size && s_row <= M->r_size && *(M->rows + f_row-1) && *(M->rows + s_row-1)){ //not null pointer, usual row assignation(starts from 1)
        for(int c = 0; c < M->c_size; c++){
            storage = *(*(M->rows + f_row-1) + c);
            *(*(M->rows + f_row-1) + c) = *(*(M->rows + s_row-1) + c);
            *(*(M->rows + s_row-1) + c) = storage;            
        }
    }
}
void bm_print(BM *M){
    /*
    The function prints all Matrix entries in a tabular format.
    */
    if(M && M->rows && 0 < M->r_size && 0 < M->c_size){    
        printf("Column    ->  ");
        for (int i = 1; i <= M->c_size; ++i)
        {
            printf("%d     ", i);
        }
        putchar('\n');
        for (int r = 1; r <= M->r_size; ++r)
        {
            printf("\nRow %d ->     ", r );
            for (int c = 1; c <= M->c_size; ++c)
            {
                printf("%0.1f   ", bm_read(M, r, c));
            }
        }
    }
}
void bm_addrow(BM* M, int new_r_pos){
    /*
    */   

    float** storage;
    int new_r_size;
    if(M && M->rows && 0 < new_r_pos && 0 < M->r_size && 0 < M->c_size){
        storage = M->rows;
        new_r_size = M->r_size + 1;
        if(new_r_pos <= new_r_size){
            M->rows = (float**) realloc(M->rows, new_r_size*sizeof(float*));
            if(M->rows){//not null
                *(M->rows + new_r_size-1) = (float*) calloc(M->c_size, sizeof(float));
                if(*(M->rows + new_r_size - 1)){
                    M->r_size = new_r_size;
                    if(new_r_pos < new_r_size){
                        brow_swap(M, new_r_pos, new_r_size);
                        for(int r_swap_index = new_r_pos+1; r_swap_index <= new_r_size; r_swap_index++){
                            brow_swap(M, r_swap_index, new_r_size);   
                        }
                    }
                }
                else{
                    M->rows = (float**) realloc(M->rows, (new_r_size-1) * sizeof(float*));
                }
            }
            else{
                M->rows = storage;
            }
        }
    }
}

int bm_isnull(BM* M){
    /*
    The function checks if  the pointer to the structure and neither the structure nor the rows are null
    */
    int i = 1;
    if(M && M->r_size && M->rows){
        i--;
        while(i < M->r_size && *(M->rows+i)){
            ++i;
        }
    }
    
    return i != M->r_size;
}

void test_bm_isnull(){
    BM* MNULL = bm_make(0, 10);
    assert(bm_isnull(MNULL));
    BM* MOK = bm_make(1, 10);
    assert(!bm_isnull(MOK));
}

BM* bm_sum(BM* f_M, BM* s_M){
    /*
    The function sums both the s_M's entries and f_M BM's entries in a new r_M Matrix of the same row and column size. The sum is done between the same positional entries from both matrices
        thus both matrices must be the same row and column size then the function returns the address of r_M Matrix otherwise no operation is performed and a NULL pointer is returned.
    */
    
    BM* r_M = NULL;
    if(!(bm_isnull(f_M) || bm_isnull(s_M)) && f_M->r_size == s_M->r_size && f_M->c_size == s_M->c_size){
        r_M = bm_make(f_M->r_size, f_M->c_size);
        if(r_M){
            for (int r = 0; r < f_M->r_size; ++r)
            {
                for (int c = 0; c < f_M->r_size; ++c)
                {
                    //*(*(r_M->rows + r) + c) = *(*(f_M->rows + r) + c) + *(*(s_M->rows + r) + c);
                    bm_write(r_M, r, c, bm_read(f_M, r, c) + bm_read(s_M, r, c));
                }
            }
        }
    }
    return r_M;
}
BM* bm_mult(BM* f_M, BM* s_M){
    /*
    The function constructs a new matrix whose elements Aji are the result of the multiplication of (j) f_M Matrix's row  with the (i) s_M Matrix's column.
    Returns the direction of the resulting matrix otherwise if memory couldn't be assigned to the resulting matrix or the given matrices to multiply has any of its structure elements NUll 
    the function returns a NULL pointer.
    */
    
    BM* r_M = NULL;
    if(!(bm_isnull(f_M) || bm_isnull(s_M)) && f_M->c_size == s_M->r_size){
        r_M = bm_make(f_M->r_size, s_M->c_size);
        if(r_M){
            for (int r = 1; r <= f_M->r_size; ++r)
            {
                for (int c = 1; c <= s_M->c_size; ++c)
                {
                    float storage = 0;
                    for (int n = 1; n <= f_M->c_size; ++n)
                    {
                        storage += bm_read(f_M, r, n) * bm_read(s_M, n, c);
                    }
                    bm_write(r_M, r, c, storage);
                }
            }
        }
    }
    return r_M;
}
