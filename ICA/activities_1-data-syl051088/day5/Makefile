# Makefile for Demo

CC=gcc -std=c99

# Note, if you do not specify a file as a dependency, make 
# will not automatically compile when the file changes. 
# You need to specify all the dependencies of bin_hex after
# The colon so changing them automatically triggers make to compile
typedef_cast: typedef_cast.c
	${CC} -o typedef_cast typedef_cast.c

clean:
	rm -f typedef_cast