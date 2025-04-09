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
    ListNode* reverseBetween(ListNode* head, int left, int right) { // these are indices, not values, 1 indexed
        // Guard cases:
        // null, size 0, size 1, just return head
        if (head == NULL || head == nullptr || head->next == nullptr){
            return head;
        }
        // No swap case
        if (left == right){
            return head;
        }
        // Special guard, size 2 (flip), use a temp int to flip the data
        if (head->next->next == nullptr){
            int store = head->val;
            head->val = head->next->val;
            head->next->val = store;
            return head;
        }

        // traverse the list, storing each value in a vector of values
        ListNode* tempHead = new ListNode(); 
        tempHead = head; // We use a temp so that we can return the original head node
        ListNode* leftMost = new ListNode(); 
        leftMost = head; // this will hold our position of the start of the reversing area
        vector<int> values = {};
        while (tempHead != NULL){ // As long as there is data
            values.push_back(tempHead->val); // Add the value that lives at the node to the vector
            if (values.size() == left){ // If we access the first reversable node (left)
                leftMost = tempHead; // Set it for later
            }
            tempHead = tempHead->next;
        } // Now that we have every value that lives at the node locations
        tempHead = leftMost; // Move to the area to reverse
        // Now we insert the data in reverse order
        for (int i = right - 1; i > left - 2; i--){ // remember that "left" and "right" are 1 indexed!
            tempHead->val = values.at(i); // Add the value at the rightmost swap node
            tempHead = tempHead->next; // Move to the next node and decrement our index i
        }

        return head;
    }
};