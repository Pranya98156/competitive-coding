class Solution {
public:
    ListNode* ReverseLinkedList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=NULL;
        ListNode* curr=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

   ListNode* MiddleLinkedList(ListNode* head){
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
   }
    bool isPalindrome(ListNode* head) {
       if(head==NULL || head->next==NULL){
        return true;
       }
       ListNode* middle=MiddleLinkedList(head);
       middle->next=ReverseLinkedList(middle->next);
       ListNode* head1=head;
       ListNode* head2=middle->next;
       while(head2){
        if(head1->val!=head2->val){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
       }
       return true;
    }
};