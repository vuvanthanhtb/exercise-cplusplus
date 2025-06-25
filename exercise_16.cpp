// NHỎ NHẤT - LỚN NHẤT
#include <iostream>
#include <math.h>

using namespace std;

int sumDigits(int num, int n) {
    int sum = 0;
    int k = n;
    while(k) {
        sum += num % 10;
        num = num / 10;
        k--;
    }

    return sum;
}

int main() {
    int m, s;
    cin >> m >> s;

    int limit = pow(10, m);

    int k = pow(10, m - 1);
    int min = limit;
    int max = -1;
    while(k < limit) {
        if(sumDigits(k, m) == s) {
            if(min > k) {
                min = k;
            }
            if(max < k) {
                max = k;
            }
        }

        k++;
    }

    if(min == limit) {
        min = -1;
    }


    cout << min << " " << max << endl;
    return 0;
}
