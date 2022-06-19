/*
 * Examples of casting and how it is manifested in the assembly code
 */

// A somewhat typical function, where data of different original types
// is being converted to the widest possible type, then added and returned.
//
// Here we are widening two's complement numbers
//
long addMult(long x, long y, int z)
{
  long t1 = x + y;
  long t2 = t1 * (long)z; // widening z
  return t2;
}

long addMult1(long x, long y, char z)
{
  long t1 = x + y;
  long t2 = t1 * (long)z; // widening z
  return t2;
}

unsigned long unsignedAddMult1(unsigned long x, unsigned long y, unsigned char z)
{
  unsigned long t1 = x + y;
  unsigned long t2 = t1 * (unsigned long)z; // widening z
  return t2;
}

unsigned long arith_u(unsigned char x, unsigned short y)
{
  unsigned long t1 = (unsigned long)x * 64;
  unsigned long t2 = (unsigned long)y + 42;

  return t1 + t2;
}

unsigned long arith_u1(unsigned char x, unsigned int y)
{
  unsigned long t1 = (unsigned long)x * 64;
  unsigned long t2 = (unsigned long)y + 42;

  return t1 + t2;
}