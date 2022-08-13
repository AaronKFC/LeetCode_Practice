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

//Solution 1 (NeetCode)

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while (fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second=slow->next;
        ListNode* first=head;
        slow->next = NULL;
        
        second = reverse(second);
        merge(first, second);
    }

private:
    ListNode* reverse(ListNode* node) {
        ListNode* prev=NULL;
        ListNode* tmp;
        while (node != NULL) {
            // ListNode* tmp = node->next;
            tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        return prev;
    }
    
    
    void merge(ListNode* l1, ListNode* l2) {
        while (l2 != NULL) {
            ListNode* tmp1=l1->next;
            ListNode* tmp2=l2->next;
            l1->next = l2;
            l2->next = tmp1;
            // l1, l2 = tmp1, tmp2;  //why這樣寫會超過time limit？
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};