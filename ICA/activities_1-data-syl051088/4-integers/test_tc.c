/*
 * Data activity 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "binary_convert.h"

int main()
{
	// some limits: it's best to see what our mchine will give us
	printf("short is %zu bytes wide\n", sizeof(short));
	printf("min value of a short is: %hd\n", SHRT_MIN);
	printf("max value of a short is: %hd\n", SHRT_MAX);

	////////////////  two's complement values
	printf("\nA few two's complement values\n");

	short tmp = -32767;

	char *bin_str;
	bin_str = short_to_bin_str(tmp);
	printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = SHRT_MIN;
	bin_str = short_to_bin_str(tmp);
	printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = 256;
	bin_str = short_to_bin_str(tmp);
	printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = -256;
	bin_str = short_to_bin_str(tmp);
	printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	////////////////  unsigned integer values
	printf("\nA few unsigned short integer values\n");
	unsigned short utmp = 245;

	printf("unsgined short is %zu bytes wide\n", sizeof(unsigned short));
	printf("min value of a short is: %hu\n", 0);
	printf("max value of a short is: %hu\n", USHRT_MAX);

	bin_str = short_to_bin_str(tmp);
	printf("%hu\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = 256;
	bin_str = short_to_bin_str(tmp);
	printf("%hu\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	tmp = 5;
	bin_str = short_to_bin_str(tmp);
	printf("%hu\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);

	short int v = -12345;
	unsigned short uv = (unsigned short)v;
	char *bin_str1;
	char *bin_str2;
	bin_str1 = short_to_bin_str(v);
	bin_str2 = ushort_to_bin_str(uv);
	printf("v = %hd, \t%s,\nuv = %hu, \t%s\n", v, bin_str1, uv, bin_str2);
	free(bin_str1);
	free(bin_str2);

	v = 12345;
	uv = (unsigned short)v;
	bin_str1 = short_to_bin_str(v);
	bin_str2 = ushort_to_bin_str(uv);
	printf("v = %hd, \t%s,\nuv = %hu, \t%s\n", v, bin_str1, uv, bin_str2);
	free(bin_str1);
	free(bin_str2);

	int p = 32768;
	short int q = (short int)p;
	bin_str1 = short_to_bin_str(p);
	bin_str2 = int_to_bin_str(q);
	printf("p = %d, \t%s,\nq = %hd, \t%s\n", p, bin_str1, q, bin_str2);
	free(bin_str1);
	free(bin_str2);

	short a = 32767;
	int b = (int)a;
	bin_str1 = short_to_bin_str(a);
	bin_str2 = int_to_bin_str(b);
	printf("a = %d, \t%s,\nb = %hd, \t%s\n", a, bin_str1, b, bin_str2);
	free(bin_str1);
	free(bin_str2);

	///////////////////////////////// Part 3- keep commented until you work on this later
	// create the hexidecimal table for all 1-byte signed numbers
	signed char i;
	char * bin;

	//uncomment this section for part 3
	printf("decimal\thex\tbinary\n");

	for (i=-64; i<=63; i++) {
		bin = char_to_bin_str(i);
		printf("%hhd\t%02hhx\t%s\n", i, i, bin);
		free(bin);

	}

	for (i=-128; i<=127; i++) {
		bin = char_to_bin_str(i);
		printf("%hhd\t%02hhx\t%s\n", i, i, bin);
		free(bin);
		if (i == 127) break;
	}
}
