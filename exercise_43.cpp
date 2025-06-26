// SẮP XẾP THEO MÃ SINH VIÊN
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

  string get_code() const { return code; }

  string get_classroom() const { return classroom; }

  static void show_list_student(vector<Student> &students) {
    for (int i = 0; i < students.size() - 1; i++) {
      for (int j = i + 1; j < students.size(); j++) {
        if (students[i].get_code() > students[j].get_code()) {
          Student temp = students[i];
          students[i] = students[j];
          students[j] = temp;
        }
      }
    }
    for (const Student &student : students) {
      cout << student;
    }
  }
};

Student::Student() {}

Student::~Student() {}

int main() {
  vector<Student> students;
  int count = 1;

  while (true) {
    Student s;
    cin >> s;
    students.push_back(s);

    if (count % 4 == 0) {
      Student::show_list_student(students);
    }

    if (count > 1000) {
      break;
    }

    count++;
  }

  return 0;
}