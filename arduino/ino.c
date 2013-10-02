//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int led = 13;
int on = 0;

void setup() {
	pinMode(led, OUTPUT);

	Serial.begin(9600);
	Serial.println("Up and running!");

	for (int a = 10; a > 1; a--) {
		digitalWrite(led, HIGH);
		delay(500);
		digitalWrite(led, LOW);
		delay(250);
		Serial.print(a);
			Serial.print("...");
	}

	Serial.println(" ");
	Serial.println("WRITING....");
	Serial.println("A:");

	for (int b = 0; b < 10; b++) {
		Serial.println(" ");
		Serial.print("b");Serial.print(b);
		Serial.println(" ");
		Serial.println("Done:");
		
		int receipts[98] = {0};
		int receipt_size = sizeof(receipts) / sizeof(int);
		int iterations = 0;
		int done = 97;

		Serial.print("receipts: ");Serial.print(receipt_size);Serial.println(" ");
		Serial.print("iterations: ");Serial.print(iterations);Serial.println(" ");
		Serial.print("done: ");Serial.print(done);Serial.println(" ");

		int newnum;
		while (done > 0) {

			newnum = random(0,97);

			// if the number is new then mark it as seen
			if (receipts[newnum] == 0) {
				receipts[newnum] = 1;

				// decrease 'done'
				done--;
				Serial.print("d");Serial.print(done);
			}
		}
	}

//	clock_t startm, stopm;
//	#define START if ( (startm = clock()) == -1) {printf("Error calling clock");exit(1);}
//	#define STOP if ( (stopm = clock()) == -1) {printf("Error calling clock");exit(1);}
//	#define PRINTTIME printf( "%6.6f seconds used by the processor.\n", ((double)stopm-startm)/CLOCKS_PER_SEC);

//	START;

	// seed rand 
//	srand (time(NULL));
/*
	int totals[10000] = {0};
	int a, b, newnum, newindex, newval, i;

	for (a = 0; a < 10; a++) {
		if (on == 0) {
			on = 1;
			digitalWrite(led, HIGH);
//			Serial.write("ON..");
		}
		else {
			on = 0;
			digitalWrite(led, LOW);
//			Serial.write("OFF..");
		}
		delay(100);
		int receipts[98] = {0};
		int receipt_size = sizeof(receipts) / sizeof(int);
		int iterations = 0;
		int done = 97;

		while (done > 0) {
			// generate random from 1 to 98;
			newnum = random(1,98);

			// if the number is new then mark it as seen
			if (receipts[newnum] == 0) {
				receipts[newnum] = 1;

				// decrease 'done'
				done--;
//				Serial.write("DECREASING..");
			}

			// increase this round's count
			iterations++;
		}

		// increment the total value (we initialized a massive array so no need to check if the index is defined)
		totals[iterations]++;
	}

	int c;
	int sum = 0;

	for (c = 0; c <= (sizeof(totals) / sizeof(int)) - 2; c++) {
		Serial.println(totals[c]);
		//printf("%i,",totals[c]);
		sum += totals[c];
	}

//	STOP;

//	printf("%i\n",totals[c]);
//	printf("%i Iterations in ",sum);
//	PRINTTIME;
*/
}

void loop() {}