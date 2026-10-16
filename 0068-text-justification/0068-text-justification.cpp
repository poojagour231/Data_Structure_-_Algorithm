class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
     
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Step 1: Find words that fit in this line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Step 2: Last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += ' ';
                    }
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                // Step 3: Distribute spaces evenly
                int spaces = (maxWidth - letters) / gaps;
                int extra = (maxWidth - letters) % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int count = spaces;

                        if (k - i < extra) {
                            count++;
                        }

                        line += string(count, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    
  
    }
};