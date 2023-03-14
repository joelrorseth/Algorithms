#
# Student Attendance Record 1
#
# Given a string representing a student's attendance record, with
# A: Absent, L: Late, P: Present, determine if a student can be
# rewarded. A student can be rewarded if he/she has not been absent
# more than once, and hasnt been late more than two consecutive times.
#

from collections import Counter

def checkRecord(s):

    counter = Counter(s)
    return counter['A'] <= 1 and s.find("LLL") == -1

def main():
    print("PPALLP")
    print("Should this student be rewarded?")
    print(checkRecord("PPALLP"))


main()
