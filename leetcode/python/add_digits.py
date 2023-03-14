#
# Add Digits
#
# Given a non negative integer, repeatedly add its digits until the result
# only has one digit.
#

def add_digits(num):
    if num % 10 == num: return num

    # Keep list of int digits (fill with dummy data)
    digits = [1,2,3]

    # Until num only has one digit, keep calculating sum
    while len(digits) > 1:
        digits = [int(d) for d in str(num)]
        num = sum(digits)

    return num


def main():
    print(39)
    print("First single digit sum:")
    print(add_digits(39))

main()
