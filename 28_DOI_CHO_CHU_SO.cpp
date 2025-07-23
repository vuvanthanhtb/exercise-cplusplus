// ĐỔI CHỖ CHỮ SỐ
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int arr[100];

        int num = n;
        int index = 0;
        while(num) {
            arr[index] = num % 10;
            num /= 10;
            index++;
        }

        for(int i = index - 2; i > 0; i--) {
            if(arr[i] > arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                break;
            }
        }

        int new_num = 0;
        for(int i = 0; i < index; i++) {
            new_num += arr[i] * pow(10, i);
        }

        cout << (new_num == n ? -1 : new_num) << endl;

    }
    return 0;
}