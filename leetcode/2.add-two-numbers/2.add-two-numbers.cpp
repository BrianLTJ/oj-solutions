/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.18%)
 * Total Accepted:    407.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int carry=0;
    	ListNode result(0);
    	ListNode *rp=&result;
    	
        while(l1 || l2 || carry){
        	
    		rp->next=new ListNode(0);
    		rp=rp->next;
    		
    		int val1=(l1?l1->val:0);
    		int val2=(l2?l2->val:0);
    		
        	rp->val=(val1+val2+carry)%10;
    		carry=(val1+val2+carry)/10;
    		
    		cout<< val1 << " " << val2 << " " << carry << endl;
    		l1=(l1?l1->next:l1); l2=(l2?l2->next:l2);
		}
//		while(carry>0){
//			rp->next=new ListNode(carry%10);
//        	rp=rp->next;
//        	carry = carry/10;
//		}
		return result.next;
    }
};
