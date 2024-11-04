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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // overview:
        // compare the two sizes of the lists
        // if a > b, add a, increase index of a
        // if b > a, add b, increase index of b
        // if a == b, add a, increase index of a
        // if a == null, add b, increase index of b
        // if a == null and b == null, stop

        if (list1 == NULL){ // guard cases if it is null
            return list2;
        } else if (list2 == NULL){
            return list1;
        }

        ListNode* submission; // head node, what we return
        if (list1->val < list2->val){ // if l1 is less than l2
            submission = list1; // construct the head to equal l1
            list1 = list1->next; // then iterate l1
        } else {
            submission= list2;
            list2 = list2->next;
        }
        ListNode* curr = submission; // create the body

        while (list1 && list2){ // while neither are null
            if (list1->val <= list2->val){ // if l1 comes before l2
                curr->next = list1; // assign next to l1
                list1 = list1->next; // then advance l1
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next; // advance curr on each loop end
        }

        if(!list1){ // if we run out of one list sooner than another
            curr->next = list2; // add the remaining bits of the list to it
        } else if (!list2) {
            curr->next = list1;
        }

        return submission;
    }
};