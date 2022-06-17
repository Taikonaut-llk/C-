#include<bits/stdc++.h>
using namespace std;

struct student{       // set 里添加结构体数据；由于set自己有顺序，所以需要重载 <  
	int x, y, step;
	
//	student(int xx, int yy, int dd) {
//		x = xx;
//		y = yy;
//		step = dd;
//	}
	bool operator <(const student & n1) const{     // 两种重载方式，直接在结构体内重载 
		return x < n1.x;
	}
};
//bool operator <(const student & n1,const student & n2)   // 在外面重载，但是需要const俩实例 
//{
// 
//    return n1.x < n2.x;
//}


int main() {
	// printf 输出 
	// cout >> fixed >> setprecision(3)
	float a = 23.266633;
	cout << "这是pritnf打印的输出精度" << "  ";
	printf("%.3f\n", a);
	cout << fixed << "这是cout打印的输出精度  " << setprecision(3) << a << endl << endl; 
	
	// *max_element min_element  迭代器取最大最小值
	
	// getline(cin, str)  只能读取字符串整行
	
	
	
	// itoa 整数变到char数组 atoi char数组变成整数
	int b = 12345, d = 0;
	char c[10];
	itoa(b, c, 10);
	cout << "字符数组的长度  " << sizeof(c) << endl;
	cout << "检查字符数组内容  " << c[0] << " " << c[1] << endl;
	// sprintf(c, "%d", b); 
	// cout << "字符串的长度  " << sizeof(c) << endl;
	// cout << c[0] << " " << c[1] << endl;

	// for (int i = 0; i < sizeof(c); i++) cout << c[i] << ends;
	// 问题：char串的大小必须提前指定，很头疼 
	c[1] = '9';
	d = atoi(c);
	cout << "atoi(c)打印字符数组成整数  " << d << endl;
	// char *str = "324234";
	// cout << atoi(str);
	string str = "21542";
	cout << "字符串转int  " << stoi(str) << endl << endl; 
	
	
	
	// 进制转换
	int e = 234;
	cout << "八进制输出  " << oct << e << endl;
	cout << "十进制输出  " << dec << e << endl;
	cout << "十六进制输出  " << hex << e << endl;
	printf("printf输出从区分大小写的十六进制  %X\n", e);
	cout << "二进制输出  " << bitset<8>(e) << endl;
	bitset<8>f(e);
	cout << "二进制里的1的数量  " << f.count() << endl << endl;
	// f.test(7) 判断第x个位置是0还是1，注意是逆序 
	
	
	
	// next_permutation 全排列
	int g[4];
	//vector<int> h;
	for (int i = 0; i < 4; i++) {
		g[i] = i + 1;
	//	h.emplace_back(i + 2);
	}
	do{
		cout << "基础数组的全排列  ";
		for (int i = 0; i < 4; i++) {
			cout  << g[i] << " ";
			//cout << "vector数组的全排列  " << h[i] << endl;
		}
		cout << endl;
	} while(next_permutation(g, g + 4/*h.begin(), h.end()*/));
	cout << endl << endl; 
	
	
	// abs() 整数求绝对值  fabs()  浮点数求绝对值
	// 浮点数比较  fabs(a) - fabs(b) < 1e5 
	
	
	
//	isalnum()   是否是数字，字母 
//	isalpha()   是否是字母 
//	islower() tolower()   是否是小写字母 
//	isupper() toupper()   是否是大写字母
	
	char h = 'a';
	if (isalpha(h)) cout << "这是一个字母  " << h << endl;
	if (islower(h)) cout << "这是一个小写字母  " << h << endl;
	char i = toupper(h);
	if (isupper(i)) cout << "这是一个toupper的大写字母  " << i << endl << endl;

	
	// 分数除法   j / k 小于1 
	cout << "分数除法求x位小数  "; 
	int j = 2, k = 3;
	for(int i = 0; i < 20; i++) {
		cout << j / k;
		j = (j % k) * 10; 
	}
	cout << endl << endl; 
	
	// pow(2, n)  2的 n 次方
	
	// map  
	map<char, int> l;
	for (int i = 0; i < 5; i++) {
		l.insert(make_pair('a' + i, i));
	} 
	map<char, int>::iterator it = l.begin();
	cout << "通过map的迭代器it->first读取  " << endl; 
	while (it != l.end()) {
		cout << "it->second 和 first" << it->second << " " << it->first << endl;
		it++;
	}
	cout << endl;
	

	// set
	set<student> m;
	student n;
	for (int i = 0; i < 5; i++) {   // 为什么超过 10 以后就变成字母了  // 为什么是16进制 
		n.x = i + 10;
		n.y = 14 - i;
		n.step = i;
		m.insert(n);
		m.insert(student{i + 10, 14 - i, i});
	}
	set<student>::iterator ite = m.begin();
	cout << "通过set的迭代器(*it).x读取结构体的数据  " << endl; 
	while(ite != m.end()) {
		//cout << (*ite).x;
		printf("这是printf的十进制显示  %d %d %d\n", (*ite).x, (*ite).y, (*ite).step); 
		cout << "这是cout的十六进制显示  " << (*ite).x << "  " << (*ite).y << "  " << (*ite).step << endl << endl;
		
		ite++;
	}
	
	
	
	// deque 
	deque<student> o;
	student p;
	for (int i = 0; i < 5; i++) {
		p.x = p.y = p.step = i + 1;
		o.push_back(p);
	} 
	cout << "deque的大小，应该是5  " << o.size() << endl;
	o.push_front(student{p.x = 0, p.y =0, p.step = 0});
	cout << "在deque的前面push_front一个0  " << o[0].x << endl;
	o.pop_back();
	cout << "把最后一个删除，应该是4  " << o[o.size() - 1].x << endl << endl;
	cout << endl;
	
	
	
	// binary_search()  bool类型，升序排序
	int q[10];
	vector<int> r;
	deque<int> s;
	for (int i = 1; i < 11; i++) {
		q[i - 1] = i;
		r.push_back(i);
		s.push_back(i);
	}
	
	if (binary_search(r.begin(), r.end(), 5)) 
		cout << "二分查找vector数组 true" << endl;   
	cout << "二分查找deque数组  " << binary_search(s.begin(), s.end(), 6) ? true : false;	
	cout << endl << endl;
	
	
	
	
	// lower_bound()  第一个比目标等于的数，没有就找大的
//	int num[5] = {5, 4, 2, 1, 3};
//	int *ppp = lower_bound(num, num + 5, 5); 
//	cout << "*ppp = " << *ppp << endl; 
//	vector<int> nums{4,5,6,1,2 };
//	auto itr = lower_bound(nums.begin(), nums.end(), 3);
//	cout << "auto *itr = " << *itr << endl << endl;
	
	// 读取文件 freopen
	freopen("freopen.txt", "r", stdin);
	int t;
	cout << "文件读取的数字  ";
	while (scanf("%d", &t) != EOF) {
		cout << dec << t << ends;
	}
	cout << endl << endl;
	
	
	// __gcd(a, b) 最大公约数
	int u = 6, v = 12, w = 0;
	w = __gcd(u, v);
	cout << "最大公约数  " << w << endl << endl;
	 

	// sort(a, a + 5) sort(b.begin(), b.end())  默认从小到大排序
	// sort(, , com)  
	// bool com(int a, int b)  return a > b;    从大到小排
	
	
	// 字符串 
	string x = "asdfasdf";
	string y = "df";
	int z = x.find(y);
	cout << "在字符串x中找到y的位置，应该是2  " << z << endl;
	y = x.substr(3, 2);
	cout << "在x中截取(起始位置，长度)的字符串  " << y << endl; 
	x.erase(3, 5);
	cout << "在x中删除(起始位置，长度)的字符串  " << x << endl; 
	x.insert(0, "as");
	cout << "在x中插入(起始位置，目标串)的字符串  " << x << endl; 
	 
} 
