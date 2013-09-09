import java.util.ArrayList;
import java.util.Random;

public class ino {
    
    public static void main (String[] args) {

        long start = System.nanoTime();

        ArrayList<Integer> totals = new ArrayList<Integer>();
        int[] receipts;
        int iterations;
        int done;
        int newnum;
        int totalslength;
        Random rand = new Random();
        String listString;
        int newindex;
        int sum = 0;
        String delim;

        // loop 20 times
        for (int i = 0; i < 1000000; i++) {

            // initialize the receipts array
            receipts = new int[98];
            iterations = 0;
            done = 97;

            // loop until 'done' has been subtracted to zero
            while (done > 0) {

                // generate random number
                newnum = rand.nextInt(97) + 1;

                // if the number is new then mark it as seen
                if (receipts[newnum] == 0) {
                    receipts[newnum] = 1;

                    // decrease 'done'
                    done -= 1;
                }

                // increase this round's count
                iterations += 1;

            }

            // add one to the totals for this number
            totalslength = totals.size();

            // if the array index has been defined increment the value
            if (iterations <= totalslength) {
                totals.set( iterations,( totals.get(iterations) + 1 ) );
            }
            // else add in zero values for all the indices up to the new value and then add the new value as one
            else {
                for (newindex = totalslength; newindex < iterations; newindex += 1 ) {
                    totals.add(0);
                }
                totals.add(1);
            }

        }

        // remove the first elements since the array is zero-based but the range starts at 1
        totals.remove(0);
        listString = "";

        for (int s : totals) {
            listString += s + ", ";
        }

        for (int i : totals) {
            sum += i;
        }

        System.out.println(listString.substring(0, listString.length() - 2));

        long diff = System.nanoTime() - start;
        System.out.println( sum + " iterations in " + (double)diff / 1000000000.0 + " seconds." );

    }
}