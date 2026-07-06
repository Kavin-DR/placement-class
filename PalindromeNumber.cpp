//leetcode 9. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
           return false;
        int orig = x;
        long long reverse;
        while(x != 0){
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }
        if(reverse == orig)
           return true;
        else
           return false;
        }
};
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
           return false;
        int orig = x;
        long long reverse;
        while(x != 0){
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }
        if(reverse == orig)
           return true;
        else
           return false;
        }
};
