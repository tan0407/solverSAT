SHELL=bash
GCC=g++
LDFLAGS= -lm
CFLAGS = -Wall -Wno-sign-compare -g
EXEC = solverSAT

all: $(EXEC)

clean:
	@rm -rf *.o


solverSAT:  cnfReader.o algorithms.o solverSAT.o
	@$(GCC) -o $@ $^ $(LDFLAGS)

algorithms.o:	./src/algorithms.cc
	@$(GCC) -o $@ -c $< $(CFLAGS)

cnfReader.o : 	./src/cnfReader.cc 
	@$(GCC) -o $@ -c $< $(CFLAGS)

solverSAT.o : 	./src/solverSAT.cc
	@$(GCC) -o $@ -c $< $(CFLAGS)
