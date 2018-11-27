SHELL=bash
GCC=g++
LDFLAGS= -lm
CFLAGS = -Wall -Wno-sign-compare
EXEC = test_cnf.exe

all: $(EXEC)

clean:
	@rm -rf *.o

test_cnf.exe:  cnf_read.o test_cnf.o
	@$(GCC) -o $@ $^ $(LDFLAGS)

test_cnf.o:	./test/test_CNFReader.cc  
	@$(GCC) -o $@ -c $< $(CFLAGS)
cnf_read.o : 	./src/cnfReader.cc ./src/variables.cc ./src/headers/fileReader.h ./src/headers/Clause.h  ./src/headers/Litteral.h
	@$(GCC) -o $@ -c $< $(CFLAGS)