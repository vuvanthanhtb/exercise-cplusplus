// SỐ MAY MẮN
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int m;
    cin >> m;
    int sub[m][m];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> sub[i][j];
        }
    }

    int r = 0;
    int c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            r = r == m ? 0 : r;
            c = c == m ? 0 : c;
            arr[i][j] *= sub[r][c];
            c++;
        }
        r++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}