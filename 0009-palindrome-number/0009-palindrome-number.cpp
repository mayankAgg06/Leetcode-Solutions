class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x>0 and x%10==0)return false;

        int temp=x;
        int y=0;

        while(temp>y)
        {
            int rem=temp%10;
            temp=temp/10;

            y=y*10+rem;    
        }

        if(temp==y || temp==y/10)return true;

        return false;
        
    }
};