#pragma once
#include<vector>
#include "iostream"
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int size = height.size();
		int lo = 0; 
		int hi = size-1;
		int max = 0;
		while (lo < hi) {
			int temp = 0;
			if (height[lo] < height[hi]) {
				temp = height[lo] * (hi - lo);
				lo++;
			}
			else {
				temp = height[hi] * (hi - lo);
				hi--;
			}
			if (max < temp)
				max = temp;
		}
		return max;
	}
};