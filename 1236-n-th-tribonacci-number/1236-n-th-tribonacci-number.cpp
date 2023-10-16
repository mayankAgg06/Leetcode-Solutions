class Solution {
public:
    int tribonacci(int n) {

        if(n<3)
        {
            return (n!=0);
        }

        int first=0;
        int second=1;
        int third=1;
        int sum=0;

        for(int i=3; i<=n; i++)
        {
            sum=first+second+third;
            first=second;
            second=third;
            third=sum;
        }

        return third;
        
    }
};