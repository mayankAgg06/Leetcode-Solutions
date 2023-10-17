class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int size= flowerbed.size();
        int i=0;

        if(n>size)return false;

        if(size==1) return ((n==1 and flowerbed[0]==0)||(n==0));
        
        while(i<size)
        {
            if(i==0)
            {
                if(flowerbed[i]==0 and flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }
            }

            else if(i==size-1)
            {
                if(flowerbed[i]==0 and flowerbed[i-1]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }   
            }

            else
            {
                if(flowerbed[i]==0 and flowerbed[i+1]==0 and flowerbed[i-1]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }   
            }

            i++;
        }

        if(n<=0)return true;


        return false;
    }
};