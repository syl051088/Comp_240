#include <stdio.h>
#include <assert.h>

unsigned int merge_bits(unsigned int a, unsigned int b, unsigned int mask);

int main()
{

  unsigned int mask = 0xff;
  unsigned int a = 0xabcd;
  unsigned int b = 0x2234;
  unsigned int r;

  printf("   a    \t   b    \t  mask   \t result \n");

  // some example tests
  // the first byte comes from a and the second byte comes from b
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  // instead of or in addtion to printing, you should use assertions,
  // like this below. If the output of your program will be large, just
  // keep the asserts and comment the prints.
  // note that  <assert.h>  must be included at the top of the file
  assert(r == 0xab34);

  // the first byte comes from b and the second byte comes from a
  mask = 0xff00;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0x22cd);

  // the first 4 bits come from b and the last 12 bits all come from a
  mask = 0xf000;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0x2bcd);

  // the first 12 bits come from a and the last 4 bits come from b
  mask = 0x000f;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0xabc4);

  // the output should be b
  mask = 0xffff;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0x2234);

  // the output should be a
  mask = 0x0000;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0xabcd);

  // -----------------------------------------------------------------------

  mask = 0xffff;
  a = 0x0;
  b = 0xffffffff;

  // the first 2 bytes come from a and the last 2 bytes come from b
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);

  assert(r == 0x0000ffff);

  // the first 2 bytes come from b and the last 2 bytes come from a
  mask = 0xffff0000;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0xffff0000);

  // the first 4 bits come from b and the other bits all come from a
  mask = 0xf0000000;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0xf0000000);

  // the last 4 bits come from b and the other bits all come from a  
  mask = 0x0000000f;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0x0000000f);

  // the output should be b
  mask = 0xffffffff;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0xffffffff);

  // the output should be a
  mask = 0x00000000;
  r = merge_bits(a, b, mask);
  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
  assert(r == 0x00000000);

  return 0;
}
