#include "Atom.h"

class Litteral{
private:
    Atom atom;
    bool negative;
public:
    Litteral(Atom atome);
    Litteral (int number, bool value);
    bool isNegative();
    void setNegative(bool negative);
}