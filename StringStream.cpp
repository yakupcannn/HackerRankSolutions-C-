#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {//!the function converting the string to integer data type
    stringstream ss(str);
    char ch;
    int temp;
    vector<int>arr;
    while (ss >> temp >> ch)//!parsing operation
    {
        arr.push_back(temp);//!adding element into the vector
    }
    ss >> temp;
    arr.push_back(temp);
    return arr;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}