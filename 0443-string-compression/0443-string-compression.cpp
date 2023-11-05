class Solution {
public:
    int compress(vector<char>& nums) {
        int n=nums.size();
        string s="";
        nums.push_back('*'); // for not getting the error as we will check for nums[i+1] in the loop
        int freq=1;
        for(int i=0;i<n;i++){
            char c=nums[i];
            if(nums[i+1]==c){ //checking if current character is equal to the next character
                freq++;
            }
            else{
                s+=c;
                if(freq>1){ //if freq=1 then no need to append the frequency
                    s+=to_string(freq);
                    freq=1;
                }
            }
        }
        for(int i=0;i<s.length();i++){
            nums[i]=s[i]; // for copying back
        }
        return s.length();
    }
};