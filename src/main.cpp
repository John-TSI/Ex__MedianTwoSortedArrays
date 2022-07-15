// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include<iostream>
#include"../inc/solution.hpp"

int main()
{
	//std::vector<int> vec1, vec2{1,2};  // 1.5
	//std::vector<int> vec1{1}, vec2{1,2};  // 1
	//std::vector<int> vec1{1,2}, vec2{3,4};  // 2.5
	//std::vector<int> vec1{3,5,6}, vec2{1,3,4,7,9,12};  // 5
	std::vector<int> vec1{3,5,6,10}, vec2{1,3,4,7,9,12};  // 5.5
	//std::vector<int> vec1{1,2,4,8,10}, vec2{3,6,12};  // 5
	//std::vector<int> vec1{0,3,4,8,9}, vec2{1,3,5,10,11};  // 4.5
	//std::vector<int> vec1{1,3,8,9,15}, vec2{7,11,18,19,21,25};  // 11

	Solution sol{};
	std::cout << sol.findMedianSortedArrays(vec1,vec2) << '\n';
	return 0;
}

