  
int main(void) {
    BM* TT = bm_make(16, 4);
    for (int c = 0; c <= --(TT->r_size); ++c)
    {
        //get the size of the invisible cube
        int box_size = (TT->r_size) / (2 * pow(2, c));
     
        int sum = 0;
        int temp = 0;
        for (int r = 0; c <= --(TT->c_size); ++r)
        {
     
            if (temp == box_size)
            temp = 0;
            sum = !sum;

            if(temp<box_size)
            bm_write(TT, r, c, 0);
            
            --temp;
            ++sum;

        }
    }
    bm_print(TT);

}
