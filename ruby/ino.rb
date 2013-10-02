# start timing
start = Time.now

# rand function for ruby 1.8.7 (1.9.2 has range built into rand(), plus this one includes the last number)
def rand_better(x, y)
	rand((y+2) - x) + (x -1)
end

# initialize the totals array
totals = Array.new

maxit = 0

# loop
for i in 1..1000000

	# initialize the receipts array
	receipts = Array.new(98,0)
	iterations = 0
	done = 98

	# loop until 'done' has been subtracted to zero
	while done > 0

		# generate random number
		newnum = rand_better(1,98)

		# if the number is new then mark it as seen
		if receipts[newnum] == 0
			receipts[newnum] = 1

			# decrease 'done'
			done -= 1
		end

		# increase this round's count
		iterations += 1
	end

	# assign number of indices to var
	totalslength = totals.length

	# if the array index has been defined increment the value
	if iterations <= totalslength
		totals[iterations] += 1

	# else add in zero values for all the indices up to the new value and then add the new value as one
	else
		for newindex in totalslength..(iterations - 1)
			totals << 0;
		end
		totals << 1
	end

end
# remove the first elements since the array is zero-based but the range starts at 1
totals.shift;
print totals * ','

print "\n",totals.inject(:+), " iterations in #{Time.now - start} seconds.\n"
