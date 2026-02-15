//
// Created by Diego Gomes Tomé on 15/02/2026.
//

#pragma once
#include <cassert>
#include <unordered_map>
#include <vector>
/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Input: n = 4
Output: 7
1. 1 step + 1 step + 1 step + 1 step
2. 1 step + 2 steps + 1 step
3. 1 step + 1 step + 2 steps
4. 2 steps + 1 step + 1 step
5. 2 steps + 2 steps
6. 1 step + 3 steps
7. 3 steps + 1 step

Constraints:

1 <= n <= 45

(n-1 + 1)
*/

using namespace std;

// works but it is not time efficient since it is O(2ˆn)
int climbStairs(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	return climbStairs(n - 1) + climbStairs(n - 2);
}

std::__1::unordered_map<int, int> memo;
int climbStairsMemo(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	if (memo.find(n) != memo.end()) {
		return memo[n];
	}
	memo.emplace(n, climbStairs(n - 1) + climbStairs(n - 2));
	return memo[n];
}

void run_climbStairs() {
	std::vector<int> test1 = {1, 2, 3, 4,5,45};
	assert(climbStairsMemo(test1[4]) == 5);
	for (auto n : test1) {
		std::cout << "Input: " << n << " Output: " << climbStairsMemo(n);
	}
}