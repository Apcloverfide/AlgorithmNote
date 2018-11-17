//bobo老师

class Solution {
private:
    vector<string> res;
    const string letterMap[10] = {
        " ",//0
        "",//1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mon",//6
        "pqrs",//7
        "tuv",//8
        "wxyz"//9
    };
    //
    void findCombination(const string &digits,int index,const string &s){
        if(index == digits.size()){
            //保存s
            res.push_back(s);
            return;
        }
        
        char c = digits[index];
        assert(c>='0'&&c<='9'&&c!='1');
        string letters = letterMap[c-'0'];
        for(int i = 0;i < letters.size();i++ ){
            findCombination(digits,index + 1,s + letters[i]);
        }
        return ;
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.size() == 0){
            
            return res;
        }
        
        findCombination(digits,0,"");
        return res;
    }
};
