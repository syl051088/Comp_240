/*
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "binary_convert.h"

int main(){
    unsigned char x = 0x66;
    unsigned char y = 0x39;
    unsigned char result = x & y;

    char * bx = uchar_to_bin_str(x);
    char * by = uchar_to_bin_str(y);

    char * b_result = uchar_to_bin_str(result);
    printf("%s &\n", bx);
    printf("%s\n", by);
    printf("---------\n");
    printf("%s\t%x\n\n", b_result, result);

    free(b_result);
    assert(result == 0x20);

    result = x | y;
    b_result = uchar_to_bin_str(result);
    printf("%s |\n", bx);
    printf("%s\n", by);
    printf("---------\n");
    printf("%s\t%x\n\n", b_result, result);

    free(b_result);
    assert(result == 0x7f);
    
    char * bin_str_x_complement = uchar_to_bin_str(~x);
	char * bin_str_y_complement = uchar_to_bin_str(~y);
    result = ~x | ~y;
    b_result = uchar_to_bin_str(result);

    printf("%s |\n", bin_str_x_complement);
    printf("%s\n", bin_str_y_complement);
    printf("---------\n");
    printf("%s\t%x\n\n", b_result, result);

    free(b_result);
	free(bin_str_x_complement);
	free(bin_str_y_complement);

    free(b_result);
    assert(result == 0xdf);

    result = x & !y;
	assert(result == 0);
	
	result = x && y;
	assert(result == 1);
	
	result = x || y;
	assert(result == 1);
	
	result = !x || !y;
	assert(result == 0);
	
	result = x && ~y;
	assert(result == 1);

    return 0;
}