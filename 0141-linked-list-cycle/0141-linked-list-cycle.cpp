class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Move slow pointer by one step
            fast = fast->next->next;     // Move fast pointer by two steps
            
            if (slow == fast) {
                return true;            // Cycle detected
            }
        }
        
        return false;                    // No cycle detected
    }
};
