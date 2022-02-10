all: testCopy

testCopy: copy.o testCopy.c
	gcc build/copy.o testCopy.c -o build/testCopy

copy.o: copy.c
	gcc copy.c -c -o build/copy.o

clean:
	rm build/copy.o build/testCopy
