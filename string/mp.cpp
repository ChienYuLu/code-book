#include <cstdio>
#include <cstring>
#include <vector>
#define N 200005
using namespace std;

int fail[N];
char a[N], b[N];
vector<int> match;
int lena, lenb;

void make_failure()
{
	int n = lenb;
	fail[0] = -1;
	fail[1] = 0;
	for (int i = 2; i <= n; i++) {
		int tmp = fail[i-1];
		while (1) {
			if (b[tmp] == b[i-1]) {
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

void str_match()
{
	match.clear();
	int i = 0;
	int j = 0;
	int cnt = 0;
	while (i < lena) {
		while (a[i] == b[j] && i < lena) {
			i++;
			j++;
			if (j == lenb) {
				match.push_back(i);
				j = fail[j];
			}
		}
		j = fail[j];
		if (j == -1) {
			i++;
			j = 0;
		}
	}
}

int main()
{
	strcpy(a, "0210xxx0010x");
	strcpy(b, "010x");

	lena = strlen(a);
	lenb = strlen(b);

	make_failure();
	str_match();

	for (int i = 0; i <= lenb; i++)
		printf("%d ", fail[i]);
	printf("\n");

	for (int i = 0; i < match.size(); i++) {
		printf("%d ", match[i]);
	}
	printf("\n");

	return 0;
}
