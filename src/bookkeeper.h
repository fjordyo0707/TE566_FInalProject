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

#include "employee.h"
#include "customer.h"

#include <iostream>


class bookkeeper {
    public:
        void List_Employee();
        void Add_Employee(employee e);
        void List_Customer();
        void Add_Customer(customer c);


    private:
        employee_list my_employee_list;
        customer_list my_customer_list;
    
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

#endif