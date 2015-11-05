#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int ssize = s.size();
        string r;
        for(int i = 0; i < numRows; i++){
            for(int j = i; j < ssize; j += 2*numRows -2){
                r += s[j];
                if(0 < i && i < numRows-1 && j+(numRows-1-i)*2 < ssize){
                    r += s[j+(numRows-1-i)*2];
                }
            }
        }
        return r;
    }
};

int main(){
    Solution so;
    string s("PAYPALISHIRING");
    cout << so.convert(s, 3) <<endl;
    return 0;
}
