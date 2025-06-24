// TÍNH TỔNG 1 ĐẾN N
#include <iostream>
using namespace std;

int computeSum(int n) {
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    if(n <= 0) {
        cout << "Vui long nhap mot so nguyen duong." << endl;
        return 1;
    }

    while (n--)
    {
        int input;
        cin >> input;
        if(input <= 0) {
            cout << "Vui long nhap mot so nguyen duong." << endl;
            return 1;
        }
        cout << computeSum(input) << endl;
    }
    
    return 0;
}