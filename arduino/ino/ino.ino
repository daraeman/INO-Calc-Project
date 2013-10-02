// init totals array (really big cuz its static size)
int totalslength = 100;
int totals[100] = {0};

int led = 13;

int on = 0;

void setup() {
	Serial.begin(9600);
	pinMode(led, OUTPUT);

				for (int a = 10; a > 1; a--) {
					digitalWrite(led, HIGH);
					delay(100);
					digitalWrite(led, LOW);
					Serial.print(a);
					Serial.print(".. ");
					delay(100);
				}

	// number of iterations loop
	for (int i = 1; i <= 3; i++) {
				if (on == 0) {
					digitalWrite(led, HIGH);
					Serial.print("on");
					on = 1;
					delay(1000);
				}
				else {
					digitalWrite(led, LOW);
					Serial.print("off");
					on = 0;
				}
		// init the receipts array with zeroes
		int receipts[98] = {0};
		// init the while decreaser with 98 receipts
		int done = 97;
		// total iterations count
		int iterations = 0;

		// stop when done has been decreased to zerp
		while ( done > 0 ) {
			//Serial.print(done);
			// generate the random number
			int newnum = random(0,97);


			if ( receipts[newnum] == 0 ) {
				receipts[newnum] = 1;

				// decrease 'done'
				done--;
			}

			// increase this round's count
			iterations++;
		}
		Serial.println("\n");

		// if the array index has been defined increment the value
		if ( iterations <= totalslength) {
			totals[iterations]++;
		}
		// else add in zero values for all the indices up to the new value and then add the new value as one
		else {
			for ( int a = totalslength; a < iterations; a++ )  {
				totals[a] = 0;
			}
			totals[iterations] = 1;
		}
		Serial.println("\n");
	}
	// remove the first elements since the array is zero-based but the range starts at 1
	//array_shift($totals);
	int b;
	for (b = 1; b < totalslength; b++) {
		Serial.print(totals[b]);
		Serial.print(",");
	}
	b++;
	Serial.print(totals[b]);

				for (int i = 1; i < 10; i++) {
					digitalWrite(led, HIGH);
					delay(200);
					digitalWrite(led, LOW);
					delay(200);
				}
				digitalWrite(led, LOW);

/*$mtime = microtime();
$mtime = explode(" ",$mtime);
$mtime = $mtime[1] + $mtime[0];
$endtime = $mtime;
$totaltime = ($endtime - $starttime);

echo array_sum($totals)." iterations in ".$totaltime." seconds.";
*/

}

void loop() {}

