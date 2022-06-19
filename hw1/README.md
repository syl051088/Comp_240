# Merging bits from two input integers

## Notes

- Makefile is provided;
- starting point for code files is provided
 
## What should work in the terminal

Commands that should work to run this problem:


    make clean
    make 

    ./merge_bits

## Problem Description
### Merge bits from two values according to a mask

You goal is to write a function called `merge_bits` whose declaration looks like this in
your `merge_bits.c` file:

<pre>
unsigned int merge_bits(unsigned int a, unsigned int b, unsigned int mask) {
</pre>

The values in the three parameters are as follows

<pre>
unsigned int a;    // value to merge in non-masked bits
unsigned int b;    // value to merge in masked bits
unsigned int mask; // 1 where bits from b should be selected; 0 where from a.
</pre>

This `merge_bits` function should return the result of creating a new unsigned int that contains the result of taking bits from a in the bit positions of the mask that are zero, and bits from b in the bit positions of the mask that are one. (See the results below for examples of what this means.)

**Important Restriction**: Your function must only use the bitwise operations. It can be done using a combination of some number of the '^' and '&' operations. It can also be done using a combination of &, |, and ~, which might be a bit easier for you to devise. The function will be very few lines (even 1, but this is extreme and not necessary).

The following is the starting point for your main program function in your `test.c` file:


	int main() {

	  unsigned int mask = 0xff;
	  unsigned int a = 0xabcd;
	  unsigned int b = 0x2234;
	  unsigned int r;

	  printf("   a    \t   b    \t  mask   \t result \n");

	  // some example tests
	  r = merge_bits(a, b, mask);
	  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
	  // instead of or in addition to printing, you should use assertions,
	  // like this below. If the output of your program will be large, just
	  // keep the asserts and comment the prints.
	  // note that  <assert.h>  must be included at the top of the file
	  assert(r == 0xab34);

	  mask = 0xff00;
	  r = merge_bits(a, b, mask);
	  printf("%.8x\t%.8x\t%.8x\t%.8x\n", a, b, mask, r);
	  assert(r == 0x22cd);

	  return 0;
	}


By convention, this is primarily designed to test your new *merge_bits* function.

Initially, if you make and run this code as given above, the first assert will cause it to fail.

When you have a proper *merge_bits* function working, the result of running your merge_bits program using this main should look like this:

<pre>
   a    	   b    	  mask   	 result 
0000abcd	00002234	000000ff	0000ab34
0000abcd	00002234	0000ff00	000022cd
</pre>

**Most important task:** Then proceed to add more test cases so that you thoroughly test whether your *merge_bits* function is working under all possible circumstances, especially edge cases.


# COMP 240 Homework Requirements

## Good Code Practice expected for every assignment

One goal we have for computer science majors or other students who may develop
code at some point in their lives is that they learn and practice good coding techniques.
In this class, we do this by setting expectations for coding that mimic how you would
write code in real life, as you try to make certain that it is correct, and that other developers who look at your code later will understand it because it is readable and has useful explanations of what it contains and how it works. It is essential that you develop habits of mind when coding that you use consistently for every task you take on.

To instill this habit of mind in your work, I insist that all homework code have the following properties:

- Code is indented properly.

- Code is broken into small functions that make sense as a separate entity.

- Code contains a main() that tests each function **thoroughly and exhaustively**. For this course, place that in a file called `test.c`  **Thorough and exhaustive** testing is harder than you might imagine but *really important*.  You must design tests of a function that try all ranges and extremes of possible values to ensure that it works in all possible cases.  Think this part through very carefully and explain the tests in comments.  Use asserts to help you check results instead of printing large amounts of output.  Having asserts in your code instead of print statements means that you can avoid the manual hassle of looking through large amounts of printout to check your code for accuracy. (In certain cases, printing is also useful; make a judgement for the code you are asked to test, and in some cases use both prints and asserts.)

- main() returns 0 when it completes successfully.

- There is a header comment in every file with your name in it and a short description. Do this- points off if you don't. Why? Because members of all good coding teams author their work in the header file.

- There is a header comment for **every function** describing its input parameters and what it returns.

- There are comments in main explaining the tests that you are running on each function.

- There are comments within functions when necessary to explain it. Not every line needs to be commented.

- Use the makefile provided with each problem unless you are asked to write your own makefile for practice.


