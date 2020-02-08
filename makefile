#this is a makefile file
pshell:
	$(CC) *.c -o pshell
install:
	cp ./pshell /bin/pshell
clean:
	rm -r out *.h.gch *.o
