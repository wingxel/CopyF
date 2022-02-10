INCLUDE = $(JAVA_HOME)

all: libcopy.so

libcopy.so: ../build/copy.o Copy.c
	gcc -fPIC -I $(INCLUDE)/include -I $(INCLUDE)/include/linux -shared -o ../build/libcopy.so ../build/copy.o Copy.c

clean:
	rm ../build/libcopy.so 
