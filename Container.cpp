#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"
using namespace sdds;


void Container::setEmpty() {
    validContainer = false;
}

int Container::capacity() {
    return Capacity;
}

int Container::volume() {
    return Content_volume;
}



Container::Container(const char* Content, int Capacity, int Content_volume) {
    if (Content == NULL || Content_volume > Capacity) {
        validContainer = false;
    }
    else {
        strcpy(this->Content, Content);
        this->Capacity = Capacity;
        this->Content_volume = Content_volume;
        validContainer = true;
    }
}


int Container::operator += (int value) {

    if (Content_volume + value <= Capacity) {
        Content_volume += value;
    }
    else {
        value = Capacity - Content_volume;
        Content_volume = Capacity;
    }

    return value;
}


int Container::operator -= (int value) {

    if (Content_volume - value >= 0) {
        Content_volume -= value;
    }
    else {
        value = Content_volume;
        Content_volume = 0;
    }
    return value;
}


bool Container::valid() {
    return validContainer;
}


void Container::clear(int Capacity, const char* Content) {

    if (Capacity >= 1 && Content != NULL && strlen(Content) >= 1) {
        this->Capacity = Capacity;
        strcpy(this->Content, Content);
        this->Content_volume = 0;
        validContainer = true;
    }
}



ostream& Container::print(ostream& out) {

    if (validContainer) {
        out << Content << ": (" << Content_volume << "cc/" << Capacity << ")";
    }
    else {
        out << "****: (**cc/***)";
    }
    return out;
}



istream& Container::read(istream& in) {

    char ch;
    int value;

    if (!validContainer) {
        cout << "Broken Container, adding aborted! Press <Enter> to continue....";
       ch = getchar();   
       in.ignore();
    }
    else {
        bool validValue = false;
        cout << "Add to ";
        print(cout);

        while (!validValue) {
            cout << endl << "> ";
            in >> value;

            if (value > Capacity) {
                cout << "Invalid Integer, retry:";
            }
            else if (value < 1 || value > 999) {
                cout << "Value out of range [1<=val<=999]:";
            }
            else {
                validValue = true;
            }
        }
        value = (*this += value);
        cout << "Added " << value << " CCs" << endl;
    }
    return in;
}