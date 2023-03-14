#
# Generate Parentheses
#
# Given n pairs of parentheses, determine all combinations of well
# formed parentheses.
#
# Joel Rorseth
#

def generateParenthesis(n):
    combs = []
    generate(n, n, "", combs)
    return combs


# Solution is easy, just backtrack all solutions by counting the number
# of open/closed parenths, add valid combinations and recurse
def generate(n_open, n_close, s, combs):

    if n_open == 0:
        combs.append(s + (")" * n_close))

    else:
        if n_open > 0:
            generate(n_open-1, n_close, s+"(", combs)

        if n_close > 0 and n_close > n_open:
            generate(n_open, n_close-1, s+")", combs)



# Driver
print("For n=3, combinations:\n", generateParenthesis(3))
