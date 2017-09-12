#
# Minimum Time Difference
#
# Given a list of timestamps in HH:mm time format, find the minimum
# time difference in mins between any two timestamps. Note: this works in
# a circular fashion, 23:59 and 00:00 have a difference of 1 min.
#

def convert(time):
    return int(time[:2]) * 60 + int(time[3:])

def findMinDifference(timePoints):

    # Transform list of times into minutes representation
    minutes = list(map(convert, timePoints))
    minutes.sort()

    # Zip and create tuples where element n is paired with element n+1
    # This must be done to accomodate circular nature, shift first element to end

    return min( (y-x) % (24 * 60) for x,y in zip(minutes, minutes[1:] + minutes[:1]) )

def main():
    times = ["00:00", "22:59", "14:35", "12:58", "04:50"]

    print(times)
    print(findMinDifference(times))

main()
