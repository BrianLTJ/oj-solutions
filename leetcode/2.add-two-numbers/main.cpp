#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include "2.add-two-numbers.cpp"

int main(){
    ListNode *a = new ListNode(8);
    a->next = new ListNode(1);
    ListNode *b = new ListNode(0);
//    b->next=new ListNode(9);
//    b->next->next=new ListNode(7);
//    b->next->next->next=new ListNode(9);
	
	Solution s;
	ListNode *r = s.addTwoNumbers(a,b);
	while(r){
		cout<<r->val<< " ";
		r=r->next;
	}
	cout<<endl;
    return 0;
}
