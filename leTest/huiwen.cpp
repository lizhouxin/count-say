#include<iostream>
#include<string>
using namespace std;

int main()
{
	string inStr;
	do {
		cin >> inStr;
	} while (cin.get() != '\n');

	int len = inStr.size();
	int start = 0, right = 0, left = 0, max_len = 1, max_left = 0;
	if (len < 2) cout << inStr;
	for (start = 0; right < len&& len - start > max_len / 2;)
	{
		right = left = start;
		while (right < len - 1 &&inStr[right] == inStr[right + 1])
			right++;
		start++;
		while (left > 0 && right < len - 1 && inStr[left - 1] == inStr[right + 1])
		{
			right++;
			left--;
		}
		if (max_len < right - left + 1)
		{
			max_len = right - left + 1;
			max_left = left;
		}
	}
	cout << inStr.substr(max_left, max_len) << endl;
	system("pause");
	return 0;
}
