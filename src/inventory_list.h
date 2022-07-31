#ifndef INVENTORY_INFO_H
#define INVENTORY_INFO_H

#include <string>
#include <iostream>
#include <vector>
#include "inventory.h"
using std::cout;
using std::endl;
using std::vector;

class inventory_list {
    public:
    friend std::ostream & operator << (std:: ostream& out, const inventory_list& I_L) {
            out << std::setw(15) << "No."
                << std::setw(15) << "Part"
                << std::setw(15) << "Price/Unit"
                << std::setw(15) << "Quantity"
                << std::setw(15) << "Value"
                << std::endl;
            
            out << "===============================================";
            out << "===============================================";
            out << std::endl;
            
            for(int i = 0 ; i < I_L.my_inventory_list.size(); ++i) {
                out<<std::setw(15)<<i<<I_L.my_inventory_list[i]<<std::endl;
            }

            return out;
        }
    
    void add_inventory(inventory inv) {
        my_inventory_list.emplace_back(inv);
    } 


    private:
    vector<inventory> my_inventory_list;
    
};

#endif