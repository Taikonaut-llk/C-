#include<bits/stdc++.h>
using namespace std;

struct student{       // set ����ӽṹ�����ݣ�����set�Լ���˳��������Ҫ���� <  
	int x, y, step;
	
//	student(int xx, int yy, int dd) {
//		x = xx;
//		y = yy;
//		step = dd;
//	}
	bool operator <(const student & n1) const{     // �������ط�ʽ��ֱ���ڽṹ�������� 
		return x < n1.x;
	}
};
//bool operator <(const student & n1,const student & n2)   // ���������أ�������Ҫconst��ʵ�� 
//{
// 
//    return n1.x < n2.x;
//}


int main() {
	// printf ��� 
	// cout >> fixed >> setprecision(3)
	float a = 23.266633;
	cout << "����pritnf��ӡ���������" << "  ";
	printf("%.3f\n", a);
	cout << fixed << "����cout��ӡ���������  " << setprecision(3) << a << endl << endl; 
	
	// *max_element min_element  ������ȡ�����Сֵ
	
	// getline(cin, str)  ֻ�ܶ�ȡ�ַ�������
	
	
	
	// itoa �����䵽char���� atoi char����������
	int b = 12345, d = 0;
	char c[10];
	itoa(b, c, 10);
	cout << "�ַ�����ĳ���  " << sizeof(c) << endl;
	cout << "����ַ���������  " << c[0] << " " << c[1] << endl;
	// sprintf(c, "%d", b); 
	// cout << "�ַ����ĳ���  " << sizeof(c) << endl;
	// cout << c[0] << " " << c[1] << endl;

	// for (int i = 0; i < sizeof(c); i++) cout << c[i] << ends;
	// ���⣺char���Ĵ�С������ǰָ������ͷ�� 
	c[1] = '9';
	d = atoi(c);
	cout << "atoi(c)��ӡ�ַ����������  " << d << endl;
	// char *str = "324234";
	// cout << atoi(str);
	string str = "21542";
	cout << "�ַ���תint  " << stoi(str) << endl << endl; 
	
	
	
	// ����ת��
	int e = 234;
	cout << "�˽������  " << oct << e << endl;
	cout << "ʮ�������  " << dec << e << endl;
	cout << "ʮ���������  " << hex << e << endl;
	printf("printf��������ִ�Сд��ʮ������  %X\n", e);
	cout << "���������  " << bitset<8>(e) << endl;
	bitset<8>f(e);
	cout << "���������1������  " << f.count() << endl << endl;
	// f.test(7) �жϵ�x��λ����0����1��ע�������� 
	
	
	
	// next_permutation ȫ����
	int g[4];
	//vector<int> h;
	for (int i = 0; i < 4; i++) {
		g[i] = i + 1;
	//	h.emplace_back(i + 2);
	}
	do{
		cout << "���������ȫ����  ";
		for (int i = 0; i < 4; i++) {
			cout  << g[i] << " ";
			//cout << "vector�����ȫ����  " << h[i] << endl;
		}
		cout << endl;
	} while(next_permutation(g, g + 4/*h.begin(), h.end()*/));
	cout << endl << endl; 
	
	
	// abs() ���������ֵ  fabs()  �����������ֵ
	// �������Ƚ�  fabs(a) - fabs(b) < 1e5 
	
	
	
//	isalnum()   �Ƿ������֣���ĸ 
//	isalpha()   �Ƿ�����ĸ 
//	islower() tolower()   �Ƿ���Сд��ĸ 
//	isupper() toupper()   �Ƿ��Ǵ�д��ĸ
	
	char h = 'a';
	if (isalpha(h)) cout << "����һ����ĸ  " << h << endl;
	if (islower(h)) cout << "����һ��Сд��ĸ  " << h << endl;
	char i = toupper(h);
	if (isupper(i)) cout << "����һ��toupper�Ĵ�д��ĸ  " << i << endl << endl;

	
	// ��������   j / k С��1 
	cout << "����������xλС��  "; 
	int j = 2, k = 3;
	for(int i = 0; i < 20; i++) {
		cout << j / k;
		j = (j % k) * 10; 
	}
	cout << endl << endl; 
	
	// pow(2, n)  2�� n �η�
	
	// map  
	map<char, int> l;
	for (int i = 0; i < 5; i++) {
		l.insert(make_pair('a' + i, i));
	} 
	map<char, int>::iterator it = l.begin();
	cout << "ͨ��map�ĵ�����it->first��ȡ  " << endl; 
	while (it != l.end()) {
		cout << "it->second �� first" << it->second << " " << it->first << endl;
		it++;
	}
	cout << endl;
	

	// set
	set<student> m;
	student n;
	for (int i = 0; i < 5; i++) {   // Ϊʲô���� 10 �Ժ�ͱ����ĸ��  // Ϊʲô��16���� 
		n.x = i + 10;
		n.y = 14 - i;
		n.step = i;
		m.insert(n);
		m.insert(student{i + 10, 14 - i, i});
	}
	set<student>::iterator ite = m.begin();
	cout << "ͨ��set�ĵ�����(*it).x��ȡ�ṹ�������  " << endl; 
	while(ite != m.end()) {
		//cout << (*ite).x;
		printf("����printf��ʮ������ʾ  %d %d %d\n", (*ite).x, (*ite).y, (*ite).step); 
		cout << "����cout��ʮ��������ʾ  " << (*ite).x << "  " << (*ite).y << "  " << (*ite).step << endl << endl;
		
		ite++;
	}
	
	
	
	// deque 
	deque<student> o;
	student p;
	for (int i = 0; i < 5; i++) {
		p.x = p.y = p.step = i + 1;
		o.push_back(p);
	} 
	cout << "deque�Ĵ�С��Ӧ����5  " << o.size() << endl;
	o.push_front(student{p.x = 0, p.y =0, p.step = 0});
	cout << "��deque��ǰ��push_frontһ��0  " << o[0].x << endl;
	o.pop_back();
	cout << "�����һ��ɾ����Ӧ����4  " << o[o.size() - 1].x << endl << endl;
	cout << endl;
	
	
	
	// binary_search()  bool���ͣ���������
	int q[10];
	vector<int> r;
	deque<int> s;
	for (int i = 1; i < 11; i++) {
		q[i - 1] = i;
		r.push_back(i);
		s.push_back(i);
	}
	
	if (binary_search(r.begin(), r.end(), 5)) 
		cout << "���ֲ���vector���� true" << endl;   
	cout << "���ֲ���deque����  " << binary_search(s.begin(), s.end(), 6) ? true : false;	
	cout << endl << endl;
	
	
	
	
	// lower_bound()  ��һ����Ŀ����ڵ�����û�о��Ҵ��
//	int num[5] = {5, 4, 2, 1, 3};
//	int *ppp = lower_bound(num, num + 5, 5); 
//	cout << "*ppp = " << *ppp << endl; 
//	vector<int> nums{4,5,6,1,2 };
//	auto itr = lower_bound(nums.begin(), nums.end(), 3);
//	cout << "auto *itr = " << *itr << endl << endl;
	
	// ��ȡ�ļ� freopen
	freopen("freopen.txt", "r", stdin);
	int t;
	cout << "�ļ���ȡ������  ";
	while (scanf("%d", &t) != EOF) {
		cout << dec << t << ends;
	}
	cout << endl << endl;
	
	
	// __gcd(a, b) ���Լ��
	int u = 6, v = 12, w = 0;
	w = __gcd(u, v);
	cout << "���Լ��  " << w << endl << endl;
	 

	// sort(a, a + 5) sort(b.begin(), b.end())  Ĭ�ϴ�С��������
	// sort(, , com)  
	// bool com(int a, int b)  return a > b;    �Ӵ�С��
	
	
	// �ַ��� 
	string x = "asdfasdf";
	string y = "df";
	int z = x.find(y);
	cout << "���ַ���x���ҵ�y��λ�ã�Ӧ����2  " << z << endl;
	y = x.substr(3, 2);
	cout << "��x�н�ȡ(��ʼλ�ã�����)���ַ���  " << y << endl; 
	x.erase(3, 5);
	cout << "��x��ɾ��(��ʼλ�ã�����)���ַ���  " << x << endl; 
	x.insert(0, "as");
	cout << "��x�в���(��ʼλ�ã�Ŀ�괮)���ַ���  " << x << endl; 
	 
} 
