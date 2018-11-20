#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int main(){
    int k;
    string s1,s2;
    cin >> k; //朋友答案对的个数
    cin >> s1 >> s2;
    int x = 0,n = s1.size();
    for(int i = 0;i < s1.size();i++){
        if(s1[i] == s2[i])
            x++;
    }
    int ans;
    if(x == k){
        ans = k;
    } else{
        ans = n - abs(k - x);
    }
    cout << ans << endl;
}
/*2
TTFFT
T
*/
