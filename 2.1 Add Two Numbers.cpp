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

 	/**
	 * Adding two linked list numbers
	 * Time: O(n), θ(n), Ω(n)
	 * Space: O(n)
	 * @param ListNode* list1, ListNode* list2
	 * @return ListNode* result
	 */
class Solution { // An in-place solution can be used if the data structures we are editing are not important to save space.
                 // This algorithm assumes that they are important and should not be changed.
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(); // The head is blank, we use this to access our resulting list by result->next
    ListNode* temp = result;
    int carry = 0;

    while (carry != 0 || l1 != nullptr || l2 != nullptr){ // while we still have numbers to add
        int sum = 0 + carry;

        if (l1 != nullptr){ // if the digit exists, add it
            sum += l1->val;
            l1 = l1->next; // move to the next node
        }
        if (l2 != nullptr){ // remember that both of these can be nullptr, we might have just carry left
            sum += l2->val;
            l2 = l2->next;
        }

        if (sum < 10){ // if our sum is a single digit
            carry = 0; // set our carry to 0
        }
        else {
            sum = sum - 10; // subtract 10 from the double digit value
            carry = 1; // add 1 to the next node
        }

        // make the new node and make it the next node, then iterate forward
        ListNode* newNode = new ListNode(sum);
        temp->next = newNode;
        temp = temp->next;

    } // end while loop

    return result->next;
    }
};