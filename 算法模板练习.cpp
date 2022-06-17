//  BFS ********************************************************
/*
S##
...
#.T
*/
//#include<bits/stdc++.h>
//using namespace std;
//
//int n, m;     // 地图长宽 
//string maze[110];  // 地图 
//bool vis[110][110];   // 访问标记 
//int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
//
//bool in(int x, int y) {          // 边界判断 
//	return 0 <= x && x < n && 0 <= y && y < m; 
//}
//struct node{         // 结构体 
//	int x, y, d;
//	
//	// 该方式可以方便建立： q.push(node{a, b, c})
//	// 但是就不可以使用 node n1  n1.x = ..... 
//	node(int xx, int yy, int dd) {  
//		x = xx;
//		y = yy;
//		d = dd;
//	}
//
////	bool operator <(const node & n1) const{     // 两种重载方式，直接在结构体内重载 
////		return x < n1.x;
////	}
//};
//
//int bfs(int sx, int sy) {
//	queue<node> q;
////	node nn; nn.x = sy, nn.y = sy, nn.d = 0;
//	q.push(node(sx, sy, 0));
////	q.push(nn);
//	vis[sx][sy] = true;  
//	while(!q.empty()) {     
//		node now = q.front();
//		for (int i = 0; i < 4; i++) {
//			int nx = now.x + dir[i][0];
//			int ny = now.y + dir[i][1];
//			if (in(nx, ny) && maze[nx][ny] != '*' && !vis[nx][ny]) {
//				if (maze[nx][ny] == 'T') {
//					return now.d + 1;
//				} else {
//					vis[nx][ny] = true;
//					q.push(node(nx, ny, now.d + 1));
//				}
//			}
//		}
//	}
//	return -1; 
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) 
//			cin >> maze[i][j];
//	}
//	int x, y;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (maze[i][j] == 'S') {
//				x = i, y = j;
//			}
//		}
//	}
//	cout << bfs(x, y) << endl;
//	return 0;
//}


// DFS  ********************************************************
 
//used[gY][gX] = true;
//dfsMap(gX, gY, step + 1);
//used[gY][gX] = false;


// DP   ********************************************************
/* eg:
5 10
1 2 3 4 5
5 4 3 2 1
*/ 
//#include<bits/stdc++.h>
//using namespace std;
//
//const int maxn = 1003;
//int t, n, m;
//int dp[maxn][maxn], v[maxn], w[maxn];
//int dp2[maxn];
//
//int main() {
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++) cin >> v[i];
//	for (int j = 1; j <= n; j++) cin >> w[j];
///*     01背包 
//	for (int i = 1; i <= n; i++)
//		for (int j = w[i]; j <= m; j++){
//			if (j < w[i]) 
//				dp[i][j] = dp[i - 1][j];
//			else 
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
//		} 
//	cout << dp[n][m];
//*/
//	for (int i = 1; i <= n; i++) 
//		for (int j = m; j >= w[i]; j--)
//			dp2[j] = max(dp2[j], dp2[j - w[i]] + v[i]);
//	cout << dp2[m];
//	
//	return 0;
//}

//   完全背包
/*    二维
	for (int i = 1; i <= n; i++)
		for(int j = w[i]; j <= m; j++)
			dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
*/ 

/*    一维
	for (int i = 1; i <= m; i++)
		for (int j = w[i]; j <= m; j++)
			dp[i] = max(dp[i], dp[j - w[i]] + v[i]);
*/




// 并查集  ********************************************************
//#include<bits/stdc++.h>
//using namespace std;

//for(int i=1;i<=n;i++)      // 第一步初始化 
//	f[i]=i;                  //先自己就是自己的父亲节点
//int f[10003];
//int find(int x) { 
//	if (x == f[x]) return x;
//	else return f[x] = find(f[x]);
//}
///* 
//void unite(int x, int y) {         //  合并优化 
//	int a = find(x);
//	int b = find(y);
//	if (a == b) return;
//	if (R[a] <= R[b]) f[a] = b;
//	else f[b] = a;
//	if (R[a] == R[b]) R[a]++;
//}
//*/
//void unite(int x, int y) {
//	int a = find(x);
//	int b = find(y);
//	if (a != b) 
//		f[a] = b;
//}

