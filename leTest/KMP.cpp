//KMP算法用于找到两个字符串中，子串2在串1中的位置
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//子字符串重复子串记录
void get_next(string str2,int *next)
{
	int i = 1,j = 0;
	int len = str2.size();
	str2 = " " + str2;
	next[1] = 0;
	while (i < len)
	{
			if (j == 0 || str2[j] == str2[i])
			{
				i++;
				j++;
				if (str2[j] != str2[i])
					next[i] = j;
				else
					next[i] = next[j];
				
			}
			else
			{
				j = next[j];
			}
	}
}
//KMP算法实现
int KMP(string str1, string str2)
{
	//abcababcabxmn abcabx
	int pos1 = 1, pos2 = 1;
	int next[255] = {0};
	get_next(str2, next);
	int len1 = str1.size();
	int len2 = str2.size();
	str1 = " " + str1;
	str2 = " " + str2;
	while (pos1 <= len1 && pos2 <= len2)
	{
		if (pos2 == 0 || str1[pos1] == str2[pos2])
		{
			pos1++;
			pos2++;
		}
		else
		{
			pos2 = next[pos2];
		}
	}
	if (pos2 > len2)
		return pos1 - pos2;
	else
		return 0;
}
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int res = 0;
	res = KMP(str1, str2);
	cout << res << endl;
	system("pause");
	return 0;
}