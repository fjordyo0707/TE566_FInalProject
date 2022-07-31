#ifndef VENDOR_LIST_H
#define VENDOR_LIST_H

#include<iostream>
#include"vendor.h"
#include <vector>

class vendor_list {
    public:
        friend std::ostream & operator << (std:: ostream& out, const vendor_list& V_L) {
            out << std::setw(15) << "No."
                << std::setw(15) << "Company Name" 
                << std::setw(15) << "Part"
                << std::setw(15) << "Price/Unit"
                << std::setw(15) << "Address"
                << std::setw(15)  << "City" 
                << std::setw(15) << "State" 
                << std::setw(15) << "Zip Code" 
                << std::endl;
            
            out << "===============================================";
            out << "===============================================";
            out << "===============================================";
            out << std::endl;
            
            for(int i = 0 ; i < V_L.vendor_list_.size(); ++i) {
                out<<std::setw(15)<<i<<V_L.vendor_list_[i]<<std::endl;
            }

            return out;
        }

        void add_vendor(vendor c) {
            vendor_list_.emplace_back(c);
        }

    private:
        std::vector<vendor> vendor_list_;
    
};

#endif