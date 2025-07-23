// LIỆT KÊ SỐ NGUYÊN TỐ - 1
#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    int num1;
    int num2;
    cin >> num1 >> num2;

    if(num1 < 1 || num2 < 1) {
        cout << "Vui long nhap hai so nguyen duong." << endl;
        return 1;
    }

    if(num1 > num2) {
        cout << "So thu nhat phai nho hon so thu hai." << endl;
        return 1;
    }

    int n = num1;
    while(n <= num2) {
        if (isPrime(n)) {
            cout << n << " ";
        }
        
        n++;
    }

    cout << endl;
    return 0;
}