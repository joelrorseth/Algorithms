#
# Simplify Path
# Simplify a given UNIX style path.
#

from itertools import takewhile

def simplify_path(path):
    
    # Use a stack to model increasing directory traversal depth
    stack = []
        
    # Go through each directory name
    comps = [p for p in path.split("/") if p!="." and p!=""]
    for d in comps:
            
        # Pop directory off stack to nav up a directory
        if d == "..":
            if stack:
                stack.pop()
            
        # Anything else should be a valid directory to index into
        else:
            stack.append(d)
                    
    return "/" + "/".join(stack)


def main():

    direc = "/a/./b/../../c/"
    print(direc)
    print("Simplified path: ")
    print(simplify_path(direc))

main()
