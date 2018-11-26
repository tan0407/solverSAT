using namespace std;
#include <string>
class Litteral{
private:
    bool value;
    int number;
    bool negative;
public:
    Litteral (int number,bool negative);
    bool isNegative();
    void setNegative(bool negative);
    bool getValue();
    void setValue(bool value);
    int getNumber();
    string toString();
};