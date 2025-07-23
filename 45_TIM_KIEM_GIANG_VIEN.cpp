// TÌM KIẾM GIẢNG VIÊN
#include <iostream>

using namespace std;

class Teacher {
private:
  string code;
  string name;
  string department_code;
  string department_name;

public:
  Teacher();
  ~Teacher();

  void set_code(int i) {
    if (i < 10) {
      code = "GV0" + to_string(i);
    } else {
      code = "GV" + to_string(i);
    }
  }

  friend istream &operator>>(istream &is, Teacher &teacher) {
    getline(is, teacher.name);
    getline(is, teacher.department_name);
    return is;
  }

  friend ostream &operator<<(ostream &os, const Teacher teacher) {
    os << teacher.code << " " << teacher.name << " " << teacher.department_code
       << endl;
    return os;
  }

  static string toupper_department(string s) {
    for (int i = 0; i < s.size(); i++) {
      s[i] = toupper(s[i]);
    }
    return s;
  }

  void set_department_code() {
    if (toupper_department(department_name) == "CONG NGHE PHAN MEM") {
      department_code = "CNPM";
    } else if (toupper_department(department_name) == "KHOA HOC MAY TINH") {
      department_code = "KHMT";
    } else if (toupper_department(department_name) == "AN TOAN THONG TIN") {
      department_code = "ATTT";
    }
  }

  static void search_teacher(vector<Teacher> &teachers,
                             vector<string> keywords) {
    for (string keyword : keywords) {
      cout << endl;
      string title = "DANH SACH GIANG VIEN THEO TU KHOA " + keyword;
      cout << title << endl;
      for (Teacher &teacher : teachers) {
        if (toupper_department(teacher.department_name)
                .find(toupper_department(keyword)) != string::npos) {
          cout << teacher;
        }
      }
    }
  }
};

Teacher::Teacher() {}

Teacher::~Teacher() {}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  vector<Teacher> teachers;

  while (n--) {
    Teacher teacher;
    cin >> teacher;
    teacher.set_code(teachers.size() + 1);
    teacher.set_department_code();
    teachers.push_back(teacher);
  }

  int q;
  cin >> q;
  cin.ignore();
  vector<string> keywords;
  for (int i = 0; i < q; i++) {
    string keyword;
    getline(cin, keyword);
    keywords.push_back(keyword);
  };

  Teacher::search_teacher(teachers, keywords);
  return 0;
}