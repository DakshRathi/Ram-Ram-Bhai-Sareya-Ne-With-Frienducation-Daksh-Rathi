class Solution {
private:
    string expandAroundCenter(const string& s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
        left--;
        right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
public:
    string longestPalindrome(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        string longestPalindrome = "";

        for (int i = 0; i < s.length(); i++)
        {
            // Odd-length palindrome
            string palindrome1 = expandAroundCenter(s, i, i);
            if (palindrome1.length() > longestPalindrome.length()) longestPalindrome = palindrome1;

            // Even-length palindrome
            string palindrome2 = expandAroundCenter(s, i, i + 1);
            if (palindrome2.length() > longestPalindrome.length()) longestPalindrome = palindrome2;
        }

        return longestPalindrome;
    }
};