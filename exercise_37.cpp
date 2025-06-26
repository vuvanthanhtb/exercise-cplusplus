// SẮP XẾP DANH SÁCH NHÂN VIÊN
#include <iostream>
#include <string>

using namespace std;

struct Employee {
    string employee_code;
    string full_nname;
    string gender;
    string date_of_birth;
    string address;
    string tax;
    string contract_date;

    void display() {
        cout << employee_code << " " << full_nname << " " << gender << " " << date_of_birth << " " << address << " " << tax << " " << contract_date << endl;
    }
};

int convert_date_to_number(string s) {
    string output[100];
    int idx = 0;
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '/') {
            string sub = s.substr(idx, i - idx);
            idx = i + 1;
            output[count] = (sub.length() != 2 ? string("0" + sub) : sub);
            count++;
        }

        if(count == 2) {
            output[2] = s.substr(idx);
            break;
        }
    }

    string temp;
    for(int i = count; i >= 0; i--) {
        temp += output[i];
    }


    return stoi(temp);
}

bool compareDateOfBirth() {
    return true;
}

int main() {
    int n;
    cin >> n;
    int code = 1;
    Employee list[n];
    while(code <= n) {
        Employee e;
        e.employee_code = "00" + string(code < 10 ? "00" : "0") + to_string(code);
        cin.ignore();
        getline(cin, e.full_nname);
        getline(cin, e.gender);
        getline(cin, e.date_of_birth);
        getline(cin, e.address);
        getline(cin, e.tax);
        getline(cin, e.contract_date);

        list[code - 1] = e;
        code++;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(convert_date_to_number(list[i].date_of_birth) > convert_date_to_number(list[j].date_of_birth)) {
                Employee temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        list[i].display();
    }

    return 0;
}