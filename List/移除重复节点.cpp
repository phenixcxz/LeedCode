#include "List.h"
#include<iostream>
#include"vector"

using namespace std;
class Solution {
public:
    // ListNode* removeDuplicateNodes(ListNode* head) {
    //     for(auto i = head; i != NULL; i = i->next){
    //         ListNode * preNode = i;
    //         for(auto j = i->next; j != NULL; j = j->next){
    //             if(i->val == j->val){
    //                 preNode->next = j->next;
    //                // j = preNode->next;
    //             }
    //             else{
    //                 preNode = j;
    //             }

    //         }
    //     }
    //     return head;
    // }
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode * lastNode = head;
        for(auto i = head->next; i != NULL; i = i->next){
            auto j = head;
            for(; j != lastNode->next; j  = j->next){
                if(j->val == i->val){
                    break;
                }
            }
            if(j == lastNode->next){
                lastNode->next = i;
                lastNode = i;
            }
        }
        lastNode->next = NULL;
        return head;
    }
};

int main(){
    vector<int> nums = {1,2,3,3,2,1};
    ListNode * head = createList(nums);
    printList(head);

    Solution solution;
    head = solution.removeDuplicateNodes(head);
    printList(head);

    return 0;
}