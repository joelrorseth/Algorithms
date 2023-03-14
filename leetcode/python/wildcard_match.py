#
# Wildcard Matching
#
# Given a string and a pattern, implement wildcard matching with support
# for ? and *.
#
# DP solution breaks the regex match into subproblems for smaller parts
# of the pattern and string. It must continually match for smaller inputs.
#
#     [] a ? c           [] a ? c
#  [] T  F F F        [] T  F F F
#  a  F  F F F   =>   a  F  T F F
#  b  F  F F F        b  F  F T F
#  c  F  F F F        c  F  F F T
#
# Joel Rorseth
#

def isMatch(st, pat):

    # Row for each char in string, Column for each char in pattern
    dp = [[False for _ in range(len(pat)+1)] for _ in range(len(st)+1)]
    dp[0][0] = True

    # Account for leading *s in the pattern
    for j in range(1,len(pat)+1):
        if pat[j-1] == '*':
            dp[0][j] = dp[0][j-1]

    for i in range(1, len(st)+1):
        for j in range(1, len(pat)+1):

            # If char matches pattern, problem reduces to previous pat and str
            if pat[j-1] == st[i-1] or pat[j-1] == '?':
                dp[i][j] = dp[i-1][j-1]

            # Wildcard will match, problem reduces to previous pat or prev str
            elif pat[j-1] == '*':
                dp[i][j] = dp[i-1][j] or dp[i][j-1]

    return dp[-1][-1]




# Driver
s = "adceb"
p = "*a*b"
print("String:", s, ", Pattern:", p)
print("Matches?", isMatch(s,p))
