// BẢNG ĐIỂM THÀNH PHẦN - 2
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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
      if (students[i].full_name > students[j].full_name) {
        Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    students[i].display(i + 1);
  }

  return 0;
}