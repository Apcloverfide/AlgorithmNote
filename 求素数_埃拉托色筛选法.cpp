

//埃拉托色筛选法

const long long n = 1000010; //用const 关键字可以开一个大数组
bool p[n]; //false代表是素数
void select_prime(){
    for(int i = 2;i *i < n;i++){
        if(p[i] == false){
            int j = i*i;
            while(j < n){
                p[j] = true; // 非素数
                j = j + i;
            }
        }
    }
}
