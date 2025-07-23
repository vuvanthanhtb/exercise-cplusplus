// BIẾN ĐỔI DÃY SỐ
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int l = 0;
    int r = n - 1;
    int count = 0;
    while (l <= r) {
      if (a[l] == a[r]) {
        l++;
        r--;
      } else if (a[l] < a[r]) {
        l++;
        a[l] += a[l - 1];
        count++;
      } else {
        r--;
        cout << r << "  " << a[r] << " " << a[r + 1] << endl;
        a[r] += a[r + 1];
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}