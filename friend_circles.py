#
# Friend Circles
#
# There are N students in a class. You are given an NxN matrix M, where if
# M[i][j] == 1, then student i and student j are direct friends. Students may
# also be indirect friends eg. If A <-> B <-> C, then A is indirect friend
# with C. Determine the number of friend circles, defined as disjoint groups of
# students whom are direct or indirect friends.
#
# Joel Rorseth
#

class Solution:

    def find(self, num):
        return num if self.parent_of[num] == num else self.find(self.parent_of[num])

    def union(self, a, b):
        parent_of_a = self.find(a)
        parent_of_b = self.find(b)

        if parent_of_a != parent_of_b:
            self.subset_count -= 1
            self.parent_of[parent_of_a] = parent_of_b

    def findCircleNum(self, M):

        if not M:
            return 0
        if len(M) == 1:
            return 1

        self.parent_of = list(range(len(M)))
        self.subset_count = len(self.parent_of)

        for i in range(len(M)):
            for j in range(len(M[0])):

                # i and j both are friends, unionize their friend groups
                if M[i][j] == 1 and i < j:
                    self.union(i, j)

        # Count of subsets is maintained, decrements when subsets form union
        return self.subset_count




# Driver
sol = Solution()
M = [[1,1,0],[1,1,0],[0,0,1]]
print('\n'.join(str(row) for row in M))
print("There are %d friend circles" % sol.findCircleNum(M))
