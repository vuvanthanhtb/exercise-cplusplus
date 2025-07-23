// BIẾN ĐỔI NHỊ PHÂN
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
        int n, m;
        cin >> n >> m;

        int matrix[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int row[n];
        int col[m];
        for(int i = 0; i < m; i++) {
            col[i] = -1;
        }


        for(int i = 0; i < n; i++) {
            row[i] = -1;
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {
                    row[i] = i;
                    col[j] = j;
                }
            }
        }

        int result[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isExist(row, n, i)) {
                    result[i][j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isExist(col, m, i)) {
                    result[j][i] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}