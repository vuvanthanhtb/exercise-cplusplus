// CHỮ HOA – CHỮ THƯỜNG
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        char s;
        cin >> s;
        if(s >= 65 && s <= 92)
            s += 32;
        else if(s >= 97 && s <= 122)
            s -= 32;
        cout << s << endl;
    }

    return 0;
}