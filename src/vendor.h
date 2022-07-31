#ifndef VENDOR_H
#define VENDOR_H

#include<string>
#include <iomanip>

class vendor {
    public:
    vendor(std::string company_name,
             std::string part, 
             std::string address, 
             std::string city, 
             std::string state,
             std::string zipcode,
             float price_per_unit) 
             :company_name_(company_name), part_(part), address_(address), 
              city_(city), state_(state), zipcode_(zipcode), price_per_unit_(price_per_unit)
    {}
    
    friend std::ostream & operator << (std:: ostream& out, const vendor& V) {
        return out << std::setw(15) << V.company_name_ 
                   << std::setw(15) << V.part_
                   << std::setw(15) << V.price_per_unit_
                   << std::setw(15) << V.address_
                   << std::setw(15)  <<V.city_ 
                   << std::setw(15) << V.state_ 
                   << std::setw(15) << V.zipcode_;
    }

    private:
        std::string company_name_;
        std::string part_;
        std::string address_;
        std::string city_;
        std::string state_;
        std::string zipcode_;
        float price_per_unit_;
    
};

#endif