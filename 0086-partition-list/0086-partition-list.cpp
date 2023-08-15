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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* temp = head;
        
        ListNode* ans = new ListNode(0);
        
        ListNode* ans2 = new ListNode(0);
        ListNode* leftTail = ans;
        ListNode* rightTail = ans2;
        
        // now i will add all the node which are less than x 
        while(temp)
        {
            if(temp->val < x)
            {
                leftTail->next = temp;
                leftTail = leftTail->next;
            }
            else
            {
                rightTail->next = temp;
                rightTail = rightTail->next;
            }
            temp = temp->next;
        }
        leftTail->next = ans2->next;
        rightTail->next = nullptr;
        return ans->next;
        
    }
};