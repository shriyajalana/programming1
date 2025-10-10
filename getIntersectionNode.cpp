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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            int n=0;
            int m=0;
            ListNode* temp=headA;
            while(temp!=NULL){
                    temp=temp->next;
                    n++;
            }
            temp=headB;
            while(temp!=NULL){
                    temp=temp->next;
                    m++;
            }
            // taking as headA is longer
            int d=abs(n-m);
            if(m>n){
                    temp=headA;
                    headA=headB;
                    headB=temp;       
            }
            while(d--){
                    headA=headA->next;
            }
            while(headA!=NULL && headB!=NULL){
                    if(headA==headB){
                            return headA;
                    }
                    headA=headA->next;
                    headB=headB->next;
            }
            return NULL;
        
    }
};
