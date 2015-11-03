#include <iostream>
#include <algorithm>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r = NULL, *t = NULL;
        int c = 0;
        while(l1 || l2){
            if(l1){
                c += l1->val;
                l1 = l1->next;
            }
            if(l2){
                c += l2->val;
                l2 = l2->next;
            }
            ListNode *tmp = new ListNode(c%10);
            c /= 10;
            if(!r){
                r = t = tmp;
            } else{
                t->next = tmp;
                t = tmp;
            }
        }
        if(c){
            t->next = new ListNode(c);
        }
        return r;
    }
};

int main(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(3);
    ListNode *l2 = new ListNode(4);
    l2->next = new ListNode(2);
    Solution s;
    ListNode *t = s.addTwoNumbers(l1, l2);
    cout << t->val << " " << t->next->val << endl;
    return 0;
}
