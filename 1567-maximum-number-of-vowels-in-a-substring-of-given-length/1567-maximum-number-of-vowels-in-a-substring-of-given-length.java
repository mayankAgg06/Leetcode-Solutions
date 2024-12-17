class Solution {
    public int maxVowels(String s, int k) {
                int count = 0;
        String vowels = "aeiou";

        // Count vowels in the first `k` characters
        for (int i = 0; i < k; i++) {
            if (vowels.indexOf(s.charAt(i)) != -1) {
                count++;
            }
        }

        int j = 0;
        int maxx = count;

        // Sliding window to process the rest of the string
        for (int i = k; i < s.length(); i++) {
            if (vowels.indexOf(s.charAt(j)) != -1) {
                count--;
            }
            if (vowels.indexOf(s.charAt(i)) != -1) {
                count++;
            }

            j++;

            maxx = Math.max(maxx, count);

            // Early exit if maximum possible value is reached
            if (maxx == k) {
                return maxx;
            }
        }

        return maxx;

    }
}