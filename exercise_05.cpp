// SỐ MAY MẮN
#include <iostream>

using namespace std;

#define LUCKY_NUMBER 86

int isLuckyNumber(int n) {
    if(n == 0) {
        return 1;
    }
    
    int num = 0;
    int j = 1;
    while(n != 0) {
        int digit = n % 10;
        n /= 10;

        num += digit * j;
        j *= 10;

        if(num == LUCKY_NUMBER) {
            return 1;
        }

    }
    return 0;
}

int main() {
    int n;
    cin >> n;

    if(n > 20 || n < 1) {
        cout << "Vui long nhap mot so nguyen duong tu 1 den 20." << endl;
        return 1;
    }

    while(n--) {
        int num;
        cin >> num;

        cout << isLuckyNumber(num) << endl;
    }

    return 0;
}
