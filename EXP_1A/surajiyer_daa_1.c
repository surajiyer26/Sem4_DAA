#include <stdio.h>
#include <math.h>

// (3/2)^n
float one (int n) {
	return pow(3/2,n);
}

// ln(ln(n))
float two (int n) {
	return log(log(n));
}

// 2^(log2(n))
float three (int n) {
	return pow(2,log2(n));
}

// log2(log2(n))
float four (int n) {
	return log2(log2(n));
}

// n^3
float five (int n) {
	return pow(n,3);
}

// log2(n)
float six (int n) {
	return log2(n);
}

// log2(n)^log2(n)
float seven (int n) {
	return pow(log2(n),log2(n));
}

// 2^2log2(n)^1/2
float eight (int n) {
	return pow(2,pow(2*log2(n),1/2));
}

// log2(n)^2
float nine (int n) {
	return pow(log2(n),2);
}

// n*2^n
float ten (int n) {
	return n*pow(2,n);
}

// n!
float fact (int n) {
	int ans = 1;
	for (int i = 2; i<n+1; ++i) ans*=i;
	return ans;
}

int main () {

	printf ("Sr No.\tOne\tTwo\tThree\tFour\tFive\tSix\tSeven\tEight\tNine\tTen\tFactorial\n");
	int cnt = 0;
	for (int i = 0; i<101; ++i) {
		printf ("%d\t", i);
		printf ("%f\t", one(i));
		printf ("%f\t", two(i));
		printf ("%f\t", three(i));
		printf ("%f\t", four(i));
		printf ("%f\t", five(i));
		printf ("%f\t", six(i));
		printf ("%f\t", seven(i));
		printf ("%f\t", eight(i));
		printf ("%f\t", nine(i));
		printf ("%f\t", ten(i));
		if (cnt++<21) printf ("%f\t", fact(i));
		printf("\n");
	}

	return 0;
}