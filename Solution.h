#ifndef SOLUTION_H
#define SOLUTION_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>
using namespace std;
class Solution {

public:
	/**
	Problem 1:Two Sum   
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
	Problem 3:Longest Substring Without Repeating Characters   
	*/
	int lengthOfLongestSubstring(string s) {
		int len = s.length();
		int ans;
		if (len == 0) {
			ans = 0;//exist empty string
		}
		else {
			ans = 1;// init as 1, because may be exist string length of 1
		}
		int i = 0;
		int j = i + 1;
		map<char, bool> m;
		while (j < len) {
			m[s.at(j - 1)] = true;//add to map, record exist char
			if (m[s.at(j)]==false) {//this judge will add one pair to map
				j++;
				if (j == len) {//when reach to end of string,judge the last char of string
					if (j - i>ans) {
						ans = j - i;
					}
				}
			}
			else {
				if (j - i > ans) {//update longest length
					ans = j - i;
				}
				i++;
				j = i + 1;
				m.clear();
			}
		}
		return ans;
	}

	/**
	*Problem 4: Median of Two Sorted Arrays   
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
	/**
	Problem 7:Reverse Integer
	*/
		int reverse(int x) {
			//  -2147483648бл2147483647 [-2^31,2^31-1]
			double ans = 0;//set to double type in case of overflow when calculate reverse number value
			bool positive = true;
			if (x < 0) {
				positive = false;
			}
			stringstream ss;
			ss << x;
			string str, temp;
			str = ss.str();
			int len = str.length();
			int start = positive ? 0 : 1;
			int num_len = len - !positive;
			for (int i = len - 1; i >= start; --i) {
				ans = ans * 10 + str.at(i) - '0';
			}
			if (!positive) {
				ans *= -1;
			}
			if (positive&&ans>pow(2, 31) - 1) {//positive overflow
				ans = 0;
			}
			if (!positive&&ans<-pow(2, 31)) {//negative overflow
				ans = 0;
			}
			return ans;
		}
};

#endif