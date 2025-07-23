// CẤU TRÚC THÍ SINH
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string full_name;
    string date_of_birth;
    double score_1;
    double score_2;
    double score_3;

    void displayInfo() {
        double total_score = score_1 + score_2 + score_3;
        cout << fixed << setprecision(1);
        cout << full_name << "  " << date_of_birth << "  " << total_score << endl;
    }
};


int main() {
    Student student;
    getline(cin, student.full_name);
    getline(cin, student.date_of_birth);
    cin >> student.score_1;
    cin >> student.score_2;
    cin >> student.score_3;

    student.displayInfo();
    return 0;
}