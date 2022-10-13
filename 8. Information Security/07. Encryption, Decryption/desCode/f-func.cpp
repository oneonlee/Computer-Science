#include "global.h"
void comp_f(char *R, char *key, char *f)
{
   // compute f=f(R, key)

   // step 3.3.1. expand 32-bit R into 48-bit ER using E matrix
   char ER[48];
   permute_8_6(E, R, ER);

   // step 3.3.2. xor ER with key
   char ERp[48]; // result of ER xor key
   xoring(ER, key, ERp, 48);

   // step 3.3.3. split ERp into B1, B2, ..., B8
   char B[8][6];
   split_B(ERp, B); // split 48-bit ERp into 6-bit B1, B2, ..., B8
   printf("aftr split B. B is\n");
   showB(B);

   // step 3.3.4. Convert 6-bit B[i] into 4-bit SB[i]
   char SB[8][4];
   char totalSB[32];
   do_sbox(B, SB, Sbox); // convert B1 to SB1, B2 to SB2, ...
   printf("after do sbox. SB is\n");
   show_SB(SB);

   SBmerge(SB, totalSB); // merge SB1, SB2, .., SB8 into totalSB
   printf("after SB merge. totalSB is\n");
   show_arr(totalSB, 32);

   // step 3.3.5. final permutation
   permute_8_4(P, totalSB, f);
}

void SBmerge(char SB[8][4], char totalSB[])
{
   int cnt = 0;
   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         totalSB[cnt] = SB[i][j];
         cnt++;
      }
   }
}

void showB(char B[8][6])
{
   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; j < 6; j++)
      {
         printf("%d ", B[i][j]);
         ;
      }
      printf("\n");
   }
}

void show_SB(char SB[8][4])
{
   for (int i = 0; i < 8; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         printf("%d ", SB[i][j]);
         ;
      }
      printf("\n");
   }
}

void split_B(char ERp[], char B[8][6])
{
   int i, j;
   for (i = 0; i < 8; i++)
   {
      for (j = 0; j < 6; j++)
      {
         B[i][j] = ERp[i * 6 + j];
      }
   }
}

void do_sbox(char B[8][6], char SB[8][4], int Sbox[8][4][16])
{
   // comp SB[0], SB[1], ... SB[7] from B[][] using Sbox
   for (int i = 0; i < 8; i++)
   {
      do_sbox_i(B, SB, Sbox, i);
   }
}

void do_sbox_i(char B[8][6], char SB[8][4], int Sbox[8][4][16], int idx)
{
   // comp SB[idx] from B[idx] using Sbox[idx]
   int Sbox_row = (B[idx][0] * 2) + B[idx][5];
   int Sbox_col = (B[idx][1] * 8) + (B[idx][2] * 4) + (B[idx][3] * 2) + B[idx][4];
   int temp = Sbox[idx][Sbox_row][Sbox_col];

   for (int j = 3; j >= 0; j--)
   {
      SB[idx][j] = temp % 2;
      temp = temp / 2;
   }
}

int comp_row_from_B(char B[])
{
   // row is at B[0] and B[5]
   int row;
   row = B[0];
   row = row * 2 + B[5];
   return row;
}

int comp_col_from_B(char B[])
{
   // col is at B[1] to B[4]
   int col = 0, i;
   for (i = 1; i < 5; i++)
   {
      col = col * 2 + B[i];
   }
   return col;
}

void convert_val_to_4bit(int SBval, char SB[])
{
   int temp = SBval;
   for (int i = 3; i >= 0; i--)
   {
      SB[i] = temp % 2;
      temp = temp / 2;
   }
}
