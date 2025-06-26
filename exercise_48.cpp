// SỐ KHÁC NHAU TRONG FILE
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> convert_str_to_arr(string str) {
  int len = str.length();
  vector<int> result;
  int t = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == ' ') {
      string sub = str.substr(t, i - t);
      result.push_back(stoi(sub));
      t = i + 1;
      continue;
    }

    if (i == len - 1) {
      string sub = str.substr(t, i - t + 1);
      result.push_back(stoi(sub));
    }
  }

  return result;
}

bool isExist(vector<int> arr, int found) {
  for (int &a : arr) {
    if (a == found) {
      return true;
    }
  }

  return false;
}

vector<int> convertUniqueArr(vector<int> arr) {
  vector<int> result;

  for (int &a : arr) {
    if (isExist(result, a)) {
      continue;
    }
    result.push_back(a);
  }
  return result;
}

int countElements(vector<int> arr, int element) {
  int count = 0;
  for (int &a : arr) {
    if (a == element) {
      count++;
    }
  }
  return count;
}

int main() {
  string line;
  ifstream r_file("DATA.in");
  string s;

  if (r_file.is_open()) {
    while (getline(r_file, line)) {
      s += line;
    }

    r_file.close();
  } else {
    cout << "unable to open file DATA.in";
  }

  vector<int> dataFileArr = convert_str_to_arr(s);
  int size = dataFileArr.size();
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (dataFileArr[i] > dataFileArr[j]) {
        int temp = dataFileArr[i];
        dataFileArr[i] = dataFileArr[j];
        dataFileArr[j] = temp;
      }
    }
  }

  vector<int> uniqueArr = convertUniqueArr(dataFileArr);
  for (int &i : uniqueArr) {
    int count = countElements(dataFileArr, i);
    cout << i << " " << count << endl;
  }
  return 0;
}