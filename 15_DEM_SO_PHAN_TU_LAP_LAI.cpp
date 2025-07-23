// ĐẾM SỐ PHẦN TỬ LẶP LẠI
#include <iostream>

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

        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            a[i] = -1;
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[i] > arr[j]) {
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }

        int count = 0;
        int other = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i - 1]) {
                if(!isExist(a, n, arr[i])) {
                    a[other] = arr[i];
                    other++;
                }
                count++;
            }
        }

        cout << count + other << endl;
    }


    return 0;
}