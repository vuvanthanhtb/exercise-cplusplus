// TÍNH TỔNG HAI ĐỐI TƯỢNG PHÂN SỐ
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

    Fraction operator+(Fraction& other) {
        int n = numerator * other.denominator + denominator * other.numerator;
        int d = denominator * other.denominator;
        return Fraction(n, d);
    }
};

int main() {
    int n1, d1, n2, d2;
    cin >> n1 >> d1 >> n2 >> d2;

    Fraction f1(n1, d1);
    Fraction f2(n2, d2);

    Fraction f = f1 + f2;
    f.simplity();

    return 0;
}