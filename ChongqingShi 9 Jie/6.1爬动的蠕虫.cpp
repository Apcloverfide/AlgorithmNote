//简单的模拟题
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int T;
    int n,u,d;  //0 < n < 1000,0 < d < 1000
    cin >> T;
    int cur;
    while(T--){
        cin >> n >> u >> d;
        cur = 0; //当前时间离井底的距离
        if(u <= d){
            cout << "The worm cann't escapes from well" << endl;
            continue;
        } 
        int t = 0;
        while(1){
            cur += u;
            t++;
            if(n+1<= cur){
                cout << t << endl;
                break;
            }
            cur -= d;
            t++;
        }
    }
    return 0;
}
