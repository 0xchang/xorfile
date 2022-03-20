xorfile:arguments.o xor.o main.o
	gcc -o xorfile main.o getopt.o xor.o -O2
	rm -rf *.o
	@echo "The out file is xorfile"
main.o:
	@gcc main.c -c -o main.o
arguments.o:
	@gcc getopt.c -c -o getopt.o
xor.o:
	@gcc xor.c -c -o xor.o
