#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
ios::app	追加模式。所有写入都追加到文件末尾。
ios::ate	文件打开后定位到文件末尾。
ios::in		打开文件用于读取。
ios::out	打开文件用于写入。注意：不会删除旧内容，新内容会覆盖旧内容，未覆盖到的部分保持不变。
ios::trunc	如果该文件已经存在，先删除旧文件，再
*/

void writeFile() {
	ofstream ofs; //output file stream 输出流 即 写文件
//fstream fs; // 读写都可
	ofs.open("C:/Users/如初/Desktop/test.txt", ios::out); // 路径可用绝对路径或者相对路径
	ofs << "测试" << endl;
	ofs << "测试\n111" << endl;
	ofs << "结束" << endl;
	ofs.close();
}

void readFile() {
	ifstream ifs; // input ...			输入流 即 读文件
	ifs.open("C:/Users/如初/Desktop/test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//char buf[1024] = { 0 };
	//while (ifs >> buf) //每行输出一次，但是不会输出空行
	//{
	//	cout << buf << endl;
	//}
	//while (ifs.getline(buf, sizeof(buf))) // 另一种方式，可以输出空行
	//{
	//	cout << buf << endl;
	//}

	// 个人比较喜欢的方式
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

// 二进制读写文件可以避免他人直接用文本编辑器打开文本文件（不过有些内容仍会显示）
// 注意尽量不要用string，会出现问题（string的siziof问题）
// 可以写入一个对象，那么占用的空间仅仅是sizeof(对象)
void writeBFile() {
	TempData t = { "测试名", 666 };

	fstream fs;
	fs.open("C:/Users/如初/Desktop/test.txt", ios::binary | ios::out);

	//把对象的地址转化为 const char*
	fs.write((const char*)&t, sizeof(t));
	fs.close();

}

void readBFile() {
	TempData t;

	fstream fs;
	fs.open("C:/Users/如初/Desktop/test.txt", ios::binary | ios::in);
	if (!fs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//把对象的地址转化为 const char*
	fs.read((char*)&t, sizeof(TempData));
	cout << t.age << t.name << endl;
	fs.close();
}

void func_61() {
	writeBFile();
}