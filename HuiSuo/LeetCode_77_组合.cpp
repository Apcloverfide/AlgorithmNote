class Solution {
private:
    vector<vector<int> > res;
   // vector<bool>
    void generateCombine(int n,int k,int start,vector<int>& temp){
        if(k == temp.size()){
            res.push_back(temp);
            return;
        }
        if(start > n) return;
        for(int i = start;i <= n;i++){
            temp.push_back(i);
            generateCombine(n,k,i+1,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int> >  combine(int n, int k) {
        if(n < k||n<=0||k<=0)
            return res;
        
        vector<int> temp;
        generateCombine(n,k,1,temp);

        return res;
    }
};
