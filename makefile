#this is a makefile file
pshell:
	$(CC) *.c ./internal/*.c ./util/*.c -o pshell -std=gnu11
debug:
	$(CC) -g *.c ./internal/*.c ./util/*.c -o pshell -std=gnu11
install:
	cp ./pshell /bin/pshell
clean:
	rm -r out *.h.gch *.o
