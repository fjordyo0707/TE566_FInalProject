#ifndef BALANCE_SHEET_H
#define BALANCE_SHEET_H

#include <string>
#include <iomanip>
#include <iostream>

using std::setw;
using std::endl;

class balance_sheet {
    public:
    balance_sheet() {
        cash = 195397.5;
        account_receivable = 0;
        inventory = 26122.5;

        landbulding = 0;
        equpiment = 0;
        furniture = 0;

        account_payable = 0;
        notes_payable = 0;
        accruals = 0;
        mortgage = 0;

    }

    friend std::ostream & operator << (std:: ostream& out, const balance_sheet& B_S) {
        out <<"Balance Sheet"<<std::endl;
        out << setw(30)<<"Assets"<<setw(30)<<""<<setw(30)<<"Liabilities & Net Worth"<<setw(30)<<""<<endl;
        out << setw(30)<<"------" << setw(60) << "---------" << endl;
        out << setw(30)<<"Cash"<<setw(30)<<B_S.cash<<setw(30)<<"Account Payable"<<setw(30)<<B_S.account_payable<<endl;
        out << setw(30)<<"Account Receivable"<<setw(30)<<B_S.account_receivable<<setw(30)<<"Notes Payable"<<setw(30)<<B_S.notes_payable<<endl;
        out << setw(30)<<"Inventory"<<setw(30)<<B_S.inventory<<setw(30)<<"Accruals"<<setw(30)<<B_S.accruals<<endl;
        out << setw(30)<<"Total Current Assets"<<setw(30)<<B_S.total_current_assets()<<setw(30)<<"Total Current Liabilities"<<setw(30)<<B_S.total_current_liabilities()<<endl;
        out << setw(60)<<"---------------------------------------------------------" << setw(60) << "---------------------------------------------------------" << endl;
        out << setw(30)<<"Land/Building"<<setw(30)<<B_S.landbulding<<setw(30)<<"Mortgage"<<setw(30)<<B_S.mortgage<<endl;
        out << setw(30)<<"Equipment"<<setw(30)<<B_S.equpiment<<setw(30)<<"Total Long Term Debt"<<setw(30)<<B_S.total_long_term_debt()<<endl;
        out << setw(30)<<"Furniture"<<setw(30)<<B_S.furniture<<endl;
        out << setw(30)<<"Total Fixed Assets"<<setw(30)<<B_S.total_fixed_assets()<<setw(30)<<"Total Liabilities"<<setw(30)<<B_S.total_liabilities()<<endl;
        out << setw(60)<<"---------------------------------------------------------" << setw(60) << "---------------------------------------------------------" << endl;
        out << setw(30)<<"Total Assets"<<setw(30)<<B_S.total_assets()<<setw(30)<<"Net Worth"<<setw(30)<<B_S.net_worth()<<endl;

        return out; 
    }


    float cash;
    float account_receivable;
    float inventory;

    float landbulding;
    float equpiment;
    float furniture;

    float account_payable;
    float notes_payable;
    float accruals;

    float mortgage;

    float total_current_assets() const {
        return cash + account_receivable + inventory;
    }

    float total_fixed_assets() const {
        return landbulding + equpiment + furniture; 
    }

    float total_assets() const {
        return total_current_assets() + total_fixed_assets();
    }

    float const total_current_liabilities() const {
        return account_payable + notes_payable + accruals;
    }

    float const total_long_term_debt() const {
        return mortgage;
    }

    float const total_liabilities() const {
        return total_current_liabilities() + total_long_term_debt();
    }

    float const net_worth() const {
        return total_assets() + total_liabilities();
    }

    void add_accounts_receivable(float pay) {
        account_receivable += pay;
    }

    void add_accounts_payable(float pay) {
        account_payable += pay;
    }

    void add_inventory(float pay) {
        inventory += pay;
    }
    
};

#endif