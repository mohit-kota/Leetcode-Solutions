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
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* ans = new ListNode(0);
        ListNode* dum = ans;
        ListNode* temp = head;
        
        dum->next = new ListNode(temp->val);
        dum = dum->next;
        while(temp && temp->next)
        {
            int v1 = temp->val;
            int v2 = temp->next->val;
            int gcmnode = __gcd(v1,v2);
            ListNode* newnode = new ListNode(gcmnode);
            dum->next = newnode;
            dum = dum->next;
            dum->next = new ListNode(v2);
            dum = dum->next;
            temp = temp->next;
        }
        
        return ans->next;
        
    }
};