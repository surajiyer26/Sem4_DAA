#include <stdio.h>

int main () {

	// Strassen’s Matrix Multiplication (2x2)

	// initializing the matrices
	printf("Consider two 2x2 matrices named X and Y\n");
	printf("Enter the 4 elements of X:\n");
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("Enter the 4 elements of Y:\n");
	int E, F, G, H;
	scanf("%d %d %d %d", &E, &F, &G, &H);

	// starting the computation
	int M [7];
	M[0] = (A+C)*(E+F);
	M[1] = (B+D)*(G+H);
	M[2] = (A-D)*(E+H);
	M[3] = (A)*(F-H);
	M[4] = (C+D)*(E);
	M[5] = (A+B)*(H);
	M[6] = (D)*(G-E);

	// final matrix
	int I = M[1]+M[2]-M[5]-M[6];
	int J = M[3]+M[5];
	int K = M[4]+M[6];
	int L = M[0]-M[2]-M[3]-M[4];

	// result
	printf("Our matrix Z after computing X*Y=Z is:\n");
	printf("%d %d\n%d %d", I, J, K, L);

	return 0;
}