#
# Number of Matching Subsequences
#
# Given a string S, and a set of words, find the number of words that
# are a subsequence of S.
#
# Joel Rorseth
#

from collections import deque, defaultdict

def numMatchingSubseq(S, words):

    word_lookup = defaultdict(deque)

    # Map letters to deques of words that start with that letter
    for w in words:
        word_lookup[w[0]].append(w)

    count = 0
    for c in S:

        # For each char in S, remove first letter from all words that
        # started with it, and move to correct deque

        num_matches = len(word_lookup[c])
        for _ in range(num_matches):

            # Eventually, if word is a subseq, all letters will be removed
            # meaning it was a subseq and each letter was found. Easy!

            w = word_lookup[c].popleft()
            if len(w) == 1:
                count += 1
            else:
                word_lookup[w[1]].append(w[1:])

    return count




# Driver
word = "abcde"
words = ["a", "bb", "acd", "ace"]
print("S =", word, "words =", words)
print("Num words that are subsequences:", numMatchingSubseq(word, words))
