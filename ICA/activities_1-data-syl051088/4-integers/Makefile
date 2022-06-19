#Data Activity 4

CC=gcc -std=c99

all: twos_comp problem2_32

twos_comp: test_tc.c binary_convert.c
	${CC} -o twos_comp test_tc.c binary_convert.c

problem2_32: problem2_32.c
	${CC} -o problem2_32 problem2_32.c

clean:
	rm -f twos_comp problem2_32