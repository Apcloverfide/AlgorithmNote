//很简单的字符串处理
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int T;
    string s;
    cin >> T;
    int i;
    while(T--){
        cin >> s;
        int len = s.size();
        for(i = 0;i < len - i - 1;i++){
            if(s[i] != s[len - i - 1]){
                cout << s <<" is not a apa1indromic number." << endl;
                break;
            }
        }
        if(i == len/2)
            cout << s <<" is a apa1indromic number." << endl;
    }

    return 0;
}
