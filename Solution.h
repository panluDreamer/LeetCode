#ifndef SOLUTION_H
#define SOLUTION_H
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {

public:
	/**
	*problem 1
	*/
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		int len = nums.size();
		for (int i = 0; i <= len - 2;i++) {
			for (int j = i + 1; j <= len - 1;j++) {
				if (nums[i] + nums[j] == target) {
					ans.push_back(i);
					ans.push_back(j);
					break;
				}
			}
		}
		return ans;
	}
	/**
	*problem 4
	*/
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> partial_merged;
		int len1 = nums1.size();
		int len2 = nums2.size();
		int sum = len1 + len2;
		int merge_count = sum / 2 + 1;
		int curr_merge_count = 0;
		int i = 0, j = 0;
		//partially merge
		while (i <= len1 - 1 && j <= len2 - 1) {
			if (nums1[i] < nums2[j]) {
				partial_merged.push_back(nums1[i]);
				i++;
				curr_merge_count++;
			}
			else {
				partial_merged.push_back(nums2[j]);
				j++;
				curr_merge_count++;
			}
		//	cout << "curr = " << curr_merge_count << endl;
			if (curr_merge_count==merge_count) {
				goto res;
			}
		}
		while (i <= len1 - 1 && j >= len2) {
			partial_merged.push_back(nums1[i]);
			i++;
			curr_merge_count++;
			if (curr_merge_count == merge_count) {
				goto res;
			}
		}
		while (i >= len1&&j <= len2 - 1) {
			partial_merged.push_back(nums2[j]);
			j++;
			curr_merge_count++;
			if (curr_merge_count == merge_count) {
				goto res;
			}
		}
res:
		//cout << "curr_merge = " << curr_merge_count << " merge_count = " << merge_count << endl;
		double ans;
		if (sum % 2 == 0) {
			ans = (partial_merged[merge_count-1] + partial_merged[merge_count - 2]) / 2.0;
		}
		else {
			ans = 1.0*partial_merged[merge_count-1];
		}
		return ans;
	}
};

#endif