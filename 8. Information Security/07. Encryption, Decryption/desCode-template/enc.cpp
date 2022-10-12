#include "global.h"

void des_encrypt(char M[], char keys[17][48], char cipher[])
{
   // des-encrypt M into cipher with keys[][]

   // step 3.1. permute M into MPlus using IP matrix
   char MPlus[64];
   permute_8_8(IP, M, MPlus);

   // step 3.2. split MPlus into L0, R0
   char L[17][32], R[17][32];
   split_into_L0R0(MPlus, L[0], R[0], 32);

   // step 3.3. compute Ln, Rn from L(n-1), R(n-1) for n=1..16
   for (int i = 1; i <= 16; i++)
   {
      comp_Li_Ri(L, R, i, 32, keys[i]);
      show_LiRi(L, R, i);
   }

   // step 3.4. reverse L16 and R16, and apply final permutation
   reverse(L[16], R[16]);
   char LR[64];
   combineLR(L[16], R[16], LR);
   permute_8_8(IP_1, LR, cipher);
}

void split_into_L0R0(char MPlus[], char L[], char R[], int len)
{
   int i;
   // ........ code .............
   printf("after split into L0R0.\n");
   show_LR(L, R);
}
void show_LR(char *L, char *R)
{
   int i, len = 32;
   printf("L: ");
   for (i = 0; i < len; i++)
      printf("%d ", L[i]);
   printf("\nR: ");
   for (i = 0; i < len; i++)
      printf("%d ", R[i]);
   printf("\n");
}
void show_LiRi(char L[17][32], char R[17][32], int k)
{
   int i;
   printf("showing %d-th LR. L is \n", k);
   show_LR(L[k], R[k]);
}

void comp_Li_Ri(char L[17][32], char R[17][32], int i, int len, char *key)
{
   // compute L[i], R[i] from L[i-1], R[i-1] with key. L, R has length len

   // compute L[i]: copy R[i-1] into L[i]
   int j;
   for (j = 0; j < len; j++)
      L[i][j] = R[i - 1][j];

   // compute R[i]: R[i]= L[i-1] xor f(R[i-1], key)
   char f[32];
   comp_f(R[i - 1], key, f);
   xoring(L[i - 1], f, R[i], 32);
}
void reverse(char L[], char R[])
{
   // ........... code ..............
   printf("after reverse. L and R is\n");
   show_LR(L, R);
}
void combineLR(char L[], char R[], char LR[])
{
   // combine L and R into LR
   // ............code ..............

   printf("after combineLR\n");
   show_arr(LR, 64);
}
