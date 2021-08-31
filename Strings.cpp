#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, conc;
    cin >> a >> b;
    cout << a.length() << " " << b.length() << endl;
    conc = a + b;//!concreting the two strings
    cout << conc << endl;
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;
    cout << a << " " << b;
    return 0;
}