#ifndef LIST_HH
#define LIST_HH
#include <vector>
#include "iostream"
using namespace std;
class ListNode{
public:
    int val;
    ListNode * next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode * createList(vector<int> & nums){
    if(nums.empty())
        return NULL;
    ListNode * head = new ListNode(nums[0]);
    ListNode * p = head;
    for(int i = 1; i < nums.size(); i ++){
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

void printList(ListNode * head){
    cout << endl;
    for(auto i = head; i != NULL; i = i->next){
        cout << i->val << "  ";
    }
    cout << endl;
}

#endif