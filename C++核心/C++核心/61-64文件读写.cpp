#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
ios::app	׷��ģʽ������д�붼׷�ӵ��ļ�ĩβ��
ios::ate	�ļ��򿪺�λ���ļ�ĩβ��
ios::in		���ļ����ڶ�ȡ��
ios::out	���ļ�����д�롣ע�⣺����ɾ�������ݣ������ݻḲ�Ǿ����ݣ�δ���ǵ��Ĳ��ֱ��ֲ��䡣
ios::trunc	������ļ��Ѿ����ڣ���ɾ�����ļ�����
*/

void writeFile() {
	ofstream ofs; //output file stream ����� �� д�ļ�
//fstream fs; // ��д����
	ofs.open("C:/Users/���/Desktop/test.txt", ios::out); // ·�����þ���·���������·��
	ofs << "����" << endl;
	ofs << "����\n111" << endl;
	ofs << "����" << endl;
	ofs.close();
}

void readFile() {
	ifstream ifs; // input ...			������ �� ���ļ�
	ifs.open("C:/Users/���/Desktop/test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//char buf[1024] = { 0 };
	//while (ifs >> buf) //ÿ�����һ�Σ����ǲ����������
	//{
	//	cout << buf << endl;
	//}
	//while (ifs.getline(buf, sizeof(buf))) // ��һ�ַ�ʽ�������������
	//{
	//	cout << buf << endl;
	//}

	// ���˱Ƚ�ϲ���ķ�ʽ
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
}


class TempData
{
public:
	char name[64];
	int age;
};

// �����ƶ�д�ļ����Ա�������ֱ�����ı��༭�����ı��ļ���������Щ�����Ի���ʾ��
// ע�⾡����Ҫ��string����������⣨string��siziof���⣩
// ����д��һ��������ôռ�õĿռ������sizeof(����)
void writeBFile() {
	TempData t = { "������", 666 };

	fstream fs;
	fs.open("C:/Users/���/Desktop/test.txt", ios::binary | ios::out);

	//�Ѷ���ĵ�ַת��Ϊ const char*
	fs.write((const char*)&t, sizeof(t));
	fs.close();

}

void readBFile() {
	TempData t;

	fstream fs;
	fs.open("C:/Users/���/Desktop/test.txt", ios::binary | ios::in);
	if (!fs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//�Ѷ���ĵ�ַת��Ϊ const char*
	fs.read((char*)&t, sizeof(TempData));
	cout << t.age << t.name << endl;
	fs.close();
}

void func_61() {
	writeBFile();
}