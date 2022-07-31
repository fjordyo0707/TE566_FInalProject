#ifndef CUSTOMER_LIST_H
#define CUSTOMER_LIST_H

#include<iostream>
#include"customer.h"
#include <vector>

class customer_list {
    public:
        friend std::ostream & operator << (std:: ostream& out, const customer_list& C_L) {
            out << std::setw(15) << "No."
                << std::setw(15) << "Company Name" 
                << std::setw(15) << "First Name" 
                << std::setw(15) << "Last Name"
                << std::setw(15) << "Address"
                << std::setw(10)  << "City" 
                << std::setw(10) << "State" 
                << std::setw(10) << "Zip Code" 
                << std::setw(10) << "Price"
                << std::endl;
            
            out << "===============================================";
            out << "===============================================";
            out << "===============================================";
            out << std::endl;
            
            for(int i = 0 ; i < C_L.customer_list_.size(); ++i) {
                out<<std::setw(15)<<i<<C_L.customer_list_[i]<<std::endl;
            }

            return out;
        }

        void add_customer(customer c) {
            customer_list_.emplace_back(c);
        }

    private:
        std::vector<customer> customer_list_;
    
};

#endif