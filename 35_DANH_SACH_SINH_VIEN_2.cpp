// DANH SÁCH SINH VIÊN - 2
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string standardize_name(string s) {
    string output;
    output = "";
    for(int i = 0; i < s.length(); i++) {
        output = output + s[i];
        while((s[i] == ' ') && s[i + 1] == ' ') {
            i++;
        }
    }
    s = output;

    s[0] = toupper(s[0]);
    for(int i = 1; i < s.size(); i++) {
        s[i] = tolower(s[i]);

        if(s[i - 1] == ' ') {
            s[i] = toupper(s[i]);
        }
    }
    return s;
}

string standardize_date(string s) {
    string output = "";
    int idx = 0;
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '/') {
            string sub = s.substr(idx, i - idx);
            idx = i + 1;
            output += (sub.length() != 2 ? string("0" + sub) : sub) + "/";
            count++;
        }

        if(count == 2) {
            output += s.substr(idx);
            break;
        }
    }

    return output;
}

struct Student {
    string student_code;
    string full_name;
    string student_class;
    string date_of_birth;
    float gpa;

    void display() {
        cout << fixed << setprecision(2);
        string name = standardize_name(full_name);
        string date = standardize_date(date_of_birth);
        cout << student_code << " " << name << " " << student_class << " " << date << " " << gpa << endl;
    }
};


int main() {
    int n;
    cin >> n;
    int i = 1;
    while(i <= n) {
        Student s;
        s.student_code = "B20DCCN0" + string(i < 10 ? "00" : "0") + to_string(i);
        cin.ignore();
        getline(cin, s.full_name);
        getline(cin, s.student_class);
        getline(cin, s.date_of_birth);
        cin >> s.gpa;

        s.display();
        i++;
    }


    return 0;
}