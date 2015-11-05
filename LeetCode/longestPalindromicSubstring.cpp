#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
//Manacher’s algorithm

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        int sizea = 2*size+1;
        vector<int> p(sizea);
        string a(sizea, '.');
        for(int i = 0; i < size; i++){
            a[2*i+1] = s[i];
        }
        for(int id, mx = 0, i = 0; i < sizea; i++){
            if(i < mx && p[2*id-i] != mx-i){
                p[i] = min(p[2*id-i], mx-i);
            }
            else{
                id = i;
                mx = max(mx, i);
                while(mx < sizea && 2*id-mx >=0 && a[mx] == a[2*id-mx])
                    mx++;
                p[i] = mx-i;
            }
        }
        int index = max_element(p.begin(), p.end()) - p.begin();
        return s.substr((index-p[index]+1)/2, p[index]-1);
    }
};

int main(){
    Solution so;
    string s("babcbad");
    cout << so.longestPalindrome(s) <<endl;
    return 0;
}
