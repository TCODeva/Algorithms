/* LeetCode 30. Substring with Concatenation of All Words
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 * 
 * Example 1:
 * 
 * Input:
 *   s = "barfoothefoobarman",
 *   words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * Example 2:
 * 
 * Input:
 *   s = "wordgoodstudentgoodword",
 *   words = ["word","student"]
 * Output: []
 */
 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        int ss = s.size(), ws = words.size(); 
        if (ss == 0 || ws == 0) return res;
        unordered_map<string, int> map;
        
        for (int i = 0; i < ws; i++) map[words[i]] += 1;
        
        int wordLen = words[0].size();
        for (int i = 0; i < wordLen; i++) {
            
            unordered_map<string, int> tempMap;
            int left = i, count = 0;
            
            for (int j = i; j <= ss-wordLen; j += wordLen) {
                
                string str = s.substr(j, wordLen);
                
                if (map.count(str)) {
                    tempMap[str]++;
                    
                    if (tempMap[str] <= map[str]) count++;
                    else {
                        while (tempMap[str] > map[str]) {
                            tempMap[s.substr(left, wordLen)]--;
                            left += wordLen;
                            count--;
                        }
                    }
                    
                    if (count == ws) {
                        res.push_back(left);
                        tempMap[s.substr(left, wordLen)]--;
                        count--;
                        left += wordLen;
                    }
                    
                } else {
                    tempMap.clear();
                    count = 0;
                    left = j + wordLen;
                }
                
            }
        }
        return res;
    }
};
