/*
RSA  algorithm

Algorithm
1.Generate two large random primes, P and Q, of approximately equal size.
2.Compute N = P x Q
3.Compute Z = (P-1) x (Q-1).
4.Choose an integer E, 1 < E < Z, such that GCD (E, Z) = 1
5.Compute the secret exponent D, 1 < D < Z, such that E x D ≡ 1 (mod Z)

The public key is (N, E) and the private key is (N, D).
Note: The values of P, Q, and Z should also be kept secret.
The message is encrypted using public key and decrypted using private key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long int i, e, d, n, p, q, z, cipher[50];

int gcd(long int a, long int b)
{
	if(a==0) return b;
	if(b==0) return a;
	return gcd( b , a%b );
}

int prime(int a)
{
	for (i = 2; i < a; i++)
		if ((a % i) == 0)
			return 0;
	return 1;
}

int encode(char ch)
{
	long int temp = ch;
	for (i = 1; i < e; i++)
		temp = (temp * ch) % n;
	return temp;
}

char decode(long int ch)
{
	long int temp = ch;
	for (i = 1; i < d; i++)
		ch = (temp * ch) % n;
	return ch;
}

int main()
{
	int i,len;
	char text[50];

	printf("\n Enter the text to be encrypted: ");
	gets(text);
	len = strlen(text);
	// generate prime P
	do
	{
		p = rand() % 30;
	} while (!prime(p));		
	// generate prime number Q
	do
	{
		q = rand() % 30;
	} while (!prime(q));
	//compute N and Z
	n = p * q;
	z = (p - 1) * (q - 1);
	// compute E
	do
	{
		e = rand() % z;
	} while (gcd(e,z) != 1);
	// compute D
	do
	{
		d = rand()%z;
	} while( ((d * e) % z) != 1 );
	
	printf("\n P=%ld\t Q=%ld\t N=%ld\t Z=%ld\t E=%ld\t D=%ld\t \n", p, q, n, z, e, d);
	// Encrypt the plain text
	for (i = 0; i < len; i++)
		cipher[i] = encode(text[i]);

	printf("\n Encrypted Message: ");
	for (i = 0; i < len; i++)
		printf("%ld", cipher[i]);
	// Decrypt the cipher text
	for (i = 0; i < len; i++)
		text[i] = decode(cipher[i]);
	text[i] = '\0';
	printf("\n\n Decrypted Message: %s \n\n", text);
	
	return 0;
}
