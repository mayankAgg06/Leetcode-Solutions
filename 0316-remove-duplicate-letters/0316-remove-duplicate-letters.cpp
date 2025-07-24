class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }

        vector<bool> visited(256, false); 
        string ans;

        for (char c : s) {
            counts[c]--; 

            if (visited[c]) { 
                continue;
            }

            while (!ans.empty() && ans.back() > c && counts[ans.back()] > 0) {
                visited[ans.back()] = false; 
                ans.pop_back(); 
            }

            ans.push_back(c);     
            visited[c] = true; 
        }

        return ans;
    }
};