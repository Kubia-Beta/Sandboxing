# PeakFinding.cpp
A simple one-day exercise in practicing multithreading applications. It includes a demonstration of how much faster multithreading makes an application for a simple bit of extra code.

# [1 Two Sum.cpp](https://Leetcode.com/problems/two-sum/submissions/1244450128)
A solution to problem #1 on Leetcode. This algorithm's goal was to be as space-efficient as possible and beat 98% of all other submissions. To increase speed, you would not want two nested for() loops (n^2).

# [2 Add Two Numbers.cpp](https://Leetcode.com/problems/add-two-numbers/submissions/1484996277)
A partial solution to problem #2 on Leetcode, 1565 / 1569 test cases passed (See the next item for the full solution). In this algorithm, I used some string manipulation to achieve the final result, using an unsigned long long integer to handle extremely large numbers. However, the final 4 test cases are larger than 18.4 septillion (>18,446,744,073,709,551,615), causing the test cases to fail. This is reasonable if you are trying to count the number of water molecules in a liter of water (>33.4 septillion), or if you are adding the mass of the Earth (5.98 septillion kg) multiple times.

# [2.1 Add Two Numbers.cpp](https://Leetcode.com/problems/add-two-numbers/submissions/1522662145/)
The full solution to problem #2 on Leetcode, beating 100% of solutions on time complexity and 72.95% if solutions on space complexity. In this algorithm, I move node by node adding the sum of each of the two values one at a time, allowing for any list input of arbitrary length to be added together with another arbitrary list. The space complexity can be cut down, but only if adding l1 and l2 is allowable in-place. In-place changes are dangerous, as other functions may be using these lists. However, if you want the fastest possible algorithm that uses the least amount of space, go for in-place.

# [20 Valid Parenthesis.cpp](https://Leetcode.com/problems/valid-parentheses/submissions/1485000195)
A solution to problem #20 on Leetcode. This is the first solution I came up with, and it solves for all test cases. Particularly, it solves further test cases such as s="[()]{}" and s="{([])}" as it will iterate backward to find the last unused operator. A faster solution can be reached of size O(n) rather than O(n^2) by pushing the corresponding closing character onto the stack, then when you reach a closing character see if it matches. If it matches, clear it from the stack and iterate forward, if it doesn't match return false.

# [21 Merge Sorted Lists.cpp](https://Leetcode.com/problems/merge-two-sorted-lists/submissions/1443541194)
A solution to problem #21 on Leetcode. In this first solution, I use an iterative approach to the nodes to construct a sorted list. This version solves for all test cases, including ones not supplied by Leetcode such as "list1=[1,2,5,7,9], list2=[1,3,4]", where the sizes of the lists are inequal but not of size zero, as is with test case 3 they supply.

# [26 Remove Duplicates from Sorted Array.cpp](https://Leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/1484973838)
A solution to problem #26 on Leetcode. Here we use an algorithm to find new elements and add them to the next position for a new unique element in the array by looking behind the selected element to check for uniqueness.

# [92 Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/submissions/1601135599/)
A solution to problem #92 on Leetcode. In this prequel to #206, I used an in-place algorithm that accesses the data that lives at each node and stores it in a vector to then swap the data that lives at each node, rather than the node pointers to demonstrate knowledge of how to manipulate both correctly. This submission beats 100% of others on Runtime, and 38.56% of others on memory. If you put in the work, you can beat 100% on memory and runtime by swapping the pointers dynamically (see #206), however, this is a more complicated algorithm for this problem than in #206 which can lead to errors.

# [110 Balanced Tree](https://Leetcode.com/problems/balanced-binary-tree/submissions/1581823334/)
A solution to problem #110 on Leetcode. Here we are tasked with examining if any given binary tree is height-balanced. A simple Depth First Search algorithm provides the tools we need to clear all test cases, beating 100% of other algorithms on runtime and 84% in memory complexity.

# [206 Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/submissions/1589509955/)
A solution to problem #206 on Leetcode. In this trivial yet tricky task, we must reverse a singly linked list. I used an in-place two pointer approach, allowing me to beat 100% of users in runtime complexity and 90.71% in memory complexity.

# [226 Invert Binary Tree](https://Leetcode.com/problems/invert-binary-tree/submissions/1583616632/)
A solution to problem #226 on Leetcode. This problem requires that you "swap" the data in a binary tree, so left becomes right. I used an in-place solution leveraging a Depth First Search algorithm paired with a temporary pointer to rotate our left and right pointers between, making this code beat 100% of other algorithms on runtime and 85.9% in memory complexity, as in-place algorithms are very memory efficient. Mathematically, there is no distinction between a binary tree that is ordered left to right versus right to left (ascending vs descending), but programmatically there is a pragmatic difference.

# [242 Valid Anagram]()
A solution to problem #242 on Leetcode. This one is rather self-descriptive, and the solution I used was to map every incoming character to an integer, updating that integer if it had already been mapped, allowing any character to be a part of the anagram. This solution beats 100% of other algorithms on speed and 48.19% on memory while being incredibly flexible. To adapt it to include other cases and languages, simply add a string transform to make sure it is all the same case and consult with someone who knows the language if it is a non-latin descendant language.

# [704 Binary Search](https://Leetcode.com/problems/binary-search/submissions/1485009772)
A solution to problem #704 on Leetcode. Binary search is one of the most basic algorithms you learn in computer science, and it a very powerful one. Truthfully, Binary Search Trees do not really exist, they are merely doubly-linked lists with a complex algorithm (Kolman et al., 2018, p 277).

# [733 Flood Fill](https://Leetcode.com/problems/flood-fill/submissions/1581725666/)
A solution to problem #733 on Leetcode. In this problem we have a 2D array of pixels that need to be filled based on matching colors, which is how a "bucket paint" tool works in programs. My first idea was to go for Depth First Search (DFS) recursion and add guards to prevent repetitive access to keep the time complexity low, and it did, beating 100% in runtime and 59.8% in memory complexity while passing all tests. The proper implementation would be a Breadth First Search (BFS) which has an explicit queue rather than recursion to avoid stack overflow risks at the cost of higher memory usage.

# [1668 Maximum Repeating Substring](https://Leetcode.com/problems/maximum-repeating-substring/submissions/1530421710/)
A solution to problem #1668 on Leetcode. In this solution, I used a simple iterative approach that beats 100% of solutions on time complexity, and without code comments [beats 79.56% of submissions for memory](https://Leetcode.com/problems/maximum-repeating-substring/submissions/1531485182/). It's a simple algorithm where you just repeatedly add a substring to a string and find if that string exists in the provided string.

# [2591 Distribute Money to Maximum Children](https://leetcode.com/problems/distribute-money-to-maximum-children/submissions/1628859288/)
A solution to problem #2591 on Leetcode. I picked this problem because of its low acceptance rate. Here we establish two guard cases, then begin looping to distribute the cash such that there are as many $8 children as possible (the goal). Since we run into the issue of rule 3 "nobody receives 4 dollars" in exactly one scenario, we hardcode it, otherwise we handle the other possible 3 cases with minimal math and memory usage, securing us a submission that beats 100% on runtime and 94.76% on memory.

References

Kolman, B., Busby, R. C., & Ross, S. C. (2018). _Discrete mathematical structures._ Pearson. 
