#include <bits/stdc++.h>
using namespace std;

// �ж����� 
bool Judge(int x) {
	return x % 400 == 0 || (x % 4 == 0 && x % 100 != 0);
}

// ��������������ڼ� 
int WeekDay(int y,int m, int d)
{
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return iWeek + 1;
} 

// ɸ���� O(n�� 1.5�η�) 
bool SuShuShai(int x) {
	if (x == 1)
		return false;
	for (int i = 2; i * i <= sqrt(x); i++) {
		if (x % i == 0) 
			return false; 
	}
	return true;
}

// ��ɸ�� ���� O(nlogn)
// bool BeiSaiFa(int ) 


// ���Լ�� gcd
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a %b);
	// շת����� 
	// (12, 8)
	// (8, 4)
	// (4, 0)
}

// ��С������ lcm
int lcm(int a, int b) {
	return a * b / gcd(a, b);
} 


// ������_������_����˷� 


// ŷ������  ����:С��n������������n���ʵ�������Ŀ


// �������

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
	if (Judge(y)) cout << "2022������" << endl;
	else cout << "��������" << endl;
	int weekday = WeekDay(2022, 6, 16);
	cout << "2022/6/16 ������ " <<  weekday << endl << endl;	
	
	if (SuShuShai(2023)) cout << "2023������" << endl;
	else cout << "��������"; 
	
	int ZuHe = 0;
	ZuHe = C(5, 2);
	cout << "C(5, 2)�Ľ����  " << ZuHe; 
}





























