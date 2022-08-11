/*
    Given head of a linked list, remove nth node from end of list
    Ex. head = [1,2,3,4,5], n = 2 -> [1,2,3,5]

    Create 2 pointers "n" apart, iterate until end, will be at nth

    Time: O(n)
    Space: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Solution1 (NeetCode) 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (n > 0) {
            fast = fast->next;
            n--;
        }
        
        if (fast == NULL) {
            return head->next;
        }
        
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};


// Solution2 (用dummy的解法)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if (head->next==NULL) {
        //     return NULL;
        // }
        struct ListNode dummy={0, head};
        ListNode* left=&dummy;
        ListNode* right=head;
        
        while (n>0 && right!=NULL) {
            right = right->next;
            n--;
        }
        
        while (right!=NULL) {
            left = left->next;
            right = right->next;
        }
        
        left->next = left->next->next;
        // return head; //不能直接return head，因為有可能就是head被remove掉
        return dummy.next;
    }
};