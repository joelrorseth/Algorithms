#
# Group Anagrams
# Given a list of strings, group anagrams together
#

from collections import defaultdict

# Solution
def group_anagrams(strs):

    groups = defaultdict(list)

    # Map strings to its sorted anagram
    # For optimal solution, could use counting sort for O(n) sort

    for s in strs:
        groups[''.join(sorted(s))].append(s)

    return [lst for lst in groups.values()]


# Demonstration
def main():

    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    groups = group_anagrams(strs)

    print("Strings:", strs)
    print("Groups:", groups)

main()
