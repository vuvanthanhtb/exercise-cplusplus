// LIỆT KÊ SỐ KHÁC NHAU
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    int a[t];
    int k = 0;
    while(k < t) {
        cin >> a[k];
        k++;
    }

    int count = 0;
    for(int i = 0; i < t; i++) {
        for(int j = i + 1; j < t; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for(int i = 1; i < t; i++) {
        if(a[i] != a[i - 1]) {
            count++;
        }
    }

    int arr[count + 1];
    arr[0] = a[0];
    int j = 1;
    for(int i = 1; i < t; i++) {
        if(a[i] != a[i - 1]) {
            arr[j] = a[i];
            j++;
        }
    }

    for(int i = 0; i <= count; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}