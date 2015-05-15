/* 二分圖匹配
 * v 是 adj list
 * vis每次要memset
 * match[y] == 0 表示還沒配對到
 */

bool bipartite(int x)
{
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (vis[y] == 0) {
			vis[y] = 1;
			if (match[y] == 0 || bipartite(match[y])) {
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}
