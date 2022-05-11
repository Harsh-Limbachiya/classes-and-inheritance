#ifndef PACK_H
#define PACK_H

#include "Container.h"
using namespace sdds;

namespace sdds {
    class Pack : public Container {
    private:
        int unitSize;
        int Size;
        int NumberOfUnits;

    public:
        Pack(const char* Content, int Size, int unitSize = 330, int NumberOfUnits = 0);
        int operator += (int units);
        int operator -= (int units);
        int unit();
        int noOfUnits();
        int size();
        void clear(int packSize, int unitSize, const char* content);
        ostream& print(ostream& out);
        istream& read(istream& in);

        friend ostream& operator << (ostream& out, Pack& P) {
            return P.print(out);
        }

        friend istream& operator >> (istream& in, Pack& P) {
            return P.read(in);
        }
    };
}
#endif