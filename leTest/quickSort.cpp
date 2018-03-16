#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int> & vec1, int low, int high)
{
	int pivotkey = vec1[low];
	while (low < high)
	{
		while (low < high && vec1[high] >= pivotkey)
			high--;
		swap(vec1[low], vec1[high]);
		while (low < high && vec1[low] <= pivotkey)
			low++;
		swap(vec1[low], vec1[high]);
	}
	return low;
}
void QuickSort(vector<int> &vec, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(vec, low, high);
		QuickSort(vec, low, pivot - 1);
		QuickSort(vec, pivot + 1, high);
	}
}
int main()
{
	vector<int> inVec;
	int m;
	inVec.push_back(0);
	do
	{
		cin >> m;
		inVec.push_back(m);
	} while (cin.get() != '\n');
	int length = inVec.size() - 1;
	QuickSort(inVec, 1, length);
	for (int i = 1; i <= length; i++)
		cout << inVec[i] << " ";
	system("pause");
	return 0;
}