class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int size= flowerbed.size();
        int i=0;

        if(n>size)return false;

        if(size==1) return ((n==1 and flowerbed[0]==0)||(n==0));
        
        while(i<size)
        {
            if(flowerbed[i]==0)
            {
                if(i==0)
                {
                    if(flowerbed[i+1]==0)
                    {
                        flowerbed[i]=1;
                        n--;
                    }
                }
                else if(i==size-1)
                {
                    if(flowerbed[i-1]==0)
                    {
                        flowerbed[i]=1;
                        n--;
                    }
                }
                else
                {
                    if(flowerbed[i+1]==0 and flowerbed[i-1]==0)
                    {
                        flowerbed[i]=1;
                        n--;
                    }
                }

            }
            // if(i==0)
            // {
            //     if(flowerbed[i]==0 and flowerbed[i+1]==0)
            //     {
            //         flowerbed[i]=1;
            //         n--;
            //     }
            // }

            // else if(i==size-1)
            // {
            //     if(flowerbed[i]==0 and flowerbed[i-1]==0)
            //     {
            //         flowerbed[i]=1;
            //         n--;
            //     }   
            // }

            // else
            // {
            //     if(flowerbed[i]==0 and flowerbed[i+1]==0 and flowerbed[i-1]==0)
            //     {
            //         flowerbed[i]=1;
            //         n--;
            //     }   
            // }

            i++;
        }

        if(n<=0)return true;


        return false;

        // if (n == 0) {
        //     return true;
        // }
        // for (int i = 0; i < flowerbed.size(); i++) {
        //     if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
        //         flowerbed[i] = 1;
        //         n--;
        //         if (n == 0) {
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};