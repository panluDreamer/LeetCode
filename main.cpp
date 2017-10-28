#include<iostream>
#include "Solution.h"
#include "Problem2.h"
using namespace std;
unsigned int swap_endian(unsigned int val) {
	val = ((val << 8) & 0xFF00FF00 | ((val >> 8) & 0xFF00FF));
	return (val << 16) | (val >> 16);
}
void print_list(ListNode * head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}
int main() {
	string str("pwwkew");
	Solution s;
	int ans = 0;
	ans = s.lengthOfLongestSubstring(str);
	cout << "ans = " << ans << endl;

	//Problem2 problem2;
	//ListNode * l1, *l2,*temp1,*temp2;
	//ListNode * num1, *num2,*num3;
	//ListNode *p1, *p2, *p3;
	//num1 = new ListNode(1);
	//l1 = num1;
	//temp1 = num1;
	///*num2 = new ListNode(9);
	//temp1->next = num2;
	//temp1 = temp1->next;
	//num3 = new ListNode(9);
	//temp1->next = num3;
	//temp1 = temp1->next;*/
	//temp1->next = NULL;
	//p1 = new ListNode(9);
	//l2 = p1;
	//temp2 = p1;

	//p2 = new ListNode(9);
	//temp2->next = p2;
	//temp2 = temp2->next;

	///*p3 = new ListNode(9);
	//temp2->next = p3;
	//temp2 = temp2->next;*/
	//temp2->next = NULL;
	//cout << "l1:";
	//print_list(l1);
	//cout << endl;
	//cout << "l2:";
	//print_list(l2);
	//cout << endl;
	//ListNode *ans;
	//ans = problem2.addTwoNumbers(l1, l2);
	//cout << "ans:";
	//print_list(ans);
	//cout << endl;

}