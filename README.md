# PeakFinding.cpp
A simple one-day exercise in practicing multithreading applications. It includes a demonstration of how much faster multithreading makes an application for a simple bit of extra code.

# 20 Valid Parenthesis.cpp
A solution to problem #20 on leetcode. This is the first solution I came up with, and it solves for all test cases. Particularly, it solves further test cases such as s="[()]{}" and s="{([])}" as it will iterate backward to find the last unused operator. A faster solution can be reached of size O(n) rather than O(n^2) by pushing the corresponding closing character onto the stack, then when you reach a closing character see if it matches. If it matches, clear it from the stack and iterate forward, if it doesn't match return false.

# 21 Merge Sorted Lists.cpp
A solution to problem #21 on leetcode. In this first solution, I use an iterative approach to the nodes to construct a sorted list. This version solves for all test cases, including ones not supplied by leetcode such as "list1=[1,2,5,7,9], list2=[1,3,4]", where the sizes of the lists are inequal but not of size zero, as is with test case 3 they supply.

# 26 Remove Duplicates from Sorted Array.cpp
A solution to problem #26 on leetcode. Here we use an algorithm to find new elements and add them to the next position for a new unique element in the array by looking behind the selected element to check for uniqueness.

# 2 Add Two Numbers.cpp
A partial solution to problem #2 on leetcode, 1565 / 1569 test cases passed. In this algorithm, I used some string manipulation to achieve the final result, using an unsigned long long integer to handle extremely large numbers. However, the final 4 test cases are larger than 18.4 septillion (>18,446,744,073,709,551,615), causing the test cases to fail. This is reasonable if you are trying to count the number of water molecules in a liter of water (>33.4 septillion), or if you are adding the mass of the Earth (5.98 septillion kg) multiple times.
