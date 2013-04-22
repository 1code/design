#include "Pizza.h"

void Pizza::dough(const string& dough) {
    dough_ = dough;
}

void Pizza::sauce(const string& sauce) {
    sauce_ = sauce;
}

void Pizza::topping(const string& topping) {
    topping_ = topping;
}

void Pizza::open() const {
    cout << "Pizza with " << dough_ << " dough, " << sauce_ << " sauce and "
        << topping_ << " topping. Mmm." << endl;
}
