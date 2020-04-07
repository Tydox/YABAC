  
int main(void) {
    BM* TT = bm_make(16, 4);
    for (int c = 0; c <= --(TT->r_size); ++c)
    {
        //get the size of the invisible cube
        int box_size = (TT->r_size) / (2 * pow(2, c));
        //switch will be 0 or 1
        int switcher = 0;
        //indicator will tell us position on the row
        int indicator = 0;

        for (int r = 0; c <= --(TT->c_size); ++r)
        {
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
            
            ++indicator;

        }
    }
    bm_print(TT);

}
