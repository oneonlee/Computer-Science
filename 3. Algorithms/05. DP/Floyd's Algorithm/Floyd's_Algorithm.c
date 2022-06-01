#include <stdio.h>

#define N 5 // 정점 수
#define INF 100

void floyd2(int n, const int(*W)[N+1], int(*D)[N+1], int(*P)[N+1]) {
	int i, j, k;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			P[i][j] = 0;	//배열 P초기화
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			D[i][j] = W[i][j];
		}
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}

			}
		}
	}
}

void path(int(*P)[N+1], int q, int r) {
	if (P[q][r] != 0) {
		path(P, q, P[q][r]);
		printf("v%d -> ", P[q][r]);
		path(P,P[q][r], r);
	}
}

int main(void) {
	// W 값
	int W[N+1][N+1] = {
		{0,0,0,0,0,0},  
		{0,0,1,INF,1,5},
		{0,9,0,3,2,INF},
		{0,INF,INF,0,4,INF},
		{0,INF,INF,2,0,3},
		{0,3,INF,INF,INF,0}
		};

	int D[N+1][N+1];
	int P[N+1][N+1];

	floyd2(N, W, D, P);

    printf("D[i][j] is \n");

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%3d", D[i][j]);
		}

		printf("\n");
	}

    printf("\nP[i][j] is \n");
    
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			printf("%3d", P[i][j]);
		}
		
		printf("\n");
	}

	int start, end;
	start = 5;
	end = 3;

    printf("\nThe shortest path(%d, %d) is", start, end);
	printf(" v%d -> ", start);
	path(P, start, end);
	printf("v%d\n", end);

	return 0;
}

