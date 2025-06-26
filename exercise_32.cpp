// HỢP VÀ GIAO CỦA HAI DÃY SỐ -2
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

void display(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int min = m < n ? m : n;

        int a[n];
        int b[m];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }

        int u_matrix[m + n];
        int i_matrix[min];

        int u_index = 0;
        int i_index = 0;
        for(int i = 0; i < n; i++) {
            if(!isExist(u_matrix, u_index, a[i])) {
                u_matrix[u_index] = a[i];
                u_index++;
            }

            if(isExist(b, m, a[i])) {
                i_matrix[i_index] = a[i];
                i_index++;
            }
        }

        for(int i = 0; i < m; i++) {
            if(!isExist(u_matrix, u_index, b[i])) {
                u_matrix[u_index] = b[i];
                u_index++;
            }
        }


        display(u_matrix, u_index);
        display(i_matrix, i_index);
    }

    return 0;
}