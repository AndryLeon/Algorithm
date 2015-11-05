#include <iostream>
#include <ctype.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int r = 0, k = 0, d, size = str.size();
        bool neg = false;
        while(str[k] && isspace(str[k])) k++;
        if(str[k] == '+') k++;
        else if(str[k] == '-'){
            neg = true;
            k++;
        }
        for(; k < size && isdigit(str[k]); k++){
            d = str[k] - '0';
            if(neg){
                if(r < (INT_MIN+d)/10)
                    return INT_MIN;
                r = r*10-d;
            }else{
                if(r > (INT_MAX-d)/10)
                    return INT_MAX;
                r = r*10+d;
            }
        }
        return r;
    }
};

int main(){
    Solution so;
    cout << so.myAtoi("+-1213434") <<endl;
}
