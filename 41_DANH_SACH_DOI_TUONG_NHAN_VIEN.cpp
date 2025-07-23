// DANH SÁCH ĐỐI TƯỢNG NHÂN VIÊN
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
  string employee_code;
  string full_nname;
  string gender;
  string date_of_birth;
  string address;
  string tax;
  string contract_date;

public:
  Employee() {}

  void setCode(int i) {
    employee_code = "00" + string(i < 10 ? "00" : "0") + to_string(i);
  }

  friend istream &operator>>(istream &in, Employee &e) {
    getline(in, e.full_nname);
    getline(in, e.gender);
    getline(in, e.date_of_birth);
    getline(in, e.address);
    getline(in, e.tax);
    getline(in, e.contract_date);
    return in;
  }

  friend ostream &operator<<(ostream &out, const Employee &e) {
    out << e.employee_code << " " << e.full_nname << " " << e.gender << " "
        << e.date_of_birth << " " << e.address << " " << e.tax << " "
        << e.contract_date << endl;
    return out;
  }
};

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<Employee> employees(n);

  for (int i = 0; i < n; i++) {
    employees[i].setCode(i + 1);
    cin >> employees[i];
  }

  for (const auto &e : employees) {
    cout << e;
  }

  return 0;
}