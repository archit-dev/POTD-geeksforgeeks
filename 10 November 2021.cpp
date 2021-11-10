//Question : Check if Linked List is Palindrome

class Solution{
  private:
    Node * reverseList(Node *head){
      Node * prev = NULL;
      Node * curr = head;
      Node * next = NULL;
      while(curr!=NULL){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
      }
      head = prev;
      return head;
  }
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *slow = head;
        Node *fast = head;
        if(head==NULL || head->next==NULL){
            return true;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        } 
        Node *middle = slow;
        slow->next = reverseList(slow->next);
        Node *ptr1= head;
        Node *ptr2 = slow->next;
        while(ptr2!=NULL){
            if(ptr1->data != ptr2->data){
                return false;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        reverseList(middle->next);
        return true;
    }
};
