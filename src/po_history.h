#ifndef PO_HISTORY_H
#define PO_HISTORY_H

#include <string>
#include <iostream>
#include <vector>
#include "po.h"
using std::endl;
using std::vector;

class po_history {
    public:
    friend std::ostream &operator<<(std::ostream &out, const po_history &P_H)
    {
        out << std::setw(15) << "No."
            << std::setw(15) << "Date"
            << std::setw(15) << "Supplier"
            << std::setw(15) << "Part"
            << std::setw(15) << "Quantity"
            << std::setw(15) << "Price/Part"
            << std::setw(15) << "Total"
            << std::endl;

        out << "=============================================";
        out << "=============================================";
        out << "=============================================";
        out << std::endl;

        for (int i = 0; i < P_H.my_po_history.size(); ++i)
        {
            out << std::setw(15) << i << P_H.my_po_history[i] << std::endl;
        }

        return out;
    }

    void add_po(po inv)
    {
        my_po_history.emplace_back(inv);
    }

private:
    vector<po> my_po_history;
    
};

#endif