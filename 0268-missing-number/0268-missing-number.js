/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    
     var obj={};
    var ans;

    for(let i=0; i<=nums.length; i++)
    {
        obj[nums[i]]=i;
    }
    for(let i=0; i<=nums.length; i++)
    {
        if(obj[i]==undefined)
        {
            ans=i;
            break;
        }
    }

    return ans;

};