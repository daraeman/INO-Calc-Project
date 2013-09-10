<?php
# start timing
	$mtime = microtime();
	$mtime = explode(" ",$mtime);
	$mtime = $mtime[1] + $mtime[0];
	$starttime = $mtime;

$totals[0] = 0;

# loop
for ($i = 1; $i <= 100; $i++) {

	# initialize the receipts array
	$receipts = array_fill(1, 98, 0);
	$iterations = 0;
	$done = 98;

	# loop until 'done' has been subtracted to zero
	while ( $done > 0 ) {

		# generate random number
		$newnum = rand(1,98);

		# if the number is new then mark it as seen
		if ( $receipts[$newnum] == 0 ) {
			$receipts[$newnum] = 1;

			# decrease 'done'
			$done--;
		}

		# increase this round's count
		$iterations++;
	}

	# assign number of indices to var
	$totalslength = count($totals);

	# if the array index has been defined increment the value
	if ( $iterations <= $totalslength) {
		$totals[$iterations]++;
	}
	# else add in zero values for all the indices up to the new value and then add the new value as one
	else {
		for ( $a = $totalslength; $a < $iterations; $a++ )  {
			$totals[$a] = 0;
		}
		$totals[$iterations] = 1;
	}

}
# remove the first elements since the array is zero-based but the range starts at 1
array_shift($totals);
echo implode(", ", $totals)."<br>";

$mtime = microtime();
$mtime = explode(" ",$mtime);
$mtime = $mtime[1] + $mtime[0];
$endtime = $mtime;
$totaltime = ($endtime - $starttime);

echo array_sum($totals)." iterations in ".$totaltime." seconds.";
