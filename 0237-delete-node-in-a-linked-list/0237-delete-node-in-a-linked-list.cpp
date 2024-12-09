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
    void deleteNode(ListNode* node) {
        ListNode*temp=nullptr;
        while(node!=nullptr && node->next!=nullptr){ 
          node->val=node->next->val;
          temp=node;
          node=node->next;
        }
       temp->next=nullptr;
       delete(node); 
    }
};