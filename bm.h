#pragma once
//BM.h library

#ifndef BM_H
#define BM_H

/* Definitions */
typedef struct {
    float **rows;
    int r_size; //rows
    int c_size; //columns
} BM;

/* Function prototypes */
BM* bm_make(int r_size, int c_size);
    /*
    The function attempts to construct a Matrix structure, allocating memory for its rows, and columns and initializing its entries to zero.
    If any memory allocation fails or the sizes of its row or columns are negative or zero the function returns a NULL pointer.  
        */
void bm_destroy(BM *M);
    /*
    The function checks for NULL pointers, if the pointer isn't NULL then its values are set to zero, its memory is freed and its value set to NULL.
    */
void bm_write(BM *M, int r_pos, int c_pos, float data);
    /*
    The function writes the given value to the matrix r_pos row and c_pos column cell.
    */
float bm_read(BM *M, int r_pos, int c_pos);
    /*
    The function reads the given value to matrix r_pos row and c_pos column cell.
    */
void bm_rowswap(BM *M, int f_row, int s_row);
    /*
    The function swaps the Matrix f_row with s_row as long as those aren't NULL pointers nor the Matrix or the address containing it are. In case memory assignation fails the function does nothing.
    */
void bm_addrow(BM *M, int new_r_pos);
    /*
    The function adds a new row which elements are all zeros in new_r_pos position, does nothing in case new row memory assignation fails.
    */   
void bm_print(BM  *M);
    /*
    The function prints all Matrix entries in a tabular format as long as the given matrix is not null.
    */
int bm_isnull(BM *M);
    /*
    The function checks if  the pointer to the structure and neither the structure nor the rows are null and returns the result value.
    */
BM* bm_sum(BM *f_M, BM *s_M);
    /*
    The function builds a new matrix of the same size as the given ones whose values are those resulting of the sum of the given matrices.
    The operation follows the math definition of sum of matrices.
    Returns NULL in case memory assignation for the resulting matrix fails or the given matrices are null.
    */
BM* bm_mult(BM *f_M, BM *s_M);
    /*
    The function builds a new matrix whose values are the multiplication of the given matrices.
    The operation follows the math definition for matrix multiplication
    In case of failure assigning memory for the new matrix or the given ones are null the function returns NULL 
    */
#endif