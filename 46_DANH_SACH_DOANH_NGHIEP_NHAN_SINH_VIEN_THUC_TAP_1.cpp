// DANH SÁCH DOANH NGHIỆP NHẬN SINH VIÊN THỰC TẬP - 1
#include <iostream>

using namespace std;

class Company {
private:
  string code;
  string name;
  int number_of_students;

public:
  Company();
  ~Company();

  friend istream &operator>>(istream &is, Company &company) {
    getline(is, company.code);
    getline(is, company.name);
    is >> company.number_of_students;
    is.ignore();
    return is;
  }

  friend ostream &operator<<(ostream &os, Company &company) {
    os << company.code << " " << company.name << " "
       << company.number_of_students << endl;
    return os;
  }

  int get_number_of_students() { return number_of_students; }

  static void show_companies(vector<Company> &companies) {
    for (int i = 0; i < companies.size() - 1; i++) {
      for (int j = i + 1; j < companies.size(); j++) {
        if (companies[i].get_number_of_students() <
            companies[j].get_number_of_students()) {
          Company temp = companies[i];
          companies[i] = companies[j];
          companies[j] = temp;
        }
      }
    }
    for (Company &company : companies) {
      cout << company;
    }
  }
};

Company::Company() {}

Company::~Company() {}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<Company> companies;

  while (n--) {
    Company company;
    cin >> company;
    companies.push_back(company);
  }

  Company::show_companies(companies);
  return 0;
}