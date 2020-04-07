
int main(void) {
    BM* TT = bm_make(16, 4);
    for (int c = 0; c <= --(TT->r_size); ++c)
    {
        //get the size of the invisible cube
        int box_size = (TT->r_size) / (2 * pow(2, c);

        for (int r = 0; c <= --(TT->c_size); ++r)
        {
            int sum = 0;
            int temp = box_size;
            if (temp == 0)
                temp = box_size;
            bm_write(TT, r, c, 0));
        --temp;

        }
    }
    bm_print(TT);

}
