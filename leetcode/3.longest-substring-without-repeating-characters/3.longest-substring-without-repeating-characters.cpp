/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.52%)
 * Total Accepted:    405.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unsigned int max=0;
    	unsigned int ps=0;
    	unsigned int curlen=1;
    	while(ps+curlen<=s.length()) {
    		if(uniqueString(s.substr(ps,curlen))){
    			(max<curlen?max=curlen:1);
    			curlen++;
			} else{
				ps++;
				(curlen>1?curlen--:curlen=1);
			}
		}
        return max;
    }

    bool uniqueString(string s){
    	bool occurred[128];
    	for(int i=0;i<128;i++) occurred[i]=false;
    	bool unique = true;
    	for(int i=0;i<s.length();i++){
    		if(occurred[int(s[i])]){
    			unique=false;
    			break;
			} else {
				occurred[int(s[i])] = true;
			}
		}
    	return unique;
	}
};

