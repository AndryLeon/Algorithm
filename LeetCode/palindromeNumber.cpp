#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        bool r = false;
        int res = 0, x1 = x;
        for(;x1; x1 /= 10){
            res = res*10+x1%10;
        }
        if(res == x)
            return true;

        return false;
    }
};

int main(){
    Solution so;
    cout << so.isPalindrome(1221) <<endl;
}
