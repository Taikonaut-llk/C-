#include <bits/stdc++.h>
using namespace std;

// 判断闰年 
bool Judge(int x) {
	return x % 400 == 0 || (x % 4 == 0 && x % 100 != 0);
}

// 求根据日期求星期几 
int WeekDay(int y,int m, int d)
{
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return iWeek + 1;
} 

// 筛素数 O(n的 1.5次方) 
bool SuShuShai(int x) {
	if (x == 1)
		return false;
	for (int i = 2; i * i <= sqrt(x); i++) {
		if (x % i == 0) 
			return false; 
	}
	return true;
}

// 倍筛法 素数 O(nlogn)
// bool BeiSaiFa(int ) 


// 最大公约数 gcd
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a %b);
	// 辗转相除法 
	// (12, 8)
	// (8, 4)
	// (4, 0)
}

// 最小公倍数 lcm
int lcm(int a, int b) {
	return a * b / gcd(a, b);
} 


// 矩阵幂_快速幂_矩阵乘法 


// 欧拉函数  定义:小于n的正整数中与n互质的数的数目


// 求组合数

long long C(int n, int m)
{
	if (m < n - m) m = n - m;
	long long ans = 1;
//	for (int i = n; i > n - m; i--) ans *= i;
//	for (int i = m; i > 0; i--) ans /= i; 
	for (int up = n, dwn = 1; dwn <= m; --up, ++dwn)
		ans *= up, ans /= dwn;
	
	return ans;
}




 
int main() {
	int y = 2022, m = 6; y = 16;
	if (Judge(y)) cout << "2022是闰年" << endl;
	else cout << "不是闰年" << endl;
	int weekday = WeekDay(2022, 6, 16);
	cout << "2022/6/16 星期四 " <<  weekday << endl << endl;	
	
	if (SuShuShai(2023)) cout << "2023是素数" << endl;
	else cout << "不是素数"; 
	
	int ZuHe = 0;
	ZuHe = C(5, 2);
	cout << "C(5, 2)的结果是  " << ZuHe; 
}





























