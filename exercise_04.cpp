// CÂN BẰNG CHẴN LẺ
#include <iostream>
#include <math.h>

using namespace std;

bool evenOddBalance(int n) {
    int evenSum = 0, oddSum = 0;
    while(n) {
        int digit = n % 10;
        if(digit % 2 == 0) {
            evenSum += 1;
        } else {
            oddSum += 1;
        }
        n /= 10;
    }

    return evenSum == oddSum;
}

int main() {
    int n;
    cin >> n;

    if(n <= 1 || n >= 7) {
        cout << "Vui long nhap mot so tu 2 den 6." << endl;
        return 1;
    }

    if(n % 2 != 0) {
        cout << "Vui long nhap mot so chan." << endl;
        return 1;
    }

    int i;
    int count = 0;
    for(i = pow(10, n - 1); i < pow(10, n); i++) {
        if(evenOddBalance(i)) {
            count++;
            cout << i << " ";

            if(count == 10) {
                cout << endl;
                count = 0;
            }
        }
    }
    cout << endl;
    return 0;
}