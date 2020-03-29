class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
        {
            return vector<string>();
        }
        return letterCombinationsCore(digits, 0);
    }
    
    vector<string> letterCombinationsCore(string digits, int index) {
        vector<string> ret;
        
        if (index == digits.size() - 1)
        {
            for (int i = 0; i < smap[digits[index]].size(); i++)
            {
                string s;
                s = s + smap[digits[index]][i];
                ret.push_back(s);
            }
            return ret;
        }
        
        vector<string> tmp = letterCombinationsCore(digits, index + 1);
        
        
        for (int i = 0; i < smap[digits[index]].size(); i++)
        {   
            for (auto & c : tmp)
            {
                ret.push_back(smap[digits[index]][i] + c);
            }
        }
           
        return ret;
        
    }
private:
    map<char, string> smap = {{'2', "abc"}, 
                              {'3', "def"}, 
                              {'4', "ghi"}, 
                              {'5', "jkl"}, 
                              {'6', "mno"}, 
                              {'7', "pqrs"}, 
                              {'8', "tuv"}, 
                              {'9', "wxyz"}};
};