#
# Largest Number At Least Twice of Others
#
# Given an array of numbers, determine if the largest number is greater
# than or equal to each other number's double.
#
# Joel Rorseth
#

def dominantIndex(nums):

    biggest = -1
    biggest_index = -1
    second_biggest = -1
    second_biggest_index = -1

    for i, num in enumerate(nums):

        if num > biggest:
            second_biggest = biggest
            second_biggest_index = biggest_index
            biggest = num
            biggest_index = i


        elif num > second_biggest:
            second_biggest = num
            second_biggest_index = i

    if biggest >= (2 * second_biggest):
        return biggest_index
    else:
        return -1


# Driver
a = [1,2,3,4,20]
print(a)
print("Largest number >= double all others? Index =", dominantIndex(a))
