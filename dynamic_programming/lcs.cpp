#include <iostream>
#include <cstdio>
#include <cstring>
#define LEFT 1
#define UP 2
#define LEFT_UP 3
#define N 1010
using namespace std;
//start from index one
//int s1[N] = {0, 2, 5, 7, 9, 3, 1, 2};
//int s2[N] = {0, 3, 5, 3, 2, 8};
char s1[N], s2[N];
int s1_len, s2_len;
int dp[N][N];
int pre[N][N];

void LCS()
{
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= s1_len; i++)
		for (int j = 1; j <= s2_len; j++)
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
				pre[i][j] = LEFT_UP;
			} else {
				if (dp[i-1][j] < dp[i][j-1]) {
					dp[i][j] = dp[i][j-1];
					pre[i][j] = LEFT;
				} else {
					dp[i][j] = dp[i-1][j];
					pre[i][j] = UP;
				}
			}
}

void print_LCS(int i, int j)
{
	if (i == 0 || j == 0) return;

	if (pre[i][j] == LEFT_UP) {
		print_LCS(i-1, j-1);
		cout << s1[i];
	}
	else if (pre[i][j] == UP)
		print_LCS(i-1, j);
	else if (pre[i][j] == LEFT)
		print_LCS(i, j-1);
}

int main()
{
	while (NULL != gets(s1+1)) {
		gets(s2+1);
		s1_len = strlen(s1+1);
		s2_len = strlen(s2+1);
		LCS();
		cout << dp[s1_len][s2_len] << endl;
	}
	return 0;
}
