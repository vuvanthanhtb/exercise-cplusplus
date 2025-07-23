// LIỆT KÊ SINH VIÊN THEO NGÀNH
#include <iostream>

using namespace std;

class Student {
private:
  string code;
  string name;
  string classroom;
  string email;
  string major;

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

  void set_major() {
    if (code.find("DCKT") != string::npos) {
      major = "Ke toan";
    } else if (code.find("DCCN") != string::npos && classroom[0] != 'E') {
      major = "Cong nghe thong tin";
    } else if (code.find("DCAT") != string::npos && classroom[0] != 'E') {
      major = "An toan thong tin";
    } else if (code.find("DCVT") != string::npos) {
      major = "Vien thong";
    } else if (code.find("DCDT") != string::npos) {
      major = "Dien tu";
    }
  }

  static string toupper_major(string s) {
    for (int i = 0; i < s.size(); i++) {
      s[i] = toupper(s[i]);
    }
    return s;
  }

  static void show_list_student(vector<Student> &students,
                                vector<string> majors) {
    for (string major : majors) {
      cout << endl;
      string title = "DANH SACH SINH VIEN NGANH " + toupper_major(major);
      cout << title << endl;
      for (Student &student : students) {
        if (toupper_major(major) == toupper_major(student.major)) {
          cout << student;
        }
      }
    }
  }
};

Student::Student() {}

Student::~Student() {}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<Student> students;

  while (n--) {
    Student s;
    cin >> s;
    s.set_major();
    students.push_back(s);
  }

  int m;
  cin >> m;
  cin.ignore();
  vector<string> majors;
  for (int i = 0; i < m; i++) {
    string major;
    getline(cin, major);
    majors.push_back(major);
  };

  Student::show_list_student(students, majors);

  return 0;
}