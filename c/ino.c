#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {

	clock_t startm, stopm;
	#define START if ( (startm = clock()) == -1) {printf("Error calling clock");exit(1);}
	#define STOP if ( (stopm = clock()) == -1) {printf("Error calling clock");exit(1);}
	#define PRINTTIME printf( "%6.6f seconds used by the processor.\n", ((double)stopm-startm)/CLOCKS_PER_SEC);

	START;

	// seed rand 
	srand (time(NULL));

	int totals[10000] = {0};
	int a, b, newnum, newindex, newval, i;

	for (a = 0; a < 100000; a++) {
		int receipts[98] = {0};
		int receipt_size = sizeof(receipts) / sizeof(int);
		int iterations = 0;
		int done = 97;

		while (done > 0) {
			// generate random from 1 to 98;
			newnum = ( ( rand() % 98 ) + 1 );

			// if the number is new then mark it as seen
			if (receipts[newnum] == 0) {
				receipts[newnum] = 1;

				// decrease 'done'
				done--;
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
		printf("%i, ",totals[c]);
		sum += totals[c];
	}

	STOP;

	printf("%i\n",totals[c]);
	printf("%i Iterations in ",sum);
	PRINTTIME;
}