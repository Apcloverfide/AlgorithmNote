
//背包问题的一维实现
//01背包
for(int i = 1;i <= n;i++){ //
    for(int j = maxv;j >= c[i];j--){
        f[j] = max(f[j], f[j - c[i]] + w[i]);
    }
}

//完全背包
for(int j = 1;j <= maxv;j++){
    for(int i = 1;i <= n;i++ ){ //每次便利所有的物品
        if(j >= v[i]){
            f[j] = max(f[j],f[j-v[i]] + w[j]);
        }
    }
}
