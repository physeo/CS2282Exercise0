/**********************************************
Bryce Graham
CS 2282
Dr. Beard
Exercise 0: An introductory program to learn concepts in c++. 
It includes using the cout, adding ascii values, working with
strings, arrays and passing values to functions.
**********************************************/

#include <iostream>
#include <string>
using namespace std;

int sumAscii(const string &s);
int asciiSumArray(char(*asciiArray)[2], int row, int col);
int parceHex(const string &hexString);
int parceBinary(const string &binaryString);
int reverseArray(int intArray[], int length);

// Handles all of the communication between the user and the various methods.
int main()
{
	cout << "Hello World. \n";

	cout << "Enter a string: ";
	string s = "";
	getline (cin, s);
	int asciiSum = sumAscii(s);
	cout << "the Ascii sum is: " << asciiSum << "\n";

	cout << "Enter a hexadecimal number: ";
	getline(cin, s);
	int hexToDec = parceHex(s);
	cout << "The number in decimal is: " << hexToDec << "\n";

	cout << "Enter a binary number: ";
	getline(cin, s);
	int binToDec = parceBinary(s);
	cout << "The number in decimal is: " << binToDec << "\n";

	cout << "Enter length of array: ";
	int length = 0;
	cin >> length;
	int* intArray = new int[length];
	for (int i = 0; i < length; ++i)
	{
		cout << "Enter an integer for the array: ";
		int myInt;
		cin >> myInt;
		intArray[i] = myInt;
	}
	reverseArray(intArray, length);
	cout << "Your array reversed is: ";
	for (int i = 0; i < length; ++i)
		cout << intArray[i] << " ";
	
	const int row = 3;
	const int col = 2;
	char twoDArray[row][col];
	cout << "\nEnter 6 characters for the 2D array\n";
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 2; ++c)
		{
			cout << "Enter a character for the array: ";
			char myChar;
			cin >> myChar;
			twoDArray[r][c] = myChar;
		}
	}
	cout << "The ascii sum of the array is: " << asciiSumArray(twoDArray, row, col) << "\n";

	return 0;
}

// Sums all of the ascii values of a string.
int sumAscii(const string &s)
{
	int sum = 0;
	for (unsigned i = 0; i < s.length(); ++i)
		sum += (int)s[0];
	return sum;
}

// Sums ascii values for each character in a 2 dimensional array. 
int asciiSumArray(char(*asciiArray)[2], int row, int col)
{
	int sum = 0;
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 2; ++col)
		{
			sum += (int)asciiArray[row][col];
		}
	}
	return sum;
}

// Converts a hexadecimal number into a decimal number.
int parceHex(const string &hexString)
{
	try
	{
		int hexToDec = stoul(hexString, nullptr, 16);
		return hexToDec;
	}
	catch (...)
	{
		return -1;
	}
}

// Converts a binary number into a decimal number.
int parceBinary(const string &binaryString)
{
	try
	{
		int binToDec = stoul(binaryString, nullptr, 2);
		return binToDec;
	}
	catch (...)
	{
		return -1;
	}
}

// Takes an array and reverses it so that the last value is first
// second last is second first and so on.
int reverseArray(int intArray[], int length)
{
	int temp;
	for (int i = 0; i < length / 2; ++i)
	{
		temp = intArray[length - (i + 1)];
		intArray[length - (i + 1)] = intArray[i];
		intArray[i] = temp;
	}
	return 0;
}

