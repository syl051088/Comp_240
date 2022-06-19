/*
    ASM Activity
    Libby Shoop

*/
#include <stdio.h>

// type definitions and constant declarations
#define M 5     // rows
#define N 6     // columns


typedef int Marray_t[M][N];

/*
 *  [][] version
 */
void set_diag(Marray_t A) {
    int i, j;
    j=0;
    for (i = 0; i < M; i++) {
      A[i][j] = 2;
      j++;
    }
	// set the last element for illustration
    A[M-1][N-1] = 99;
}

/*
 * pointer version
 */
void set_diag_p(Marray_t A) {         // M = 5, N = 6
    int i;
    int * Arow = &A[0][0];    //pointer declaration for start of row 0
    int * last = Arow + (M-1)*N + (N-1);   // final element in 2D array (pointer arithemtic handles the size of data type already, e.g. last++ moves the pointer by four bytes.
                                          // Thus, now last points to the first byte of the next element)
                                          // for illustration
    *last = 99;

    int * nextElement = Arow;
    for (i = 0; i < M; i++) {   // complete this part: i is each row
		// find pointer to next diagonal element using i and N
        // update the value pointed to by that element
        *nextElement = 2;
        nextElement = nextElement + N + 1;
    }
    // debug
	  printf ("set_diag_p: last element at M, N is: %d\n", *last);
}

void print_array(Marray_t A){
    int i, j;
    for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++) {
        printf("[%d][%d]  %d    ", i, j, A[i][j]);
      }
      printf("\n");
    }
}

void init_array(Marray_t A){
    int i, j;
    for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++) {
        A[i][j] = 0;
      }
    }
}

int main() {

  Marray_t matrix;
  init_array(matrix);
  printf("Zeroed elements of matrix:\n");
  print_array(matrix);
  printf("after setting diagonal elements  with set_diag():\n");
  set_diag(matrix);
  print_array(matrix);

  init_array(matrix);
  printf("Zeroed elements of matrix:\n");
  print_array(matrix);
  printf("after setting diagonal elements  with set_diag_p():\n");
  set_diag_p(matrix);
  print_array(matrix);


  return 0;
}