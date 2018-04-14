/*Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string inStr1, inStr2;
	cin >> inStr1 >> inStr2;
	string sumStr(inStr1.size() + inStr2.size(), '0');
	int carry = 0;
	for (int i = inStr1.size() - 1; i >= 0; i--)
	{
		carry = 0;
		for (int j = inStr2.size() - 1; j >= 0; j--)
		{
			int tem = (sumStr[i + j + 1] - '0') + (inStr1[i] - '0') * (inStr2[j] - '0') + carry;
			sumStr[i + j + 1] = tem % 10 + '0';
			carry = tem / 10;
		}
		sumStr[i] += carry;
	}
	int start = sumStr.find_first_not_of('0');
	if (string::npos != start)
	{
		cout << sumStr.substr(start);
	}
	system("pause");
	return 0;
}