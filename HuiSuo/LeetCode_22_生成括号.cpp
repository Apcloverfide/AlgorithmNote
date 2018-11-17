

class Solution {
private:
   vector<string> res;
   void findParenthesis(int n, int index,const string &s,int flag){
      if(flag < 0 || flag > n)
         return;
      if(n*2 == index){
         if(flag == 0)  
            res.push_back(s);
         return;
      }
      findParenthesis(n,index + 1,s + '(',flag + 1);
      findParenthesis(n,index + 1,s + ')',flag - 1);
   }
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
         findParenthesis(n,0,"",0);
         return res;
    }
};
