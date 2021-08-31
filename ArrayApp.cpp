#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//! description getData
void getData(ifstream*, int*, int);
//! description sum 
int findSum(int, int[]);
//! description product 
int findMultiply(int, int[]);
//! description average 
float findAverage(int, int[]);
//! description minimum  
int findMinimum(int, int[]);
//! description print
void printValue(int, int, float, int);
int main()
{
	string fileName;
	ifstream myFile;
	int size;
	cout << "enter the filename: ";
	cin >> fileName;
	//! openning file
	myFile.open(fileName, ios::in);
	//! not openning file
	if (!myFile.is_open())
	{
		cout << "The file cannot be opened" << endl;
	}
	else
	{
		myFile >> size;
		int* arr = new int[size];
		if (arr == NULL)
		{
			cout << "the memory cannot be allocated";
			system("pause");
			exit(0);
		}
		//! get data from the file
		getData(&myFile, arr, size);
		//! closing the file
		myFile.close();
		//! printing 
		printValue(findSum(size, arr), findMultiply(size, arr), findAverage(size, arr), findMinimum(size, arr));
		//! protecting memory leak
		delete[] arr;

	}
	cout << endl << endl;
	system("pause");
	return 0;
}
/*!
* @param arr is a integer array.
* @param size is size of the array.
* @param file is file object.
*/
void getData(ifstream* file, int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*file >> arr[i];
	}
}
int findSum(int size, int arr[])
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int findMultiply(int size, int arr[])
{
	int product = 1;
	for (int i = 0; i < size; i++)
	{
		product *= arr[i];
	}
	return product;
}
float findAverage(int size, int arr[])
{
	return (float)findSum(size, arr) / (float)size;
}
int findMinimum(int size, int arr[])
{
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
/*!
* @param sumF is the returning integer function that gives the sum of the array.
* @param productF is the returning integer function that gives the product of the array.
* @param averageF is the returning float function that gives the average of the array.
* @param minF is returning integer function that gives the minimum value.
*/
void printValue(int sumF, int productF, float averageF, int minF)
{
	cout << "the sum is: " << sumF << endl;
	cout << "the product is: " << productF << endl;
	cout << "the average is: " << averageF << endl;
	cout << "the minimum number is: " << minF;
}

