// HỢP VÀ GIAO CỦA HAI FILE VĂN BẢN
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

vector<string> read_content_from_file(string file_name) {
  string line;
  ifstream r_file(file_name);
  vector<string> s;

  if (r_file.is_open()) {
    while (getline(r_file, line)) {
      for (string &str : convert_str_to_arr(line)) {
        s.push_back(str);
      }
    }

    r_file.close();
  } else {
    cout << "unable to open file DATA.in";
    return {};
  }

  return s;
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

vector<string> sort_arr(vector<string> &arr) {
  int size = arr.size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        string temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  return arr;
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
  return sort_arr(result);
}

int main() {
  vector<string> s1 = read_content_from_file("DATA1.in");
  vector<string> s2 = read_content_from_file("DATA2.in");

  vector<string> unique_matrix_1 = convert_unique_arr(s1);
  vector<string> unique_matrix_2 = convert_unique_arr(s2);

  vector<string> u_matrix;
  for (string &s : unique_matrix_1) {
    u_matrix.push_back(s);
  }

  for (string &s : unique_matrix_2) {
    u_matrix.push_back(s);
  }
  u_matrix = convert_unique_arr(u_matrix);

  string u_str = "";
  for (string &s : u_matrix) {
    u_str += s + " ";
  }

  string i_str = "";
  vector<string> i_matrix;
  for (string &s : unique_matrix_1) {
    if (is_exist(unique_matrix_2, s)) {
      i_matrix.push_back(s);
    }
  }

  for (string &i : i_matrix) {
    i_str += i + " ";
  }

  cout << u_str << endl;
  cout << i_str << endl;

  return 0;
}