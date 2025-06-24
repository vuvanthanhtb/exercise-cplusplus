// BIÊN CỦA MA TRẬN
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int k = 0;
        int a[n * n];
        while(k < n * n) {
            cin >> a[k];
            k++;
        }


        int matrix[n][n];
        int l = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = a[l];
                l++;
            }

        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    cout << matrix[i][j] << " ";
                } else {
                    cout << " "  << " ";
                }
            }
            cout << endl;
        }

    }
    return 0;
}