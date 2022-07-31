#include "bookkeeper.h"

#include<iostream>
using namespace std;

int main() {
    cout<<"Start Bookkeeper"<<endl<<endl;

    bookkeeper m_b;

    employee e1("john", "smith", "123 front st", "SF", "CA", "12345", "123456789", "0", 15000.0);
    employee e2("James", "John", "123Ffront st", "CLE", "OH", "44121", "998755441", "0", 5000.0);

    customer c1("Simth Co.", "", "", "", "", "", "", 2.5);
    customer c2("Toy r Us", "", "", "", "", "", "", 2.5);
    customer c3("Online Hobbies", "", "", "", "", "", "", 2.5);

    
    vendor v1("Tires R Us", "Tires", "", "", "", "", 0.02);
    vendor v2("Mr Mixer", "Mixer", "", "", "", "", 0.05);
    vendor v3("Casting Man", "Body Casting", "", "", "", "", 0.1);
    vendor v4("Casting for U", "Cab Casting", "", "", "", "", 0.05);
    vendor v5("Acme Plastics", "Windshield", "", "", "", "", 0.1);
    vendor v6("Micro Axles", "Axles", "", "", "", "", 0.01);
    vendor v7("All Rims", "Rims", "", "", "", "", 0.01);
    vendor v8("Screw it", "Screw", "", "", "", "", 0.02);
    vendor v9("Many Boxes", "Box", "", "", "", "", 0.05);
    vendor v10("None", "Labor", "", "", "", "", 0.1);
    vendor v11("Mast Packing", "Master Pack", "", "", "", "", 0.02);

    inventory i1("Axles", 0.01, 33000);
    inventory i2("Screw", 0.02, 48250);
    inventory i3("Cab Casting", 0.05, 28250);
    inventory i4("Rims", 0.01, 6000);
    inventory i5("Mixer", 0.05, 48250);
    inventory i6("Labor", 0.1, 48000);
    inventory i7("Tires", 0.02, 6000);
    inventory i8("Master Pack", 0.02, 48250);
    inventory i9("Body Casting", 0.1, 48250);
    inventory i10("Windshield", 0.1, 48250);
    inventory i11("Box", 0.05, 48250);

    m_b.Add_Employee(e1);
    m_b.Add_Employee(e2);
    m_b.Add_Customer(c1);
    m_b.Add_Customer(c2);
    m_b.Add_Customer(c3);
    m_b.Add_Vendor(v1);
    m_b.Add_Vendor(v2);
    m_b.Add_Vendor(v3);
    m_b.Add_Vendor(v4);
    m_b.Add_Vendor(v5);
    m_b.Add_Vendor(v6);
    m_b.Add_Vendor(v7);
    m_b.Add_Vendor(v8);
    m_b.Add_Vendor(v9);
    m_b.Add_Vendor(v10);
    m_b.Add_Vendor(v11);

    m_b.Add_Inventory(i1);
    m_b.Add_Inventory(i2);
    m_b.Add_Inventory(i3);
    m_b.Add_Inventory(i4);
    m_b.Add_Inventory(i5);
    m_b.Add_Inventory(i6);
    m_b.Add_Inventory(i7);
    m_b.Add_Inventory(i8);
    m_b.Add_Inventory(i9);
    m_b.Add_Inventory(i10);
    m_b.Add_Inventory(i11);

    m_b.List_Employee();
    m_b.List_Customer();
    m_b.List_Vendor();
    m_b.Balance_Sheet();
    m_b.Income_Statement();
    m_b.Pay_Employee(0);
    m_b.Balance_Sheet();
    m_b.Income_Statement();
    m_b.Payroll();
    m_b.Inventory();

    cout<<"End Bookkeeper"<<endl;
    
    return 0;
}