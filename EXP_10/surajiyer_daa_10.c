#include <stdio.h>
#include <string.h>
#include <math.h>

#define d 256

void rabinkarp(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0;
	int t = 0;
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;


	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (i = 0; i <= N - M; i++) {

		if (p == t) {
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j])
					break;
			}
			if (j == M)
				printf("Pattern found at index %d \n", i);
		}
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;
			if (t < 0)
				t = (t + q);
		}
	}
}

int search(char p[30],char t[30], int i)
{
    int f=0;
    for(int k=0;k<strlen(p);k++)
    {
        if(p[k]!=t[k+i])
        {
            f=1;
            break;
        }
    }
    return f;
}

int anum(char alpha)
{
    for(int k=1;k<=26;k++)
    {
        if(alpha=='a'+k-1)
        return k;
    }
}

int main(void)
{
 
    char t[30],p[30];
    printf("\nEnter a sentence : ");
    gets(t);
    printf("\nEnter the word to be searched: ");
    gets(p);
    printf("\nT = %s",t);
    printf("\nP = %s",p);
    printf("\n\n");
    //naive
    printf("\n\nNaive approach : ");
    int x=0;
    for(int k=0;k<strlen(t);k++)
    {
        if(search(p,t,k)==0)
        {
        printf("\nString found from (%d , %ld)",k,k+strlen(p));
        x=1;
        break;
        }
    }
    if(x==0)
    printf("\nString not found!");
    
	printf("\n\nRabin Karp Algorithm: \n");
	int q=101;

    rabinkarp(p, t, q);
    
    return 0;

}
