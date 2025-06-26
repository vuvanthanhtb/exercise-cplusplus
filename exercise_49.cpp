// LIỆT KÊ TỪ KHÁC NHAU
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> convert_str_to_arr(string str) {
  int len = str.length();
  vector<string> result;
  int t = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == ' ') {
      string sub = str.substr(t, i - t);
      result.push_back(sub);
      t = i + 1;
      continue;
    }

    if (i == len - 1) {
      string sub = str.substr(t, i - t + 1);
      result.push_back(sub);
    }
  }

  return result;
}

bool is_exist(vector<string> arr, string found) {
  for (string &a : arr) {
    if (a == found) {
      return true;
    }
  }

  return false;
}

string standardize_str(string s) {
  for (int i = 0; i < s.size(); i++) {
    s[i] = tolower(s[i]);
  }
  return s;
}

vector<string> convert_unique_arr(vector<string> arr) {
  vector<string> result;

  for (string &a : arr) {
    string str = standardize_str(a);
    if (is_exist(result, str)) {
      continue;
    }
    result.push_back(str);
  }
  return result;
}

int main() {
  string line;
  ifstream r_file("VANBAN.in");
  string s;

  if (r_file.is_open()) {
    while (getline(r_file, line)) {
      s += line + " ";
    }

    r_file.close();
  } else {
    cout << "unable to open file DATA.in";
  }

  vector<string> dataFileArr = convert_str_to_arr(s);
  vector<string> uniqueArr = convert_unique_arr(dataFileArr);
  int size = uniqueArr.size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (uniqueArr[i] > uniqueArr[j]) {
        string temp = uniqueArr[i];
        uniqueArr[i] = uniqueArr[j];
        uniqueArr[j] = temp;
      }
    }
  }
  for (string &i : uniqueArr) {
    cout << i << endl;
  }

  return 0;
}