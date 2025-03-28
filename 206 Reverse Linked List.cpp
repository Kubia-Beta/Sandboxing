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
    ListNode* reverseList(ListNode* head) {
        // Guard Case
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        // solution 1:
        // iterate through the list
        // store each item into a vector
        // once the end of the list is reached, read the vector backwards
        // i.e. vector.end(), end()-1, end()-2, etc.
        // add items ListNode(int end(), ListNode *end()-1)
        // return the node end()

        // solution 2: in-place
        // create a reference node temp = head->next
        ListNode* temp = new ListNode();
        temp = head->next;
        // create a reference node previous = head
        ListNode* previous = new ListNode();
        previous = head;
        // head = head->next
        head = head->next;
        // previous->next = nullptr (end head node case)
        previous->next = nullptr;
        // while head->next != nullptr (stops one before the list is fully traversed)
        // while head != NULL (this stops once we have finished reversing)
        while (head != NULL){
            temp = temp->next;
            head->next = previous;
            previous = head;
            head = temp;
        }
        return previous; // previous points to the new head node, as temp and head are NULL
    }
};