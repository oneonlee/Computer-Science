#include <stdio.h>
#include <string.h>

extern int PC_1[8][7];
extern char K[64];
extern int ROL[16];
extern int PC_2[8][6];
extern char M[64];
extern int IP[8][8];
extern int E[8][6];
extern int Sbox[8][4][16];
extern int P[8][4];
extern int IP_1[8][8];

// keysched.cpp
extern void construct_key_schedule(char K[], char keys[17][48]);
extern void split_KPlus(char KPlust[], char C0[], char D0[]);
extern void show_CD(char C[], char D[]);
extern void comp_Cn_Dn(char C[17][28], char D[17][28], int ROL[]);
extern void comp_Ci_Di(char C[17][28], char D[17][28], int i, int ROL[]);
extern void comp_keys(char C[17][28], char D[17][28], int PC_2[8][6], char keys[17][48]);

// f-func.cpp
extern void comp_f(char *R, char *key, char *f);
extern void SBmerge(char SB[8][4], char totalSB[]);
extern void showB(char B[8][6]);
extern void show_SB(char SB[8][4]);
extern void split_B(char ERp[], char B[8][6]);
extern void do_sbox(char B[8][6], char SB[8][4], int Sbox[8][4][16]);
extern void do_sbox_i(char B[8][6], char SB[8][4], int Sbox[8][4][16], int i);
extern int comp_row_from_B(char B[]);
extern int comp_col_from_B(char B[]);
extern void convert_val_to_4bit(int SBval, char SB[]);

// enc.cpp
extern void des_encrypt(char M[], char keys[17][48], char cipher[]);
extern void split_into_L0R0(char MPlus[], char L[], char R[], int len);
extern void show_LR(char *L, char *R);
extern void show_LiRi(char L[17][32], char R[17][32], int k);
extern void comp_Li_Ri(char L[17][32], char R[17][32], int i, int len, char *key);
extern void reverse(char L[], char R[]);
extern void combineLR(char L[], char R[], char LR[]);

// util.cpp
extern void permute_8_8(int perm[8][8], char src[], char dest[]);
extern void permute_8_6(int perm[8][6], char src[], char dest[]);
extern void permute_8_4(int perm[8][4], char src[], char dest[]);
extern void permute_8_7(int perm[8][7], char src[], char dest[]);
extern void rotate_left_and_store(char x[], int len, int cnt, char y[]);
extern void combine_arr(char *x, char *y, char *z, int len);
extern void copy_arr(char *x, char *y, int len);
extern void xoring(char *x, char *y, char *z, int len);
extern char xorbit(char x, char y);
extern void show_arr(char *x, int len);
