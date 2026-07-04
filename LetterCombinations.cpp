//leetcode 17. Letter Combinations of a Phone Number

class Solution {
public:
   void sam(string digits,int index,string output,vector<string>& ans,vector<string>& mapping)
   {
    if(index == digits.length())
    {
        ans.push_back(output);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i = 0;i < value.length();i++)
    {
        output.push_back(value[i]);
        sam(digits,index + 1,output,ans,mapping);
        output.pop_back();
    }
   }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length() == 0)
          return ans;
        vector<string>mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        string output = "";
        sam(digits,0,output,ans,mapping);
        return ans;
    }
};
