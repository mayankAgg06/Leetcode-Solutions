class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int> rad,dir;

        int n=senate.length();

        for(int i=0; i<senate.size();i++)
        {
            if(senate[i]=='R') rad.push(i);
            else dir.push(i);
        }

        while(!rad.empty() and !dir.empty())
        {
            if(rad.front()>dir.front())dir.push(n++);
            else rad.push(n++);

            rad.pop();
            dir.pop();
        }

        if(rad.empty())return "Dire";

        return "Radiant";
        
    }
};