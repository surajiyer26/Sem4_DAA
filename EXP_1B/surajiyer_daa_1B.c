#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int limit = 100000;
const int block = 100;

void insertion_sort (FILE *f) {
	FILE *fp;
	fp = fopen("daa_2_insertion_sort.txt", "w");
    fprintf(fp,"Block Size\tTime Taken\n");
	int size = 0;
	for (int times = 0; times<limit/block; times++) {
		size+=block;
		int arr [size];
		for (int i = 0; i<size; ++i)
			fscanf(f,"%d",&arr[i]);
		// now our array is ready, we perform insertion sort
		clock_t t;
		t = clock();
		int i, key, j;
		for (i = 1; i<size; i++) {
	        key = arr[i];
	        j=i-1;
	        while (j>=0&&arr[j]>key) {
	            arr[j+1] = arr[j];
	            j=j-1;
	        }
	        arr[j+1] = key;
    	}
    	t = clock()-t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    	// storing the result in a file
    	fprintf(fp,"%d\t%lf\n",size,time_taken);
	}
	fclose(fp);
}

void selection_sort (FILE *f) {
	FILE *fp;
	fp = fopen("daa_2_selection_sort.txt", "w");
	fprintf(fp,"Block Size\tTime Taken\n");
	int size = 0;
	for (int times = 0; times<limit/block; times++) {
		size+=block;
		int arr [size];
		for (int i = 0; i<size; ++i)
			fscanf(f,"%d",&arr[i]);
		// now our array is ready, we perform selection sort
		clock_t t;
		t = clock();
		int i, j, mini;
	    for (i = 0; i<size-1; i++) {
	        mini = i;
	        for (j = i+1; j<size; j++) {
	            if (arr[j]<arr[mini])
	            mini = j;
	    	}
           if(mini!=i) {
            	int temp = arr[mini];
            	arr[mini] = arr[i];
            	arr[i] = temp;
        	}
	    }
    	t = clock()-t;
    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
    	// storing the result in a file
    	fprintf(fp,"%d\t%lf\n",size,time_taken);
	}
	fclose(fp);
}

int main () {

	// generating 1,00,000 integers and storing them in a file
	FILE *f;
	f = fopen("daa_2_random_integers.txt", "w");
	for (int i = 0; i<limit; ++i)
		fprintf(f,"%d\n",rand());

	// insertion sort
	insertion_sort(f);

	// selection sort
	selection_sort(f);

	fclose(f);

	return 0;
}