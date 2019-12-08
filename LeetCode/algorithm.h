#pragma once
#include<vector>
#include "iostream"
#include "map"
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

	string intToRoman(int num) {
		string numb;

		vector<int> temp;
		temp.push_back(num / 1000);
		temp.push_back((num%1000) / 100);
		temp.push_back((num % 100) / 10);
		temp.push_back((num % 10));
		while (temp[0]--)
			numb += "M";
		if (temp[1]) {
			if (temp[1] == 9)
				numb += "CM";
			else if (temp[1] == 4)
				numb += "CD";
			else {
				if (temp[1] / 5) {
					numb += "D";
					temp[1] -= 5;
				}
				while (temp[1]--)
					numb += "C";
			}
		}
		if (temp[2]) {
			if (temp[2] == 9)
				numb += "XC";
			else if (temp[2] == 4)
				numb += "XL";
			else {
				if (temp[2] / 5) {
					numb += "L";
					temp[2] -= 5;
				}
				while (temp[2]--)
					numb += "X";
			}
		}
		if (temp[3]) {
			if (temp[3] == 9)
				numb += "IX";
			else if (temp[3] == 4)
				numb += "IV";
			else {
				if (temp[3] / 5) {
					numb += "V";
					temp[3] -= 5;
				}
				while (temp[3]--)
					numb += "I";
			}
		}
		return numb;
	}
};