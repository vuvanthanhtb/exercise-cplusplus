// QUAY VÒNG DÃY SỐ 1
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        int a[n];

        int q = 0;
        while(q < n) {
            cin >> a[q];
            q++;
        }

        int arr[n];
        int f = 0;
        int g = 0;
        int h = d;
        while(f < n) {
            if(h < n) {
                arr[f] = a[h];
                h++;
            } else {
                arr[f] = a[g];
                g++;
            }
            f++;
        }

        int l = 0;
        for(l = 0; l < n; l++) {
            cout << arr[l] << " ";
        }
        cout << endl;

    }
    return 0;
}
