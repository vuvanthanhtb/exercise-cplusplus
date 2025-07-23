// TÁCH CHỮ SỐ
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    getchar();

    while(t--) {
        string s;
        getline(cin, s);

        int sum = 0;
        int len = s.length();
        string alphaStr = "";

        for(int i = 0; i < len; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                sum += s[i] - 48;
            } else {
                alphaStr += s[i];
            }
        }

        int alphaStrLeng = alphaStr.length();
        for(int i = 0; i < alphaStrLeng - 1; i++) {
            for(int j = i + 1; j < alphaStrLeng; j++) {
                if(alphaStr[i] > alphaStr[j]) {
                    char temp = alphaStr[i];
                    alphaStr[i] = alphaStr[j];
                    alphaStr[j] = temp;
                }
            }
        }

        if(sum != 0) {
            alphaStr += to_string(sum);
        }

        cout << alphaStr << endl;
    }
    return 0;
}