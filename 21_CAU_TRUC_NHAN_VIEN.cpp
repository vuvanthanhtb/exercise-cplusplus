// CẤU TRÚC NHÂN VIÊN
#include <iostream>

using namespace std;

struct Employee {
    string employee_code = "00001";
    string full_nname;
    string gender;
    string date_of_birth;
    string address;
    string tax;
    string contract_date;

    void display_info() {
        cout << employee_code << " " << full_nname << " " << gender << " " << date_of_birth << " " << address << " " << tax << " " << contract_date << endl;
    }
};


int main() {
    Employee employee;
    getline(cin, employee.full_nname);
    getline(cin, employee.gender);
    getline(cin, employee.date_of_birth);
    getline(cin, employee.address);
    getline(cin, employee.tax);
    getline(cin, employee.contract_date);
    employee.display_info();
    return 0;
}