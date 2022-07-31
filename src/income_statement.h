#ifndef INCOME_STATEMENT_H
#define INCOME_STATEMENT_H

using std::setw;
using std::endl;
class income_statement {
    public:

    income_statement() {
        sales = 52412.5;
        cogs = 0;
        
        payroll = 0;
        payroll_witholding = 0;
        bills = 1250;
        annual_expense = 8333.33;

        other_income = 0;
        income_taxes = 2379;
    }

    friend std::ostream & operator << (std:: ostream& out, const income_statement& I_S) {
        out <<"Icome Statement"<<std::endl;
        out << setw(30)<<"Sales"<<endl;
        out << setw(30)<<"--------------------------"<<endl;
        out << setw(30)<<"Sales"<<setw(30)<<I_S.sales<<endl;
        out << setw(30)<<"COGS"<<setw(30)<<I_S.cogs<<setw(30)<<endl;
        out << setw(30)<<"Gross "<<setw(30)<<I_S.gross_profit()<<setw(30)<<endl;
        out << setw(30)<<"--------------------------"<<endl;
        out << setw(30)<<"Payroll"<<setw(30)<<I_S.payroll<<endl;
        out << setw(30)<<"Payroll Witholding"<<setw(30)<<I_S.payroll_witholding<<endl;
        out << setw(30)<<"Bills"<<setw(30)<<I_S.bills<<endl;
        out << setw(30)<<"Annual Expenses"<<setw(30)<<I_S.annual_expense<<endl;
        out << setw(30)<<"Total Expenses"<<setw(30)<<I_S.total_expenses()<<endl;
        out << setw(30)<<"--------------------------"<<endl;
        out << setw(30)<<"Other Income"<<setw(30)<<I_S.other_income<<endl;
        out << setw(30)<<"Operaing Income"<<setw(30)<<I_S.operating_income()<<endl;
        out << setw(30)<<"Income Taxes"<<setw(30)<<I_S.income_taxes<<endl;
        out << setw(30)<<"Net Income"<<setw(30)<<I_S.net_income()<<endl;

        return out; 
    }

    float sales;
    float cogs;

    float payroll;
    float payroll_witholding;
    float bills;
    float annual_expense;

    float other_income;
    float income_taxes;

    float gross_profit() const {
        return sales - cogs;
    }

    float total_expenses() const {
        return payroll + bills + annual_expense;
    }

    float operating_income() const {
        return gross_profit() - total_expenses();
    }

    float net_income() const {
        return other_income + operating_income()  - income_taxes;
    }

    void add_sales(float s) {
        sales += s;
    }

    void add_cogs(float c) {
        cogs += c;
    }

    
};

#endif