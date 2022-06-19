/*
 *  merge_bits.c
 *
 * Author: Joseph Shao
 */

/*
 * Return the result of creating a new unsigned int that contains the
 * result of taking bits from a in the bit positions of the mask that
 * are zero, and bits from b in the bit positions of the mask that are one.
 *
 * Parameters:
 *  unsigned int a;    // value to merge in non-masked bits
 *  unsigned int b;    // value to merge in masked bits
 *  unsigned int mask; // 1 where bits from b should be selected; 0 where from a.
 */
unsigned int merge_bits(unsigned int a, unsigned int b, unsigned int mask)
{
	return (mask & b) | (~mask & a);
}
