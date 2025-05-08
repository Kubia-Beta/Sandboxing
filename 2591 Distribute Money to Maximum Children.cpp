class Solution {
public:
    int distMoney(int money, int children) {
        // guard case: 0 kids
        if (children == 0){
            return -1;
        }
        // guard case: less cash then there are kids ($1 rule)
        if (money - children < 0){
            return -1;
        } // No need to hard code an if for <7, our conditionals below get it

        // Max loops on While() = children
        // Longest loop: money = INT_MAX, children = 268,435,455

        int remaining = money - children; // every kid gets $1
        int targetCount = 0;
        while (remaining >= 7 && targetCount < children){ // start creating $8 kids
            targetCount++;
            remaining -= 7;
        } 

        if (remaining == 0){
            return targetCount;
        }

        if (targetCount == children){ // implicit: remaining > 0
            return targetCount - 1; // dump the remainder onto one kid now above $8
        }
        
        int onesChildren = children - targetCount; // number of kids left with $1
        if (remaining == 3 && onesChildren == 1){ // this is the only case where a kid gets $3
            return targetCount - 1; // So we have to give an $8 kid what's left
        }
        return targetCount; // there exists some way to distrubute remaining to children
    }
};