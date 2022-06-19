/**
 * lea_decode.c
 *
 * Auther: Joseph Shao
 *
 * Translate lea commonds from Assembly code to C code
 */

/**
 * Takes in two long variables as input and return 36 times the second variable minus 72 times the first variable.
 *
 * @param x
 * @param y
 * @return long
 */
long decode(long x, long y)
{
    long t1 = 36 * y;
    long t2 = 72 * x;
    return t1 - t2;
}