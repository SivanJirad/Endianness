// 209193481 Sivan Jhirad

#define LOW '0'
#define HIGH '1'

/**************************************************************************
* Function Name:is_big_endian
* Input:none
* Output:The function returns 1 if it is compiled in Big endian machines
        and 0 if it is compiled in Little endian machines
* Function Operation:
        In Big endian machines: least significant byte has highest address
        In little endian machines: least significant byte has lowest address
*****************************************************************************/
int is_big_endian() {
    unsigned int num = 1;
    char* address = (char *) &num;
    if (*address == 0) {
        return 1;
    } else {
        return 0;
    }
}

/**************************************************************************
* Function Name:create_mask
* Input: number
* Output: num represent mask
* Function Operation:create mask
*****************************************************************************/
unsigned long create_mask(char type) {
    int size = (sizeof(unsigned long int));
    int num_of_bit = (size*8)/2;
    unsigned long mask = 1;
    for( int i = 0;i < num_of_bit -1; i++ ) {
        mask = mask << 1;
        mask = mask + 1;
    }
    if (type == HIGH) {
        for( int i = 0;i < num_of_bit; i++ ) {
            mask = mask << 1;
        }
    }
    return mask;
}

/**************************************************************************
* Function Name:merge_bytes
* Input: 2 numbers
* Output: new number
* Function Operation:
*****************************************************************************/
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    unsigned long mask_of_half_x = create_mask(HIGH);
    unsigned long mask_of_half_y = create_mask(LOW);
    return  (x & mask_of_half_x) + (y & mask_of_half_y);
}

/**************************************************************************
* Function Name:create_mask for number
* Input: i
* Output: mask
* Function Operation:
*****************************************************************************/
unsigned long create_mask_put_byte(int i) {
    int size = sizeof(unsigned long int) -1;
    unsigned long mask = 1;
    int num_of_loop = (size + 1 - i)* 8;
    for( int j = 0; j < num_of_loop -1 ; j++ ) {
        mask = mask << 1;
        if (j < 7  ) {
            mask = mask + 1;
        }
    }
    return mask;
}

/**************************************************************************
* Function Name:create_mask_for_b
* Input: number, i
* Output: mask
* Function Operation:
*****************************************************************************/
unsigned long create_mask_b(unsigned long b, int i) {
    int num_of_loop = (sizeof(unsigned long int) - i)* 8;
    for( int j = 0;j <num_of_loop-8 ; j++ ) {
        b = b << 1;
    }
    return b;
}

/**************************************************************************
* Function Name:put_byte
* Input: 2 numbers and i
* Output:new number
* Function Operation:
*****************************************************************************/
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    unsigned long mask = create_mask_put_byte(i);
    unsigned long maskB = create_mask_b((unsigned long) b,  i);
    return x - (x& mask) + maskB;
}



