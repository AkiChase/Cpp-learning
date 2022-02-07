#include <iostream>
using namespace std;
#include <string>

//string封装了char指针，是一个字符容器

void func_23() {
	// 字符串构造
	string s1; // 默认无参构造

	string s2("测试字符串");

	string s3(s2); // 使用string来初始化
	string s4(10, 'a'); // 使用n个字符

	cout << "------------------" << endl;

	//字符串赋值
	//常用= 不做展示
	s1.assign("一二三四五", 4); // assign(s, int n) 前n个字符，n省略则整个字符串
	cout << s1 << endl;

	s1.assign(10, 'k'); // 重复n次字符
	cout << s1 << endl;

	cout << "------------------" << endl;

	//字符串拼接
	s1 += "哈哈哈";
	cout << s1 << endl;

	s1.append("123");
	cout << s1 << endl;

	s1.append("哈哈哈哈哈哈哈哈哈哈", 2); //拼接字符串的前n个字符
	cout << s1 << endl;

	s1.append("12嘿嘿3456789", 2, 4); //拼接字符串从n开始的m个字符 [n, n+m)
	cout << s1 << endl;

	cout << "------------------" << endl;

	// 字符串查找
	cout << "pos = " << int(s1.find("嘿嘿")) << endl; // 未找到返回-1
	cout << "pos = " << int(s1.rfind("嘿嘿")) << endl; // 从右开始找，即最后一个查找结果

	// 字符串替换
	s1.replace(0, 3, "哦豁哦豁哦豁"); // 把[n, n+m) 替换为输入的字符串，返回的是当前字符串的引用（不会复制一份）
	cout << s1 << endl;

	cout << "------------------" << endl;
	
	// 字符串比较
	// string也可以使用> < = >=等等运算符
	// 将字符的ascii码进行比较，依次比较字符，无字符的部分用0补全
	// 若s1 > s2 返回1，s1=s2
	s1 = "abcd";
	s2 = "zb";
	cout << s1.compare(s2) << endl;

	cout << "------------------" << endl;
	//访问字符（可以修改字符）
	s1[2] = 'T';
	s1.at(1) = 'A';
	cout << s1 << endl;

	cout << "------------------" << endl;
	// 插入字符串
	s1.insert(1, "哈哈哈哈");
	cout << s1 << endl;

	//删除字符串
	s1.erase(1, 8); //删除掉[n,n+m)
	cout << s1 << endl;

	cout << "------------------" << endl;
	// 截取子串(会返回一个新的string）
	cout << s1.substr(1, 2) << endl; //截取[n,n+m)

}