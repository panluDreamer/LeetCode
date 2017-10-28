#ifndef PROBLEM2_H
#define PROBLEM2_H
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//包含多种测试情况
//如899+1,99+1,1+99
/**
*Problem 2: Add Two Numbers   
*/
class Problem2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ans_head = new ListNode(-1);
		ListNode *p = ans_head;
		int temp_sum = 0, carry = 0;
		while (l1 != NULL&&l2 != NULL) {
			temp_sum = (l1->val + l2->val + carry) % 10;
			carry = (l1->val + l2->val + carry) / 10;
			ListNode *temp = new ListNode(temp_sum);
			p->next = temp;
			p = p->next;
			l1 = l1->next;
			l2 = l2->next;
			/*cout << "out" << endl;
			cout << "carry = " << carry << endl;*/
			if (l1 == NULL&&l2 == NULL&&carry != 0) {//carry signal in the end
				//cout << "here" << endl;
				ListNode * t = new ListNode(carry);
				p->next = t;
				p = p->next;
			}
		}
		if (l1 != NULL&&l2 == NULL) {//l2 empty,may be have carry signal
			//cout << "l2 empty" << endl;
			if (carry != 0) {
				int another_carry = (l1->val + carry) / 10;//before calculate l1->val, or l1->val will be the value modified
				l1->val = (l1->val + carry) % 10;
				//cout << "l1->val=" << l1->val << endl;
				//cout << "another_carry = " << another_carry << endl;
				p->next = l1;
				p = p->next;
				ListNode *pre = p;//may be more than one carry ,such as 9998+2
				p = p->next;
				while (p != NULL&&another_carry != 0) {
					//cout << "here" << endl;
					int ac = (p->val + another_carry) / 10;
					p->val = (p->val + another_carry) % 10;
					//ListNode * t = new ListNode(p->val);
					//p->next = t;
					pre = p;
					p = p->next;
					another_carry = ac;
				}
				if (another_carry != 0 && p == NULL) {
					ListNode * t = new ListNode(another_carry);
					pre->next = t;
					pre = pre->next;
				}
			}
			else {
				p->next = l1;
			}

		}
		if (l1 == NULL&&l2 != NULL) {//l1 empty,may be have carry signal
			//cout << "l1 empty" << endl;
			if (carry != 0) {
				int another_carry = (l2->val + carry) / 10;
				l2->val = (l2->val + carry) % 10;
				p->next = l2;
				p = p->next;
				ListNode *pre = p;
				p = p->next;
				//cout << "another_carry = " << another_carry << endl;
				while (p != NULL&&another_carry != 0) {
					//cout << "here" << endl;
					int ac = (p->val + another_carry) / 10;
					p->val = (p->val + another_carry) % 10;
					//ListNode * t = new ListNode(p->val);
					//p->next = t;
					pre = p;
					p = p->next;
					another_carry = ac;
				}
				if (another_carry != 0 && p == NULL) {
					ListNode * t = new ListNode(another_carry);
					pre->next = t;
					pre = pre->next;
				}
			}
			else {
				p->next = l2;
			}
		}
		ans_head = ans_head->next;//ignore additional head node
		return ans_head;
	}
};

#endif