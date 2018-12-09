#
# Shortest Distance to a Character
#
# Given a string S and a character C, return an array corresponding to the
# shortest distance from each index to an index which holds C in S.
#
# Joel Rorseth
#

def shortestToChar(S, C):

    e_indices = [i for i, ch in enumerate(S) if ch == C]
    dist = []
    e_ptr = 0
    pleft = None
    pright = e_indices[e_ptr]

    for i in range(len(S)):

        if S[i] == C:
            dist.append(0)
            pleft = pright
            e_ptr += 1
            pright = e_indices[e_ptr] if (e_ptr < len(e_indices)) else None

        else:
            if pleft == None:
                dist.append(abs(pright-i))
            elif pright == None:
                dist.append(abs(pleft-i))
            else:
                dist.append(min( abs(pleft-i), abs(pright-i) ))

    return dist




# Driver
s = "abcdeeeefghijklme"
c = "e"
print("Given  \"" + s + "\" and \'" + c + "\', shortest distances:")
print(shortestToChar(s,c))
