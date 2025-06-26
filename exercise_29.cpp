// TÍNH TỔNG CÁC SỐ TRONG XÂU
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int extract_number(const string& str) {
    string digits = "";
    for(char ch : str) {
        if(isdigit(ch)) {
            digits += ch;
        }
    }
    return digits.empty() ? 0 : stoi(digits);
}

void compute_total() {
    string s;
    getline(cin, s);

    int len = s.length();
    string arr[len];
    int index = 0;
    int flag = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            if(len == i + 1) {
                arr[index] = s.substr(flag);
                index++;
                break;
            }

            if(s[i + 1] < '0' || s[i + 1] > '9') {
                arr[index] = s.substr(flag, i + 1 - flag);
                index++;
                flag = i + 1;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < index; i++) {
        sum += extract_number(arr[i]);
    }

    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) {
        compute_total();
    }

    return 0;
}
