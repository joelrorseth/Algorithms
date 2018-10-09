#
# Isomorphic Strings
#
# Determine if two strings A and B are isomorphic. Two strings are isomorphic
# if the characters in A can be replaced / remapped to get B.
#
# eg. paper , title  => true
#
# Joel Rorseth
#

def isIsomorphic(s, t):
    return isIso(s,t) and isIso(t,s)

# Determine if there is a valid character mapping from s -> t
def isIso(s, t):
    char_map = [''] * 128

    for i in range(len(s)):

        mapped_char = char_map[ord(s[i]) - ord('a')]
        if mapped_char != "" and mapped_char != t[i]:
            return False

        char_map[ord(s[i]) - ord('a')] = t[i]

    return True






# Driver
s = "paper"
t = "title"
print(s, t)
print("Isomorphic?", isIsomorphic(s,t))
