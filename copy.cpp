#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int cpyfile(char* source, char* dest)
{
	ifstream in;
	ofstream out;
	in.open(source, ios::binary);
	if (in.fail())
	{
		cout << "open source error" << endl;
		in.close();
		out.close();
		return 0;
	}
	out.open(dest, ios::binary);
	if (in.fail())
	{
		cout << "open destination error" << endl;
		in.close();
		out.close();
		return 0;
	}
	else
	{
		out << in.rdbuf();
		in.close();
		out.close();
		return 1;
	}
}
int main()
{
	char source[100] = "C:\\Users\\yl_so\\Desktop\\2\\2.2\\"; //源文件地址
	char dest[100] = "C:\\Users\\yl_so\\Desktop\\2\\2SUM\\"; //目标文件地址
	char s[10] = ".TIFF";
	int i = 1;  //从第i张开始挑选
	int gap = 1; //挑选间隔
	int cnt = 1265;//目标文件名起始数字
	char fill = { '0' };//目标文件名前缀填充
	int width = 4;//目标文件名宽度
	while (i<2008)  //小于总张数
	{
		char sor[256] = {};
		char des[256] = {};
		//源文件名转换
		stringstream str1;
		str1.fill(fill);
		str1.width(width);
		str1 << i;
		char tmp1[256];
		str1 >> tmp1;
		strcat_s(sor, source);
		strcat_s(sor, tmp1);
		strcat_s(sor, s);
		//目标文件名转换
		stringstream str2;
		str2.fill(fill);
		str2.width(width);
		str2 << cnt;
		char tmp2[256];
		str2 >> tmp2;
		strcat_s(des, dest);
		strcat_s(des, tmp2);
		strcat_s(des, s);
		if (cpyfile(sor, des)) { cout << "success copy file " << i << "! " << endl; }
		else { cout << "fail!"; }
		i += gap;
		cnt++;
	}
	system("pause");
	return 0;
}