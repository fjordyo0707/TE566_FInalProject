#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H
#include "employee.h"
#include <vector>
#include <iostream>

class employee_list {
    public:
        friend std::ostream & operator << (std:: ostream& out, const employee_list& E_L) {
            out << std::setw(10) << "First Name"
                   << std::setw(10) << "Last Name"
                   << std::setw(15) << "Address"
                   << std::setw(10) << "City"
                   << std::setw(10) << "State" 
                   << std::setw(15) << "SSN" 
                   << std::setw(15) << "Withholding"
                   << std::setw(10) << "Salary"
                   <<std::endl;
            
            for(const auto & E: E_L.employ_list_) {
                out<<E<<std::endl;
            }

            return out;
        }

        void add_employee(employee e) {
            employ_list_.emplace_back(e);
        }

    private:
        std::vector<employee> employ_list_;
};

#endif