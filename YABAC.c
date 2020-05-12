#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bm.h"


int main(void)
{

	
	BM* table = bm_make(32, 5);
	//bm_print(table);
	
	for (int c = 1; c <= (table->c_size); ++c)
	{
		//get the size of the length of same input
		double padding_nums = (table->r_size) / (2 * pow(2, c-1)); //8

		int row=1;
		int sum_row=0;
		double num_rotate =(2 * pow(2, c-1)); // 2
		//8 rows
		//4 + 4=8
		//2+2+2+2=8
		//1+1+1+1+1+1+1+1=8
		float sum_rotate=1;
		while(sum_rotate<=num_rotate){
		for(;sum_row<padding_nums;++sum_row)
		{
			bm_write(table, row, c, 0);
			++row;
			
		}
			sum_row=0;
		for(;sum_row<padding_nums;++sum_row)
		{
			bm_write(table, row, c, 1);
			++row;
		}
			++sum_rotate;
			sum_row=0;
		}
		
	}

	bm_print(table);
	bm_destroy(table);
}


//{
//		//get the size of the invisible cube
//		int box_size = (table->r_size) / (2 * pow(2, c-1)); //8
//		//input 0 or 1
//		int tick = 0;
//		//amount of switches
//		int ticksum = (table->r_size) / box_size; //2
//		//count input rows
//		int count = 1;
//		//sum of flips of 0 and 1	
//		int flip = 0;
//
//		if (flip < ticksum)
//		{
//			for (int r = 1; r <= (table->r_size); ++r)
//			{
//				if (count <= box_size)
//				{
//					if (tick == 0)
//						bm_write(table, r, c, 1);
//					else if (tick == 1)
//						bm_write(table, r, c, 1);
//
//					++count;
//				}
//				else if (count == box_size)
//				{
//					++flip;
//					tick = !tick;
//				}
//			}
//		}
//	}