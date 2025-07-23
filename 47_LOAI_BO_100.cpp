// LOẠI BỎ 100
#include <iostream>
#include <string>

using namespace std;

string recursiveSplit(string s, string sub) {
  if (s.length() < 3) {
    return s;
  }
  string newStr = "";
  int check = 0;
  bool isSubstr = false;
  int subLength = sub.length();
  for (int i = 0; i < s.length(); i++) {
    if (s.substr(i, subLength) == sub) {
      check = 1;
      isSubstr = true;
      continue;
    }

    if (check >= 1) {
      check++;
    }

    if (check >= 1 && check <= 3) {
      continue;
    }

    newStr += s[i];
  }

  if (!isSubstr) {
    return s;
  }

  return recursiveSplit(newStr, sub);
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  string sub = "100";

  while (n--) {
    string s;
    getline(cin, s);
    string remaining = recursiveSplit(s, sub);
    int result = s.length() - remaining.length();
    cout << result << endl;
  }
  return 0;
}