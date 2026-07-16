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
class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        // Calculate total nodes
        int total = 1;
        ListNode *temp = head;

        while (temp->next != NULL) {
            total++;
            temp = temp->next;
        }

        int flist = (total + 1) / 2;   // First half gets extra node if odd

        ListNode *left = head;
        ListNode *head1 = head;

        int n = flist - 1;
        while (n > 0) {
            left = left->next;
            n--;
        }

        // Split list
        ListNode *curr = left->next;
        left->next = NULL;

        // Reverse second half
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode *list1 = head1;
        ListNode *list2 = prev;

        // Merge alternately
        while (list1 != NULL && list2 != NULL) {
            ListNode *next1 = list1->next;
            ListNode *next2 = list2->next;

            list1->next = list2;

            if (next1 == NULL)
                break;

            list2->next = next1;

            list1 = next1;
            list2 = next2;
        }
    }
};