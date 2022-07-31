#ifndef PAYROLL_H
#define PAYROLL_H
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class payroll {
    public:
    payroll(string date_paid,
            string employee_name,
            float dispursement,
            float witholding):
            date_paid_(date_paid), 
            employee_name_(employee_name),
            dispursement_(dispursement),
            witholding_(witholding)
    {}

    friend std::ostream & operator << (std:: ostream& out, const payroll& P) {
        return out << std::setw(15) << P.date_paid_ 
                   << std::setw(15) << P.employee_name_
                   << std::setw(15) << P.dispursement_
                   << std::setw(15) << P.witholding_;
    }
    
    private:
    string date_paid_;
    string employee_name_;
    float dispursement_;
    float witholding_;
};

#endif