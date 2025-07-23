// LIỆT KÊ SỐ CÓ BA ƯỚC SỐ
#include <iostream>

using namespace std;

bool isNumberWithThreeFactors(int num) {
    int count = 2;
    int i = 2;
    while(i < num) {
        if(num % i == 0) {
            count++;
        }

        if(count > 3) {
            return false;
        }

        i++;
    }
    return count == 3;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        int num;
        cin >> num;

        int k = 1;
        while(k < num) {
            if(isNumberWithThreeFactors(k)) {
                cout << k << " ";
            }
            k++;
        }
        cout << endl;
    }
    return 0;
}