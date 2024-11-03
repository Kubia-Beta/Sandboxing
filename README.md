# PeakFinding.cpp
A simple one-day exercise in practicing multithreading applications. It includes a demonstration of how much faster multithreading makes an application for a simple bit of extra code.

# 20 Valid Parenthesis.cpp
A solution to problem #20 on leetcode. This is the first solution I came up with, and it solves for all test cases. Particularly, it solves further test cases such as s="[()]{}" and s="{([])}" as it will iterate backward to find the last unused operator. A faster solution can be reached of size O(n) rather than O(n^2) by pushing the corresponding closing character onto the stack, then when you reach a closing character see if it matches. If it matches, clear it from the stack and iterate forward, if it doesn't match return false.
