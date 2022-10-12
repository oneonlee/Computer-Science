#include "global.h"

void permute_8_8(int perm[8][8], char src[], char dest[])
{
   // compute dest from src by applying the permutation table "perm" whose
   // dimensionis row*col
   int row = 8;
   int col = 8;
   int index;
   int cnt = 0;
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         index = perm[i][j];
         dest[cnt] = src[index - 1];
         cnt++;
      }
   }
   printf("after permute. dest (size:%d) is\n", cnt);
   for (int i = 0; i < cnt; i++)
      printf("%d ", dest[i]);
   printf("\n");
}
void permute_8_6(int perm[8][6], char src[], char dest[])
{
   // compute dest from src by applying the permutation table "perm" whose
   // dimensionis row*col
   int row = 8;
   int col = 6;
   int index;
   int cnt = 0;
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         index = perm[i][j];
         dest[cnt] = src[index - 1];
         cnt++;
      }
   }
   printf("after permute. dest (size:%d) is\n", cnt);
   for (int i = 0; i < cnt; i++)
      printf("%d ", dest[i]);
   printf("\n");
}
void permute_8_4(int perm[8][4], char src[], char dest[])
{
   // compute dest from src by applying the permutation table "perm" whose
   // dimensionis row*col
   int row = 8;
   int col = 4;
   int index;
   int cnt = 0;
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         index = perm[i][j];
         dest[cnt] = src[index - 1];
         cnt++;
      }
   }
   printf("after permute. dest (size:%d) is\n", cnt);
   for (int i = 0; i < cnt; i++)
      printf("%d ", dest[i]);
   printf("\n");
}
void permute_8_7(int perm[8][7], char src[], char dest[])
{
   // compute dest from src by applying the permutation table "perm" whose
   // dimensionis row*col
   int row = 8;
   int col = 7;
   int index;
   int cnt = 0;
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         index = perm[i][j];
         dest[cnt] = src[index - 1];
         cnt++;
      }
   }
   printf("after permute. dest (size:%d) is\n", cnt);
   for (int i = 0; i < cnt; i++)
      printf("%d ", dest[i]);
   printf("\n");
}
void rotate_left_and_store(char x[], int len, int cnt, char y[])
{
   // rotate-left x[] by cnt and store in y[]
   int i, j;
   for (i = 0; i < len - cnt; i++)
   {
      y[i] = x[i + cnt];
   }
   for (i = len - cnt, j = 0; i < len; i++, j++)
   {
      y[i] = x[j];
   }
}

void combine_arr(char *x, char *y, char *z, int len)
{
   // x and y are both arrays of length of len. combine them into z
   int i;
   for (i = 0; i < len; i++)
      z[i] = x[i];
   for (i = 0; i < len; i++)
      z[i + len] = y[i];
}
void copy_arr(char *x, char *y, int len)
{
   // copy y into x. length len.
   for (int i = 0; i < len; i++)
   {
      x[i] = y[i];
   }
}
void xoring(char *x, char *y, char *z, int len)
{
   // x xor y = z.
   for (int i = 0; i < len; i++)
   {
      z[i] = xorbit(x[i], y[i]);
   }
   printf("after xoring\n");
   for (int i = 0; i < len; i++)
   {
      printf("%d ", z[i]);
   }
   printf("\n");
}
char xorbit(char x, char y)
{
   if (x == y)
      return 0;
   else
      return 1;
}
void show_arr(char *x, int len)
{
   for (int i = 0; i < len; i++)
      printf("%d ", x[i]);
   printf("\n");
}
