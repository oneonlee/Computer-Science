#include <stdio.h>
#include <cmath>

int enc(int M, int e, int n);
int dec(int C, int d, int n);
int compute_pow(int a, int b, int m);
int select_e(int phi1, int p, int q);
int compute_phi2(int phi1);
int GCD(int a, int b);

int main()
{
	printf("enter p and q, two prime numbers\n");
	int p, q;
	scanf("%d %d", &p, &q);
	// step 1. compute n
	int n = p * q;
	// step 2. compute phi1
	int phi1 = (p - 1) * (q - 1);
	int e;
	int phi2;
	int d;

	for (;;)
	{
		// step 3. select e
		e = select_e(phi1, p, q);

		// step 4. compute phi2
		phi2 = compute_phi2(phi1);

		// step 5. compute d
		d = compute_pow(e, phi2 - 1, phi1);
		if (e == d)
			printf("not suitable e. select another one\n");
		else
		{
			printf("(%d %d) are ok to use ", e, d);
			break;
		}
	}
	printf("p:%d q:%d n:%d phi1:%d e:%d phi2:%d d:%d\n",
		   p, q, n, phi1, e, phi2, d);
	// now encrypt
	printf("enter num to encrypt\n");
	int M, C;
	scanf("%d", &M);
	C = enc(M, e, n);
	printf("M:%d C:%d\n", M, C);
	int Mp = dec(C, d, n);
	printf("Mp:%d\n", Mp);
}
int enc(int M, int e, int n)
{
	return compute_pow(M, e, n);
}
int dec(int C, int d, int n)
{
	return compute_pow(C, d, n);
}
int compute_pow(int a, int b, int m)
{
	unsigned long long int power = (unsigned long long int)pow(a, b);
	printf("%llu\n", power);
	return power % m; // return a^b mod m
}

int select_e(int phi1, int p, int q)
{
	printf("Choose 'e' and Enter one of the numbers below.\n");

	// display relative prime numbers to phi1
	for (int i = 2; i <= phi1 + 1; i++)
	{
		if (p % i == 0 or q % i == 0)
			continue;
		else
			printf("%d ", i);
	}
	// let user select one of them
	printf("\nSelect \'e\': ");

	int e;
	scanf("%d", &e);
	return e;
}

int compute_phi2(int phi1)
{
	int cnt = 0;
	for (int i = 1; i < phi1; i++)
	{
		if (GCD(phi1, i) == 1)
			cnt++;
	}
	return cnt; // return num of relative prime numbers to phi1
}

int GCD(int a, int b)
{
	int gcd;
	for (int i = 1; i <= a && i <= b; ++i)
	{
		// Checks if i is factor of both integers
		if (a % i == 0 && b % i == 0)
			gcd = i;
	}

	return gcd; // return GCD of a, b
}
