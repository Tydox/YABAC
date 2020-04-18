#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bm.h"


int main(void) {

    BM* TT = bm_make(16, 4);
    for (int c = 0; c <= --(TT->r_size); ++c)
    {
        //get the size of the invisible cube
        int box_size = (TT->r_size) / (2 * pow(2, c)); //8
        //input 0 or 1
        int tick = 0;
        //amount of switches
        int ticksum = (TT->r_size)/box_size; //2
        //count input rows
        int count=1;
    	//sum of flips of 0 and 1	
    	int flip=0;

        if(flip<ticksum){
        for (int r = 0; c <= --(TT->c_size); ++r)
        {
        if(count<box_size)
        {
             if(tick==0)
            bm_write(TT,r,c,0);
             else if(tick==1)
			bm_write(TT,r,c,1);

        	++count;	
        }
        else if (count==box_size)
        {
	        ++flip;
        	tick=!tick;
        }
        }
        }
    }
		
		bm_print(TT);

}


/*
   //if indicator reached last row, reset it and flip the switch
            if (indicator == box_size)
            indicator = 0;
            switcher = !switcher;


            if (switcher == 0) {
                if (indicator <= box_size)
                    bm_write(TT, r, c, 0);
                
            }
            else {
                if (indicator <= box_size)
                    bm_write(TT, r, c, 1);
            }
            
*/