// SAO CHÉP TỆP TIN
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string line;
    ifstream r_file("PTIT.in");
    if(r_file.is_open()) {
        ofstream w_file("PTIT.out");
        if(w_file.is_open()) {
            while(getline(r_file, line)) {
                w_file << line << endl;
            }
            w_file.close();
        } else {
            cout << "unable to open file PTIT.out";
        }
        r_file.close();
    } else {
        cout << "unable to open file PTIT.in";
    }

    return 0;
}