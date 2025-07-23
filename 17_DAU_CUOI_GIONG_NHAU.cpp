// ĐẦU CUỐI GIỐNG NHAU
#include <iostream>
#include <string>

using namespace std;

void numOfSameStartEnd() {
    string s;
    getline(cin, s);
    int count = 0;
    int len = s.length();
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            if(s[i] == s[j]) {
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) {
        numOfSameStartEnd();
    }

    return 0;
}
