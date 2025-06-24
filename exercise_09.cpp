// CHÊNH LỆCH NHỎ NHẤT
#include <iostream>
#include<math.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int a[n];
        int k = 0;
        while(k < n) {
            cin >> a[k];
            k++;
        }
        int min = a[0];
        int j = 0;
        while(j < n) {
            int f = j + 1;
            while (f < n)
            {
                int sub = abs(a[j] - a[f]);
                if(min > sub) {
                    min = sub;
                }
                f++;
            }
            j++;
        }
        cout << min << endl;
    }

    cout << endl;
    return 0;
}