//给定一个没有重复数字的序列，返回其所有可能的全排列。
class Solution {
private:
   vector<vector<int>> res;
   vector<int> vis; //标志 nums[i] 是否被访问过
   //回溯 index
   void generatePermute(vector<int> tmp,vector<int> nums){
      if(tmp.size() == nums.size()){
         res.push_back(tmp);
      }
      for(int i = 0;i < nums.size();i++){
         if( !vis[i] ){
            vis[i] = 1;
            tmp.push_back(nums[i]);
            generatePermute(tmp,nums);
            tmp.pop_back();
            vis[i] = 0;
         }
      }
   }
public:
   vector<vector<int>> permute(vector<int>& nums) {
      res.clear();
      if(nums.size() < 1)
         res;
      vis = vector<int>(nums.size(),0);
      vector<int> t;
      generatePermute(t,nums);
      return res;
   }
};
