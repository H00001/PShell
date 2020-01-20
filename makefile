#this is a makefile file
CC=gcc
pshell:
	$(CC) main.c -o pshell
install:
	cp ./pshell /bin/pshell
clean:
	rm -r out *.h.gch *.o
