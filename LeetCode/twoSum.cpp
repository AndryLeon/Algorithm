#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(nums.size());
        iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int x, int y){return nums[x] < nums[y];});
        for(size_t i = 0, j = nums.size()-1; i < j; i++){
            while(i < j+1 && nums[v[i]]+nums[v[j]] > target) j--;
            if(nums[v[i]]+nums[v[j]] == target){
                int x = v[i], y = v[j];
                v.clear();
                if(x > y)
                    swap(x, y);
                v.push_back(x+1);
                v.push_back(y+1);
                break;
            }
        }
        return v;
    }
};

int main(){
    vector<int> v = {1,23,6,8,64,3,10};
    Solution s;
    auto r = s.twoSum(v, 13);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}
