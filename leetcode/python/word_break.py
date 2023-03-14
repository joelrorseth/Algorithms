#
# Word Break
#
# Given a string and a dictionary of valid words, determine if the entire
# string can be segmented into a space separated sequence of dictionary
# words. Eg. s="leetcode", dict={"leet","code"}  => True
#
# Joel Rorseth
#

def wordBreak(s, wordDict):

    dp = [False] * (len(s)+1)
    dp[0] = True

    # Check if s[0..i-1] can be segmented
    #   Must check using 2nd ptr if s[0..i-1] can be split into
    #   s[0..j) and s[j..i-1] such that s[0..j) can be segmented
    #   and s[j..i-1] is in the dict.

    for i in range(1,len(s)+1):
        for j in range(0, i):

            if dp[j] and s[j:i] in wordDict:
                dp[i] = True

    return dp[-1]




# Driver
wordDict = {"leet", "code"}
s = "leetcode"
print(s)
print(wordDict)
print("Can segment?", wordBreak(s, wordDict))
