#ifndef PO_H
#define PO_H

#include <iostream>
#include <string>

using std::string;

class po {
    public:
    po(string date,
       string supplier,
       string part,
       int quantity,
       float price_part,
       int vendor_idx):
       date_(date), 
       supplier_(supplier),
       part_(part),
       quantity_(quantity),
       price_part_(price_part),
       vendor_idx_(vendor_idx)
    {}

    friend std::ostream & operator << (std:: ostream& out, const po& P) {
        return out << std::setw(15) << P.date_ 
                   << std::setw(15) << P.supplier_
                   << std::setw(15) << P.part_
                   << std::setw(15) << P.quantity_
                   << std::setw(15) << P.price_part_
                   << std::setw(15) << P.total_pay();
    }

    float total_pay() const {
        return price_part_ * (float) quantity_;
    }

    int get_quantity() const {
        return quantity_;
    }

    int get_vendor_idx() const {
        return vendor_idx_;
    }

    private:
    string date_;
    string supplier_;
    string part_;
    int quantity_;
    float price_part_;
    int vendor_idx_;
    
};

#endif