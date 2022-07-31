#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>

using std::string;

class invoice {
    public:
    invoice(string date,
            string customer_,
            int quantity,
            float price_part):
            date_ (date), 
            customer_(customer_),
            quantity_(quantity),
            price_part_(price_part)
    {}

    friend std::ostream & operator << (std:: ostream& out, const invoice& I) {
        return out << std::setw(15) << I.date_ 
                   << std::setw(15) << I.customer_
                   << std::setw(15) << I.quantity_
                   << std::setw(15) << I.price_part_
                   << std::setw(15) << I.total_pay();
    }

    float total_pay() const {
        return price_part_ * (float) quantity_;
    }

    int get_quantity() const {
        return quantity_;
    }

    private:
    string date_;
    string customer_;
    int quantity_;
    float price_part_;
    
};

#endif