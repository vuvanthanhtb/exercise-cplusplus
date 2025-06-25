// SẮP XẾP CHỮ SỐ
#include <iostream>

#define MAX 10000

using namespace std;

bool isExist(int arr[], int n, int found) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == found) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int a[MAX];
        int index = 0;
        for(int i = 0; i < n; i++) {
            int current = arr[i];
            while(current) {
                int temp = current % 10;
                if(!isExist(a, index, temp)) {
                    a[index] = temp;
                    index++;
                }

                current /= 10;
            }

        }

        for(int i = 0; i < index - 1; i++) {
            for(int j = i + 1; j < index; j++) {
                if(a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        for(int i = 0; i < index; i++) {
            cout << a[i] << "  ";
        }
        cout << endl;
    }
    return 0;
}