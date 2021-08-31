#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int size;
    cin >> size;
    int* arr=new int[size];//!dynamic memory allocation
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";//!printing the array with reverse order
    }
    delete[]arr;
    return 0;
}
