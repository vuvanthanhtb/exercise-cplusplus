// TÍNH TỔNG GIAI THỪA
#include <iostream>

using namespace std;

#define MAX 20

int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;

    if(n <= 0) {
        cout << "Vui long nhap mot so nguyen duong." << endl;
        return 1;
    } else if(n > MAX) {
        cout << "Vui long nhap mot so nho hon hoac bang " << MAX << "." << endl;
        return 1;
    }

    int sum = 0;
    while(n >= 1) {
        sum += factorial(n);
        n--;
    }


    cout << sum << endl;

    return 0;
}