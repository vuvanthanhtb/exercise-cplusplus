// QUAY MA TRẬN
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int row, col;
    cin >> row >> col;

    int arr[row][col];
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> arr[i][j];
      }
    }

    int result[row][col];

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        result[i][j] = arr[i][j];
      }
    }

    for (int i = 0; i < col; i++) {
      if (i > 0) {
        result[0][i] = arr[0][i - 1];
      }

      if (i < col - 1) {
        result[row - 1][i] = arr[row - 1][i + 1];
      }
    }

    for (int i = 0; i < row; i++) {
      if (i < row - 1) {
        result[i][0] = arr[i + 1][0];
      }

      if (i > 0) {
        result[i][col - 1] = arr[i - 1][col - 1];
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cout << result[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}