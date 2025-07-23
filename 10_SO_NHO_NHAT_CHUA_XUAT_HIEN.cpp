// SỐ NHỎ NHẤT CHƯA XUẤT HIỆN
#include <iostream>

using namespace std;

bool isPresent(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return true;
    }
  }
  return false;
}

void sortArray(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int a[n];
    int k = 0;
    while (k < n) {
      cin >> a[k];
      k++;
    }

    sortArray(a, n);

    int m = 0;
    int currentSmallest = a[n - 1] + 1;
    while (m < n) {
      int current = a[m];
      if (current > 0) {
        int i = 1;
        while (i < current) {
          bool found = isPresent(a, m, i);
          if (!found) {
            currentSmallest = i;
            break;
          }
          i++;
        }
      }
      m++;
    }

    cout << currentSmallest << endl;
  }
  return 0;
}