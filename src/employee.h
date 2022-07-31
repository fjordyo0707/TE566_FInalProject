#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<iostream>
#include<iomanip>

class employee {
    public:
    employee(std::string first_name, 
             std::string last_name, 
             std::string address, 
             std::string city, 
             std::string state,
             std::string zipcode,
             std::string ssn,
             std::string withholding, 
             float salary) : first_name_(first_name), last_name_(last_name), address_(address), 
                             city_(city), state_(state), zipcode_(zipcode), ssn_(ssn), withholding_(withholding),
                             salary_(salary)
    {}
    
    friend std::ostream & operator << (std:: ostream& out, const employee& E) {
        return out << std::setw(15) << E.first_name_ 
                   << std::setw(15) << E.last_name_ 
                   << std::setw(15) << E.address_ 
                   << std::setw(15) << E.city_ 
                   << std::setw(15) << E.state_ 
                   << std::setw(15) << E.ssn_ 
                   << std::setw(15) << E.withholding_
                   << std::setw(15) << E.salary_;
    }

    float get_salary() const {
        return salary_;
    }

    std::string get_first_name() const {
        return first_name_;
    }

    private:
        std::string first_name_;
        std::string last_name_;
        std::string address_;
        std::string city_;
        std::string state_;
        std::string zipcode_;
        std::string ssn_;
        std::string withholding_;
        float salary_;
};

#endif