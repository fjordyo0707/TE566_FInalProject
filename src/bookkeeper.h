#ifndef BOOKKEEPER_H
#define BOOKKEEPER_H

#include "employee_list.h"
#include "vendor_list.h"
#include "customer_list.h"
#include "income_statement.h"
#include "balance_sheet.h"
#include "po_history.h"
#include "invoice_history.h"
#include "inventory_list.h"
#include "payroll_history.h"
#include "book_config.h"

#include "employee.h"
#include "customer.h"
#include "vendor.h"
#include "payroll.h"
#include "inventory.h"
#include "po.h"

#include <iostream>

using std::cout;
using std::endl;


class bookkeeper {
    public:
        void List_Employee();
        void Add_Employee(employee e);
        void List_Customer();
        void Add_Customer(customer c);
        void List_Vendor();
        void Add_Vendor(vendor v);
        void Pay_Employee(int i);
        void Balance_Sheet();
        void Income_Statement();
        void Payroll();
        void Inventory();
        void Create_Invoice(invoice i);
        void Invoice_History();
        void Create_PO(po p);
        void PO_History();

        void Add_Inventory(inventory i);



    private:
        employee_list my_employee_list;
        customer_list my_customer_list;
        vendor_list my_vendor_list;
        income_statement my_income_statement;
        balance_sheet my_balance_sheet;
        payroll_history my_payroll_history;
        inventory_list my_inventory_list;
        invoice_history my_invoice_history;
        po_history my_po_history;

};

void bookkeeper::Add_Employee(employee e) {
    my_employee_list.add_employee(e);
}

void bookkeeper::List_Employee() {
    std::cout<<my_employee_list<<std::endl;
}

void bookkeeper::Add_Customer(customer c) {
    my_customer_list.add_customer(c);
}

void bookkeeper::List_Customer() {
    std::cout<<my_customer_list<<std::endl;
}

void bookkeeper::Add_Vendor(vendor v) {
    my_vendor_list.add_vendor(v);
}

void bookkeeper::List_Vendor() {
    std::cout<<my_vendor_list<<std::endl;
}

void bookkeeper::Balance_Sheet() {
    cout<<my_balance_sheet<<endl;
}

void bookkeeper::Income_Statement() {
    cout<<my_income_statement<<endl;
}

void bookkeeper::Pay_Employee(int i) {
    employee p_e = my_employee_list.get(i);
    float salary = p_e.get_salary();
    float pay_witholding = salary * SALARY_WITHOLDING_RATIO;
    float pay = salary * (1.0 - SALARY_WITHOLDING_RATIO);

    my_balance_sheet.cash -= salary;

    my_income_statement.payroll += pay;
    my_income_statement.payroll_witholding += pay_witholding;

    payroll employee_pay("5/7/2022", p_e.get_first_name(), pay, pay_witholding);
    my_payroll_history.add_payroll(employee_pay);
}

void bookkeeper::Payroll() {
    cout<<my_payroll_history<<endl;
}

void bookkeeper::Inventory() {
    cout<<my_inventory_list<<endl;
}

void bookkeeper::Add_Inventory(inventory i) {
    my_inventory_list.add_inventory(i);
}

void bookkeeper::Create_Invoice(invoice i) {
    my_invoice_history.add_invoice(i);
    my_inventory_list.decrease_quantity(i.get_quantity());
    my_balance_sheet.add_accounts_receivable(i.total_pay());
    my_income_statement.add_sales(i.total_pay());
    my_income_statement.add_cogs(i.get_quantity() * my_inventory_list.get_unit_price());
}

void bookkeeper::Invoice_History() {
    cout<<my_invoice_history<<endl;
}

void bookkeeper::Create_PO(po p) {
    my_po_history.add_po(p);
    my_balance_sheet.add_accounts_payable(p.total_pay());
    my_balance_sheet.add_inventory(p.total_pay());
    my_inventory_list.decrease_quantity_idx(p.get_quantity(), p.get_vendor_idx());

}

void bookkeeper::PO_History() {
    cout << my_po_history << endl;
}

#endif