#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int sizeI, q, sizeJ;
    cin >> sizeI;
    cin >> q;
    int** arr = new int* [sizeI];//!dynamic array allocation
    for (int i = 0; i < sizeI; i++)
    {
        cin >> sizeJ;
        arr[i] = new int[sizeJ];
        for (int j = 0; j < sizeJ; j++)
        {
            cin >> arr[i][j];
        }
    }
    int wI, wJ;
    for (int i = 0; i < q; i++)
    {
        cin >> wI >> wJ;
        cout << arr[wI][wJ] << endl;
    }
    delete[] arr;//!protecting from memory leak
    return 0;
}
