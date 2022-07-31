#ifndef INVENTORY_INFO_H
#define INVENTORY_INFO_H

#include <string>
#include <iostream>
#include <vector>
#include "inventory.h"
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


        out << "===============================================";
        out << "===============================================";
        out << std::endl;
        out << std::setw(15) << "Total"
            << std::setw(30) << "COG/Unit"
            << std::setw(30) << "Total Built Units"
            << endl;
        out << setw(15) << I_L.get_total_value()
            << setw(30) << I_L.get_unit_price() 
            << setw(30) <<  I_L.complete_unit()
            << endl;;

        return out;
    }
    
    void add_inventory(inventory inv) {
        my_inventory_list.emplace_back(inv);
    }

    float get_total_value() const {
        int ret = 0;
        for(const auto & inv: my_inventory_list) {
            ret += inv.value();
        }
        return ret;
    }

    float get_unit_price() const {
        float sum = 0;
        for(const auto & inv: my_inventory_list) {
            sum += inv.price();
        }
        return sum;
    }

    int complete_unit() const {
        int smallest = my_inventory_list.front().quantity();
        for(const auto & inv: my_inventory_list) {
            if(inv.quantity() < smallest) {
                smallest = inv.quantity();
            }
        }
        return smallest;
    }

    void decrease_quantity(int n) {
        for(auto& inv: my_inventory_list) {
            inv.set_quantity(inv.quantity() - n);
        }
    }
    void decrease_quantity_idx(int n, int idx) {
        int new_q = my_inventory_list[idx].quantity() - n;
        my_inventory_list[idx].set_quantity(new_q);
    }


    private:
    vector<inventory> my_inventory_list;
    
};

#endif