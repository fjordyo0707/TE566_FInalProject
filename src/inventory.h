#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <iostream>
using std::endl;
using std::string;

class inventory {
    public:
    inventory(string part,
              float price_per_unit,
              int quantity):
              part_(part), 
              price_per_unit_(price_per_unit),
              quantity_(quantity)
    {}
    friend std::ostream & operator << (std:: ostream& out, const inventory& I) {
        return out << std::setw(15) << I.part_ 
                   << std::setw(15) << I.price_per_unit_
                   << std::setw(15) << I.quantity_
                   << std::setw(15) << I.value();
    }
    float value() const {
        return price_per_unit_ * (float) quantity_;
    }
    private:
    string part_;
    float price_per_unit_;
    int quantity_;
};

#endif