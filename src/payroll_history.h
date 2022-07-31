#ifndef PAYROLL_HISTORY_H
#define PAYROLL_HISTORY_H
#include <string>
#include <iostream>
#include <vector>
#include "payroll.h"
using std::cout;
using std::endl;
using std::vector;

class payroll_history {
    public:

    friend std::ostream & operator << (std:: ostream& out, const payroll_history& P_H) {
            out << std::setw(15) << "No."
                << std::setw(15) << "Date Paid"
                << std::setw(15) << "Employee"
                << std::setw(15) << "Dispursement"
                << std::setw(15) << "Witholding"
                << std::endl;
            
            out << "===============================================";
            out << "===============================================";
            out << std::endl;
            
            for(int i = 0 ; i < P_H.my_payroll_history.size(); ++i) {
                out<<std::setw(15)<<i<<P_H.my_payroll_history[i]<<std::endl;
            }

            return out;
        }
    
    void add_payroll(payroll pay) {
        my_payroll_history.emplace_back(pay);
    } 


    private:
    vector<payroll> my_payroll_history;
    
};

#endif