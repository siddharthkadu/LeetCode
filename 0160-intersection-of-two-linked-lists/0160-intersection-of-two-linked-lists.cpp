class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Initialize two pointers to the heads of the two lists
        ListNode *pointerA = headA;
        ListNode *pointerB = headB;
        
        // Traverse both lists
        while (pointerA != pointerB) {
            // If pointerA reaches the end of list A, redirect it to headB
            if (pointerA == nullptr) {
                pointerA = headB;  // Move pointerA to the head of list B
            } else {
                pointerA = pointerA->next;  // Otherwise, move pointerA to the next node in list A
            }

            // If pointerB reaches the end of list B, redirect it to headA
            if (pointerB == nullptr) {
                pointerB = headA;  // Move pointerB to the head of list A
            } else {
                pointerB = pointerB->next;  // Otherwise, move pointerB to the next node in list B
            }
        }
        
        // Either they meet at the intersection point or both are nullptr (no intersection)
        return pointerA;
    }
};
