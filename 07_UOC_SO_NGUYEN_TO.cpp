// ƯỚC SỐ NGUYÊN TỐ
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

void printPrimeFactors(int n) {
    if(n < 2) {
        return;
    }

    int num = 2;
    while(num <= n) {
        if(n % num == 0 && isPrime(num)) {
            cout << num << " ";
        }
        num++;
    }
    cout << endl;
}

int main() {
    int num;
    cin >> num;

    while(num--) {
        int n;
        cin >> n;
        printPrimeFactors(n);
    }

    return 0;
}