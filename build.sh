g++ -o algorithms.o -c ./src/algorithms.cc -Wall -Wno-sign-compare &&
g++ -o cnfReader.o -c ./src/cnfReader.cc -Wall -Wno-sign-compare &&
g++ -o solverSAT.o -c ./src/solverSAT.cc -Wall -Wno-sign-compare &&
g++ -o solverSAT algorithms.o cnfReader.o solverSAT.o &&
rm -rf *.o &&
echo "Build successful"