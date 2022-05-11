#include "Pack.h"
using namespace sdds;

Pack::Pack(const char* Content, int Size, int unitSize, int NumberOfUnits):Container(Content, Size* unitSize, unitSize* NumberOfUnits) {

    this->Size = Size;
    this->unitSize = unitSize;
    this->NumberOfUnits = NumberOfUnits;
}

int Pack::operator += (int units) {

    int result = Container::operator+=(units * unitSize) / unitSize;
    this->NumberOfUnits += result;
    return result;
}


int Pack::operator -= (int units) {

    int result = Container::operator-=(units * unitSize) / unitSize;
    this->NumberOfUnits -= result;
    return result;
}


int Pack::unit() {
    return unitSize;
}


int Pack::noOfUnits() {
    return NumberOfUnits;
}


int Pack::size() {
    return Size;
}


void Pack::clear(int packSize, int unitSize, const char* content) {

    if (unitSize > 0) {
        Container::clear(packSize * unitSize, content);
        this->NumberOfUnits = 0;
        this->unitSize = unitSize;
    }
}


ostream& Pack::print(ostream& out) {
    
    Container::print(out);

    if (valid()) {
        out << ", " << NumberOfUnits << " in a pack of " << Size;
    }
    return out;
}


istream& Pack::read(istream& in) {

    char ch;
    int units;

    if (!valid()) {
        cout << "Broken Container, adding aborted! Press <ENTER> to continue....";       
        ch = getchar();
    }
    else if (NumberOfUnits == Size) {
        in.ignore();
        cout << "Pack is full!, press <ENTER> to continue...";
        ch = getchar();
    }
    else {
        bool validValue = false;
        cout << "Add to ";
        print(cout);

        int maxVal = Size - NumberOfUnits;
        cout << endl << "> ";
        while (!validValue) {

            in >> units;
            if (units > Size) {
                cout << "Invalid Integer, retry: ";
            }
            else if (units < 1 || units > maxVal) {
                cout << "Value out of range [1<=val<=" << maxVal << "]:";
            }
            else {
                validValue = true;
            }
        }
        units = (*this += units);
        cout << "Added " << units << endl;
    }
    return in;
}