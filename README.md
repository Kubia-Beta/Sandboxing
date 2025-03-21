# PeakFinding.cpp
A simple one-day exercise in practicing multithreading applications. It includes a demonstration of how much faster multithreading makes an application for a simple bit of extra code.

# [1 Two Sum.cpp](https://leetcode.com/problems/two-sum/submissions/1244450128)
A solution to problem #1 on leetcode. This algorithm's goal was to be as space-efficient as possible and beat 98% of all other submissions. To increase speed, you would not want two nested for() loops (n^2).

# [2 Add Two Numbers.cpp](https://leetcode.com/problems/add-two-numbers/submissions/1484996277)
A partial solution to problem #2 on leetcode, 1565 / 1569 test cases passed (See the next item for the full solution). In this algorithm, I used some string manipulation to achieve the final result, using an unsigned long long integer to handle extremely large numbers. However, the final 4 test cases are larger than 18.4 septillion (>18,446,744,073,709,551,615), causing the test cases to fail. This is reasonable if you are trying to count the number of water molecules in a liter of water (>33.4 septillion), or if you are adding the mass of the Earth (5.98 septillion kg) multiple times.

# [2.1 Add Two Numbers.cpp](https://leetcode.com/problems/add-two-numbers/submissions/1522662145/)
The full solution to problem #2 on leetcode, beating 100% of solutions on time complexity and 72.95% if solutions on space complexity. In this algorithm, I move node by node adding the sum of each of the two values one at a time, allowing for any list input of arbitrary length to be added together with another arbitrary list. The space complexity can be cut down, but only if adding l1 and l2 is allowable in-place. In-place changes are dangerous, as other functions may be using these lists. However, if you want the fastest possible algorithm that uses the least amount of space, go for in-place.

# [20 Valid Parenthesis.cpp](https://leetcode.com/problems/valid-parentheses/submissions/1485000195)
A solution to problem #20 on leetcode. This is the first solution I came up with, and it solves for all test cases. Particularly, it solves further test cases such as s="[()]{}" and s="{([])}" as it will iterate backward to find the last unused operator. A faster solution can be reached of size O(n) rather than O(n^2) by pushing the corresponding closing character onto the stack, then when you reach a closing character see if it matches. If it matches, clear it from the stack and iterate forward, if it doesn't match return false.

# [21 Merge Sorted Lists.cpp](https://leetcode.com/problems/merge-two-sorted-lists/submissions/1443541194)
A solution to problem #21 on leetcode. In this first solution, I use an iterative approach to the nodes to construct a sorted list. This version solves for all test cases, including ones not supplied by leetcode such as "list1=[1,2,5,7,9], list2=[1,3,4]", where the sizes of the lists are inequal but not of size zero, as is with test case 3 they supply.

# [26 Remove Duplicates from Sorted Array.cpp](https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/1484973838)
A solution to problem #26 on leetcode. Here we use an algorithm to find new elements and add them to the next position for a new unique element in the array by looking behind the selected element to check for uniqueness.

# [704 Binary Search](https://leetcode.com/problems/binary-search/submissions/1485009772)
A solution to problem #704 on leetcode. Binary search is one of the most basic algorithms you learn in computer science, and it a very powerful one. Truthfully, Binary Search Trees do not really exist, they are merely doubly-linked lists with a complex algorithm (Kolman et al., 2018, p 277).

# [733 Flood Fill](https://leetcode.com/problems/flood-fill/submissions/1581725666/)
A solution to problem #733 on leetcode. In this problem we have a 2D array of pixels that need to be filled based on matching colors, which is how a "bucket paint" tool works in programs. My first idea was to go for Depth First Search (DFS) recursion and add guards to prevent repetitive access to keep the time complexity low, and it did, beating 100% in runtime and 59.8% in memory complexity while passing all tests. The proper implementation would be a Breadth First Search (BFS) which has an explicit queue rather than recursion to avoid stack overflow risks at the cost of higher memory usage.

# [1668 Maximum Repeating Substring](https://leetcode.com/problems/maximum-repeating-substring/submissions/1530421710/)
A solution to problem #1668 on leetcode. In this solution, I used a simple iterative approach that beats 100% of solutions on time complexity, and without code comments [beats 79.56% of submissions for memory](https://leetcode.com/problems/maximum-repeating-substring/submissions/1531485182/). It's a simple algorithm where you just repeatedly add a substring to a string and find if that string exists in the provided string.

References

Kolman, B., Busby, R. C., & Ross, S. C. (2018). _Discrete mathematical structures._ Pearson. 
