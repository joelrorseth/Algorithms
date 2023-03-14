#
# Length of Last Word
# https://leetcode.com/problems/length-of-last-word/
#
# Return the length of the last word in a space separated string
#


# Finds first valid word from end, return 0 if word DNE
def length_last_word(s):
    words = reversed(s.split(" "))
    return next((len(w) for w in words if len(w) > 0), 0)


# Better solution using two pointers
def length_last_word_ptrs(s):
    """
    :type s: str
    :rtype: int
    """
    l,r = len(s)-1,len(s)-1
    while r>=0 and s[r]==' ':
        r -= 1
        l = r
    while l>=0 and s[l]!=' ':
        l -= 1
        return r-l


# Demonstration
def main():

    s = "This is a sentence"
    print(s, "\nLength of last word:", length_last_word(s))

main()
