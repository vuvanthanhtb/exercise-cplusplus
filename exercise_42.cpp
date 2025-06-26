// SẮP XẾP SINH VIÊN THEO LỚP
#include <iostream>

using namespace std;

class Student {
private:
  string code;
  string name;
  string classroom;
  string email;

public:
  Student();
  ~Student();

  friend istream &operator>>(istream &is, Student &student) {
    getline(is, student.code);
    getline(is, student.name);
    getline(is, student.classroom);
    getline(is, student.email);
    return is;
  }

  friend ostream &operator<<(ostream &os, const Student student) {
    os << student.code << " " << student.name << " " << student.classroom << " "
       << student.email << endl;
    return os;
  }

  string get_code() { return code; }

  string get_classroom() { return classroom; }
};

Student::Student() {}

Student::~Student() {}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<Student> students(n);

  for (int i = 0; i < n; i++) {
    cin >> students[i];
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (students[i].get_classroom() > students[j].get_classroom()) {
        Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
      } else if (students[i].get_classroom() == students[j].get_classroom()) {
        if (students[i].get_code() > students[j].get_code()) {
          Student temp = students[i];
          students[i] = students[j];
          students[j] = temp;
        }
      }
    }
  }

  for (const auto &s : students) {
    cout << s;
  }

  return 0;
}