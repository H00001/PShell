#this is a makefile file
pshell:
	$(CC) *.c ./internal/*.c ./util/*.c -o pshell -std=gnu11
debug:
	$(CC) -g *.c ./internal/*.c ./util/*.c -o pshell -std=gnu11
clean:
	rm -r out *.h.gch *.o
install:
	cp pshell /bin
