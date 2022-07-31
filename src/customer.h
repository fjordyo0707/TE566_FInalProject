#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<string>
#include <iomanip>

class customer {
    public:
    customer(std::string company_name,
             std::string first_name, 
             std::string last_name, 
             std::string address, 
             std::string city, 
             std::string state,
             std::string zipcode,
             float price) : company_name_(company_name), first_name_(first_name), last_name_(last_name),
                            address_(address), city_(city), state_(state), zipcode_(zipcode), price_(price)
    {}
    
    friend std::ostream & operator << (std:: ostream& out, const customer& C) {
        return out << std::setw(15) << C.company_name_ 
                   << std::setw(15) << C.first_name_ 
                   << std::setw(15) << C.last_name_ 
                   << std::setw(15) << C.address_
                   << std::setw(15)  << C.city_ 
                   << std::setw(15) << C.state_ 
                   << std::setw(15) << C.zipcode_ 
                   << std::setw(10) << C.price_;
    }

    private:
        std::string company_name_;
        std::string first_name_;
        std::string last_name_;
        std::string address_;
        std::string city_;
        std::string state_;
        std::string zipcode_;
        float price_;
    
};

#endif