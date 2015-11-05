#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        for(;x; x /= 10){
            if((10*r)/10 != r )
                return 0;
            r = 10*r + x%10;
        }
        return r;
    }
};

int main(){
    Solution so;
    cout << so.reverse(-123) <<endl;
}
