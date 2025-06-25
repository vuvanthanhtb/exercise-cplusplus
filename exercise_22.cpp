// KHAI BÁO LỚP PHÂN SỐ
#include <iostream>

using namespace std;

class Fraction {
  private:
    int numerator;
    int denominator;

    int greatest_common_divisor(int num1, int num2) {
        while(num2 != 0) {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }

        return num1;
    }

  public:
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    void simplity() {
        int gcd_value = greatest_common_divisor(abs(numerator), abs(denominator));
        cout << numerator / gcd_value << "/" << denominator / gcd_value << endl;
    }
};

int main() {
    int n, d;
    cin >> n >> d;
    Fraction f(n, d);
    f.simplity();
    return 0;
}