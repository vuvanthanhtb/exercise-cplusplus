// SẮP XẾP XEN KẼ - 2
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] < a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        int result[n];
        int indexStart = 0;
        int indexEnd = n - 1;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                result[i] = a[indexStart];
                indexStart++;
            } else {
                result[i] = a[indexEnd];
                indexEnd--;
            }
        }

        for(int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}