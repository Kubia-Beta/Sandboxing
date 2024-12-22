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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // C String based solution
    ListNode* solution = new ListNode();
    string firstNum = "";
    string secondNum = "";
    string solutionNum = "";
    // loop through l1 adding each new item to the front of firstNum
    while (l1 != nullptr){
        firstNum += to_string(l1->val);
        l1 = l1->next;
    }
    // loop through l2 adding each new item to the front of secondNum
    while (l2 != nullptr){
        secondNum += to_string(l2->val);
        l2 = l2->next;
    }
    reverse(firstNum.begin(), firstNum.end());
    reverse(secondNum.begin(), secondNum.end());
    // cast firstNum and secondNum to int since we need to do math on it
    unsigned long long int targetNum = stoull(firstNum) + stoull(secondNum);
    // build targetNum into a linked list by casting it back to string
    solutionNum = to_string(targetNum);
    reverse(solutionNum.begin(), solutionNum.end());
    char c = solutionNum[0];
    solution->val = static_cast<int>(c) - '0';

    ListNode* currNode = solution;
    for (int i = 1; i < solutionNum.length(); i++){
        c =  solutionNum[i];
        ListNode* newNode = new ListNode(static_cast<int>(c) - '0');
        currNode->next = newNode; 
        currNode = newNode;
    }

    return solution;
    }
};