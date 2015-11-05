#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128, -1);
        int l = -1;
        int r = 0;
        int size = s.size();
        for(int i = 0; i < size; i++){
            l = max(l, v[s[i]]);
            r = max(r, i-l);
            v[s[i]] = i;
        }
        return r;
    }
};

int main(){
    string s("hellohel");
    Solution S;
    cout << S.lengthOfLongestSubstring(s) <<endl;
}
