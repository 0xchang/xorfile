xorfile:arguments.o xor.o main.o
	@gcc -o bin/xorfile obj/main.o obj/arguments.o obj/xor.o -O2
	@echo "The out file is bin/xorfile"
main.o:
	@gcc src/main.c -c -o obj/main.o
arguments.o:
	@gcc src/arguments.c -c -o obj/arguments.o
xor.o:
	@gcc src/xor.c -c -o obj/xor.o
clean:
	rm -rf obj/*
clean_all:
	rm -rf bin/* obj/*
