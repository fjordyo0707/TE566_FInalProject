#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H
#include "employee.h"
#include <vector>
#include <iostream>

class employee_list {
    public:
        friend std::ostream & operator << (std:: ostream& out, const employee_list& E_L) {
            out << std::setw(15) << "No."
                << std::setw(15) << "First Name"
                << std::setw(15) << "Last Name"
                << std::setw(15) << "Address"
                << std::setw(15) << "City"
                << std::setw(15) << "State" 
                << std::setw(15) << "SSN" 
                << std::setw(15) << "Withholding"
                << std::setw(15) << "Salary"
                << std::endl;
            
            out << "===============================================";
            out << "===============================================";
            out << "===============================================";
            out << std::endl;
            
            for(int i = 0 ; i < E_L.employee_list_.size(); ++i) {
                out<<std::setw(15)<<i<<E_L.employee_list_[i]<<std::endl;
            }

            return out;
        }

        int size() {
            return employee_list_.size();
        }

        employee get(int i) {
                return employee_list_[i];
        }

        void set(int i, employee e) {
            if( i < this->size())
                employee_list_[i] = e; 
            else
                std::cout<<"idx exceed range"<<std::endl;
        }

        void add_employee(employee e) {
            employee_list_.emplace_back(e);
        }

    private:
        std::vector<employee> employee_list_;
};

#endif