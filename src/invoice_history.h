#ifndef INVOICE_HISTORY_H
#define INVOICE_HISTORY_H

#include <string>
#include <iostream>
#include <vector>
#include "invoice.h"
using std::endl;
using std::vector;

class invoice_history
{
public:
    friend std::ostream &operator<<(std::ostream &out, const invoice_history &I_H)
    {
        out << std::setw(15) << "No."
            << std::setw(15) << "Date"
            << std::setw(15) << "Customer"
            << std::setw(15) << "Quantity"
            << std::setw(15) << "Price/Part"
            << std::setw(15) << "Total"
            << std::endl;

        out << "===============================================";
        out << "===============================================";
        out << std::endl;

        for (int i = 0; i < I_H.my_invoice_history.size(); ++i)
        {
            out << std::setw(15) << i << I_H.my_invoice_history[i] << std::endl;
        }

        return out;
    }

    void add_invoice(invoice inv)
    {
        my_invoice_history.emplace_back(inv);
    }

private:
    vector<invoice> my_invoice_history;
};

#endif