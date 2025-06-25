// LOẠI BỎ NGUYÊN ÂM
#include <iostream>
#include <string>

using namespace std;

string removeVowels(string input) {
    string vowels = "ueoaiUEOAI";
    string output = "";
    int len = input.length();

    for(int i = 0; i < len; i++) {
        if (vowels.find(input[i]) == string::npos)
        {
            char c = tolower(input[i]);
            output += ".";
            output += c;
        }
    }

    return output;
}

int main() {
    string s;
    getline(cin, s);

    cout << removeVowels(s) << endl;
    return 0;
}