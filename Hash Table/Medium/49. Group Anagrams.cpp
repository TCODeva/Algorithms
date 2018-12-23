/* LeetCode 49. Group Anagrams
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */
 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> map;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            map[t].insert(s);
        }
        vector<vector<string>> res;
        for (auto m : map) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            res.push_back(anagram);
        }
        return res;
    }
};
