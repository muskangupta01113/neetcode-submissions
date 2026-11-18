
class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> need(256, 0);

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int count = t.length();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];

            if (need[c] > 0) {
                count--;
            }

            need[c]--;

            // All characters are found
            while (count == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char ch = s[left];
                need[ch]++;

                if (need[ch] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
