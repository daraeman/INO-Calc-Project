# start timing
import time
start = time.time()

# import modules
import array
import random

# initialize the totals array
totals = array.array( 'i' , (0 for i in range(0,2) ) )

# loop
for i in range(100000):

    # initialize the receipts array
    receipts = array.array( 'i' , (0 for i in range(0,98) ) )
    iterations = 0
    done = 98

    # loop until 'done' has been subtracted to zero
    while (done > 0):

        # generate random number
        newnum = random.randint(0,97)

        # if the number is new then mark it as seen
        if receipts[newnum] == 0:
            receipts[newnum] = 1

            # decrease 'done'
            done -= 1

                # increase this round's count
        iterations += 1

    # add one to the totals for this number
    totalslength = len(totals)

    # if the array index has been defined increment the value
    if iterations <= totalslength:
        totals[iterations] += 1

    # else add in zero values for all the indices up to the new value and then add the new value as one
    else:
        for newindex in range( totalslength , iterations ) :
            totals.append(0);
        totals.append(1)

# remove the first elements since the array is zero-based but the range starts at 1
totals.pop(0);
print ", ".join([str(x) for x in totals])
#print "Total Iterations", sum(totals)

print sum(totals), 'iterations in', time.time()-start, 'seconds.'