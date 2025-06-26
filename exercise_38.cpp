// BẢNG ĐIỂM THÀNH PHẦN - 1
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

bool compareCode(string str1, string str2) {
  int len = str1.length();
  for (int i = 0; i < len; i++) {
    if (str1[i] > str2[i]) {
      return false;
    }
  }

  return true;
}

struct Student {
  string student_code;
  string full_name;
  string student_class;
  double score_1;
  double score_2;
  double score_3;

  void display(int i) {
    cout << fixed << setprecision(1);
    cout << i << " " << student_code << " " << full_name << " " << student_class
         << " " << score_1 << " " << score_2 << " " << score_3 << endl;
  }
};

int main() {
  int n;
  cin >> n;
  Student students[n];
  int t = 0;
  while (t < n) {
    Student s;
    cin.ignore();
    getline(cin, s.student_code);
    getline(cin, s.full_name);
    getline(cin, s.student_class);
    cin >> s.score_1;
    cin >> s.score_2;
    cin >> s.score_3;

    students[t] = s;
    t++;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (compareCode(students[i].student_code, students[j].student_code)) {
        Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    students[i].display(i);
  }

  return 0;
}