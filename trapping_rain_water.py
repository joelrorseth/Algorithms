#
# Trapping Rain Water
#
# Given an array of non-negative integers, representing an elevation
# map where each building has width=1, determine the amount of rain
# water that can be trapped within the contained area.
#
# Joel Rorseth
#

def trap(height):

    # Track max height buildings to left & right of all pts
    # Water for a pt is min(tallest left, tallest right) - cur building height

    n = len(height)
    if n == 0 or n == 1:
        return 0

    max_left = [0] * n
    max_right = [0] * n

    # Could omit, point is that there is no left/right for these
    max_left[0] = 0
    max_right[-1] = 0

    max_yet = height[0]
    for i in range(1,n):
        max_left[i] = max_yet
        max_yet = max(max_yet, height[i])

    max_yet = height[-1]
    for i in reversed(range(0,n-1)):
        max_right[i] = max_yet
        max_yet = max(max_yet, height[i])

    water = 0
    for i in range(n):
        w = min(max_left[i], max_right[i]) - height[i]
        if w > 0:
            water += w

    return water



# Driver
rain = [0,1,0,2,1,0,1,3,2,1,2,1]
print(rain)
print("These buildings could trap %d units of water" % trap(rain))
