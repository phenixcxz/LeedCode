#include "iostream"
#include "vector"
using namespace std;

void createVector(vector<vector<int>> &nums){
    for(int i = 0;i < 5; i ++){
        vector<int> temp;
        for(int j = 0;j < 4; j ++){
            temp.push_back(i*5+j);
        }
        nums.push_back(temp);
    }
}

void printVector(vector<vector<int>> &nums){
    int right = nums[0].size()-1;
    int up = 0;
    int left = 0;
    int down = nums.size()-1; 
    while(right >= left || up <= down){
        for(int i = left; i <= right; i++){
            cout << nums[up][i] << "  ";
        }
        up++; 
        for(int i = up; i <= down; i ++){
            cout << nums[i][right] << "  ";
        }
        right --;
        for(int i = right; i >= left; i --){
            cout << nums[down][i] << "  ";

        }
        down --;
        for(int i = down ; i >= up ; i --){
            cout << nums[i][left] << "  ";
        }
        left ++;
        cout << endl;
    }
}

int main(void){

    vector<vector<int>> nums;
    createVector(nums);

    for(auto i:nums){
        for(auto j:i)
            cout << j << "  ";
        cout << endl;
    }
    printVector(nums);
    return 0;
}