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
    ListNode* middleNode(ListNode* head) {
        // Guard cases
        // null, size 0, 1, and 2 case

        // return head;

        // move across the linked list storing the number of nodes into an int
        ListNode* tempHead = new ListNode();
        tempHead = head;
        int totalNodes = 0;
        int currentMiddle = 0;
        // have a ListNode that stores the value that is at the middle addres
        ListNode* middle = new ListNode();
        middle = head;
        // Traverse
        // Whenever ceiling(totalNodes / 2) > currentMiddle
        // calculate the distance between currentMiddle and newMiddle = ceiling(totalnodes / 2)
        // call a for loop that moves ->next distance number of times, giving us the new middle.
    }
};