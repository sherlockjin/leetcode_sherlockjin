#include"common.h"

class SolutionArray {
public:
	vector<int> twoSum1(vector<int>& nums, int target);

	vector<int> twoSum2(vector<int>& nums, int target);

	int removeDuplicates(vector<int>& nums);

	void testRemoveDuplicates();
};


vector<int> SolutionArray::twoSum1(vector<int>& nums, int target) {
	vector<int> sorted(nums);
	sort(sorted.begin(), sorted.end());

	vector<int> result;
	for (int i = 0, j = sorted.size() - 1; i < j; )
	{
		int sum = sorted[i] + sorted[j];
		if (target == sum)
		{
			for (int k = 0; k < nums.size(); k++)
			{
				if (nums[k] == sorted[i])
				{
					result.push_back(k);
				}
				else if (nums[k] == sorted[j])
				{
					result.push_back(k);
				}
				if (result.size() == 2)
				{
					return result;
				}
			}
		}
		else if (target > sum)
		{
			i++;
		}
		else
		{
			j--;
		}
	}


}

vector<int> SolutionArray::twoSum2(vector<int>& nums, int target) {
	map<int, int> m;//key 为 数值， value 为索引
	int sz = nums.size();
	for (int i = 0; i < sz; i++)
	{
		int left = target - nums[i];
		if (m.find(left) != m.end())
		{
			return{ m[left],i };
		}
		m[nums[i]] = i;
	}
}

int SolutionArray::removeDuplicates(vector<int>& nums) {
	int pos = 0;
	int curNum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i == 0)
		{
			curNum = nums[0];
		}
		else
		{
			if (nums[i] != curNum)
			{
				pos++;
				nums[pos] = nums[i];
				curNum = nums[i];
			}
		}
	}
	return pos + 1;
}

void SolutionArray::testRemoveDuplicates() {
	vector<int> nums = { 1,1,1,2,3,4,4};
	int res = removeDuplicates(nums);
	cout << res << endl;
	for (int i = 0; i < res; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}


