xorfile:arguments.o xor.o main.o
	@gcc -o bin/xorfile main.o arguments.o xor.o -O1
	@rm -rf *.o
	@echo "The file is bin/xorfile"
main.o:
	@gcc src/main.c -c
arguments.o:
	@gcc src/arguments.c -c
xor.o:
	@gcc src/xor.c -c