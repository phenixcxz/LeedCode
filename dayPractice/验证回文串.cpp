/*************************************************************************
    > File Name: 验证回文串.cpp
    > Author: cxz
    > Mail: phenixcxz@163.com 
    > Created Time: 五  6/19 22:30:40 2020
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0;
        int hi = s.size()-1;
        while(lo < hi){
            while((lo < hi) && !isChar(s[lo]))
                lo++;
            while((lo< hi) && !isChar(s[hi]))
                hi--;
            if(!isEqual(s[lo],s[hi]))
                return false;
            lo++;
            hi--;
        }
        return true;
    }
    bool isChar(char r){
        return isNumber(r) || isHiChar(r) ||  isLowChar(r);
    }

    bool isEqual(char & a ,char & b){
        char x = 'a' - 'A';
        if(a == b)
            return true;
        if(isLowChar(a) && isHiChar(b)){

            return b+x == a; 
        }
        if(isHiChar(a) && isLowChar(b))
            return a+x == b;
        return false;
    }
    bool isLowChar(char &ch){
 
        return (ch <= 'z' && ch >= 'a');
    }
    bool isNumber(char &ch){
        return (ch>= '0' && ch <= '9');
    }
    bool isHiChar(char & ch){
        return (ch >= 'A' && ch <= 'Z');
    } 
};


int main(void){
	Solution solution;
	cout << solution.isPalindrome("0P0") << endl;
	return 0;
}
