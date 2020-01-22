#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int ryad()
{
	double x, e, t;
	int k = 3, sw = 0;
	cin >> x >> e;
	vector <double> vec;
	vec.push_back(1);
	vec.push_back(x);
	vec.push_back(x*x*x);
	while (abs(vec.at(k)-vec.at(k-1))>=e && sw==0)
	{
		k++;
		vec.push_back((12. - vec.at(k - 1) * x) / vec.at(k - 2) * (vec.at(k - 2) + sqrt(vec.at(k - 3))));
		if (vec.at(k - 3) < 0 || (vec.at(k - 2) * vec.at(k - 2) + sqrt(vec.at(k - 3)) == 0))
			sw = 2;
	}
	switch (sw)
	{
		case 0:
		cout << k << " " << vec.at(k);
		case 2:
		cout << "Error";
	}
	return 0;
}

int glas(char ch)
{
	if (ch == 'a' || ch == 'e' || ch == 'u' || ch == 'o')
		return 1;
	else return 0;
}

string check(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int t;
		bool f = 0;
		if (glas(str[i]) == 1 && str[i+1] != ' ')
		{
			t = str.length();
			for (int j = t + 1; j >= i; j--)
				str[j] = str[j - 1];
			str[i] = '/';
		}
	}
	cout << str << endl;
	return str;
}

int fail()
{
	int k;
	bool f;
	string str, t;
	ifstream text ("text.txt");
	while (text)
	{
		text >> str;
		str = check(str);
	}
	return 0;
}

int main()
{
	fail();
	return 0;
}