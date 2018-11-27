SHELL=bash
GCC=g++
LDFLAGS= -lm
CFLAGS = -Wall -Wno-sign-compare
EXEC = solverSAT.exe

all: $(EXEC)

clean:
	@rm -rf *.o


solverSAT.exe:  Clause.o cnfReader.o solverSAT.o
	@$(GCC) -o $@ $^ $(LDFLAGS)

Clause.o:	./src/Clause.cc  
	@$(GCC) -o $@ -c $< $(CFLAGS)

cnfReader.o : 	./src/cnfReader.cc 
	@$(GCC) -o $@ -c $< $(CFLAGS)

solverSAT.o : 	./src/solverSAT.cc
	@$(GCC) -o $@ -c $< $(CFLAGS)