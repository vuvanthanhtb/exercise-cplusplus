// TRẺ NHẤT – GIÀ NHẤT
#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  string date_of_birth;

  void display_name() { cout << name << endl; }
};

int convert_date_to_number(string s) {
  string output[100];
  int idx = 0;
  int count = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '/') {
      string sub = s.substr(idx, i - idx);
      idx = i + 1;
      output[count] = (sub.length() != 2 ? string("0" + sub) : sub);
      count++;
    }

    if (count == 2) {
      output[2] = s.substr(idx);
      break;
    }
  }

  string temp;
  for (int i = count; i >= 0; i--) {
    temp += output[i];
  }

  return stoi(temp);
}

int main() {
  int n;
  cin >> n;
  int index = 0;
  Person list[n];
  while (index < n) {
    string arr[2];
    for (int i = 0; i < 2; i++) {
      cin >> arr[i];
    }

    Person p;
    p.name = arr[0];
    p.date_of_birth = arr[1];

    list[index] = p;
    index++;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (convert_date_to_number(list[i].date_of_birth) >
          convert_date_to_number(list[j].date_of_birth)) {
        Person temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }

  list[n - 1].display_name();
  list[0].display_name();

  return 0;
}