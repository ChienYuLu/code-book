#include <stdio.h>

int fail[1000006];
char line[1000006];

int main()
{
	int n;
	while (EOF != scanf("%d%*c", &n) && n) {
		scanf("%s", line);

		int i;
		fail[0] = -1;
		fail[1] = 0;
		for (i = 2; i <= n; i++) {
			int tmp = fail[i-1];
			while (1) {
				if (line[tmp] == line[i-1]) {
					fail[i] = tmp+1;
					break;
				} else if (tmp == 0) {
					fail[i] = 0;
					break;
				}
				tmp = fail[tmp];
			}
		}
	}
	return 0;
}
