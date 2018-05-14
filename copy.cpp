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
	char source[100] = "C:\\Users\\yl_so\\Desktop\\2\\2.2\\"; //Դ�ļ���ַ
	char dest[100] = "C:\\Users\\yl_so\\Desktop\\2\\2SUM\\"; //Ŀ���ļ���ַ
	char s[10] = ".TIFF";
	int i = 1;  //�ӵ�i�ſ�ʼ��ѡ
	int gap = 1; //��ѡ���
	int cnt = 1265;//Ŀ���ļ�����ʼ����
	char fill = { '0' };//Ŀ���ļ���ǰ׺���
	int width = 4;//Ŀ���ļ������
	while (i<2008)  //С��������
	{
		char sor[256] = {};
		char des[256] = {};
		//Դ�ļ���ת��
		stringstream str1;
		str1.fill(fill);
		str1.width(width);
		str1 << i;
		char tmp1[256];
		str1 >> tmp1;
		strcat_s(sor, source);
		strcat_s(sor, tmp1);
		strcat_s(sor, s);
		//Ŀ���ļ���ת��
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