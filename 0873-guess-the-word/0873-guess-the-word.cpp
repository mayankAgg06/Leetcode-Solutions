/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    string findingOverlaps(vector<string>& wordlist)
    {
        vector<vector<int>> freq(6,vector<int>(26,0));

        for(string word: wordlist)
        {
            for(int i=0; i<6; i++)
            {
                freq[i][word[i]-'a']++;
            }
        }

        int best_score=0;
        string best_word="";

        for(string word:wordlist)
        {
            int score=0;
            for(int i=0; i<word.length(); i++)
            {
                score+=freq[i][word[i]-'a'];
            }

            if(score>best_score)
            {
                best_score=score;
                best_word=word;
            }
        }

        return best_word;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> wordlist = words;

        while(wordlist.size()>0)
        {
            string closest_word= findingOverlaps(wordlist);
            int match = master.guess(closest_word);

            if(match==6)return;

            vector<string> new_wordlist;

            for(string word:wordlist)
            {
                int m=0;
                for(int i=0; i<6; i++)
                {
                    if(word[i]==closest_word[i]) m++;
                }

                if(m==match) new_wordlist.push_back(word);
            }

            wordlist = new_wordlist;
        }

    }
};