//int main() {
//	const long long mod=998244353;
//	string str;
//	int n, m;
//	cin >> n >> m;
//	int thr[m][3];
//	
//	for(int i=1;i<=n;i++)//先自己就是自己的父亲节点
//		f[i]=i;
//
//	for (int i = 0; i < m; i++) {
//		cin >> thr[i][0] >> thr[i][1] >> thr[i][2];
//	}
//	
//	for (int i = 0; i < m; i++) {
//		if (thr[i][0] == 1) {
//			if (find(thr[i][1]) == find(thr[i][2])) 
//				str += '1';
//			else str += '0';
//		}
//		if (thr[i][0] == 0) {
//			unite(thr[i][1], thr[i][2]);
//		}
//	}
//
//	cout << stoi(str, 0, 2) % mod;
//	return 0;
//}





// 前缀和  ********************************************************
// 一维前缀和
//状态方程
//s[i] = s[i - 1] + a[i];
//求 l ~ r
//    = s[r] - s[l - 1]; 

// 二维前缀和
//状态方程 
//s[x, y] = s[i - 1][y] + s[i][y - 1] - s[i - 1][y - 1] + a[i][j];
//求 (x1, x2) ~ (x2, y2) 
//    = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]; 





// 二分  ********************************************************
//int len = nums.size();
//int l = 0, r = len - 1;
//while (l <= r) {
//    int mid = l + (r - l) / 2;
//    if (nums[mid]  == target) 
//        return mid;
//    else if (nums[mid] < target)
//        l = mid + 1;
//    else r = mid - 1;
//}
//return -1;






// 快排 ********************************************************
//#include<bits/stdc++.h>
//using namespace std;
//
//int q[100010];   // 在主函数外面声明的数组值为0 
//// 快速排序子函数部分 
///*
//void quick_sort(int q[], int l, int r) {
//	// 边界不满足左边小，直接返回 
//	if (l >= r) return; 
//	// 第一步，确定边界
//	// 由于i和j都是先自减或自增后判断，初始时i，j往边界扩一步
//	int i = l - 1, j = r + 1, x = q[l + r >> 1];
//	// 开始
//	while (i < j) {
//		do i++; while (q[i] < x);
//		do j--; while (q[j] > x);
//		if (i < j) swap(q[i], q[j]);
//	} 
//	quick_sort(q, l, j);
//	quick_sort(q, j + 1, r);
//}
//*/
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> q[i];
//	}
//	quick_sort(q, 0, n - 1);
//	
//	for (int i = 0; i < n; i++) cout << q[i] << ends;
//  return 0;
//}






// 归并  ********************************************************
//#include<bits/stdc++.h>
//using namespace std;
//
//int q[100010], temp[100010];
//// 归并排序子函数部分 
///*
//void merge_sort(int q[], int l, int r) {
//	// 递归出口 
//	if (l >= r) return;
//	
//	int mid = (l + r) >> 1;
//	
//	merge_sort(q, l, mid);
//	merge_sort(q, mid + 1, r);
//	
//	// k为temp下标，i，j为两个子区间的起始位置 
//	int k = 0, i = l, j = mid + 1;
//	
//	while (i <= mid && j <= r) {
//		if (q[i] <= q[j]) temp[k++] = q[i++];
//		else temp[k++] = q[j++];
//	}
//	
//	// 当一个区间走完另一个没完的时候，让它走完 
//	while (i <= mid) temp[k++] = q[i++];
//	while (j <= r) temp[k++] = q[j++];
//	
//	for(i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
//}
//*/
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> q[i];
//	} 
//	
//	merge_sort(q, 0, n - 1);
//	
//	for (int i = 0; i < n; i++) cout << q[i] << ends;
//	
//	return 0;
//}








//  位运算  ********************************************************
// x % 2 == 1 ---   x & 1 == 1 

//#include<bits/stdc++.h>
//using namespace std;
//
//int main() {
//	if (3 & 1 == 1) {
//		cout << "00011" << endl;
//		cout << "00001" << endl;
//		cout << "--------" << endl;
//		cout << "00001 == 1" << endl;
//		cout << "所以3 & 1 == 1 true";
//	}
//}

// 树 图 堆 贪心 数论 图论 






































 
