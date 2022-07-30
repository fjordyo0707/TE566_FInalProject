#include "bookkeeper.h"
#include "employee.h"

#include<iostream>
using namespace std;

int main() {
    cout<<"Start Bookkeeper"<<endl<<endl;

    bookkeeper m_b;

    employee e1("john", "smith", "123 front st", "SF", "CA", "12345", "123456789", "0", 150000.0);
    employee e2("James", "John", "123Ffront st", "CLE", "OH", "44121", "998755441", "0", 50000.0);

    customer c1("Simth Co.", "", "", "", "", "", "", 2.5);
    customer c2("Toy r Us", "", "", "", "", "", "", 2.5);
    customer c3("Online Hobbies", "", "", "", "", "", "", 2.5);

    m_b.Add_Employee(e1);
    m_b.Add_Employee(e2);
    m_b.Add_Customer(c1);
    m_b.Add_Customer(c2);
    m_b.Add_Customer(c3);
    m_b.List_Employee();
    m_b.List_Customer();

    cout<<"End Bookkeeper"<<endl;
    
    return 0;
}