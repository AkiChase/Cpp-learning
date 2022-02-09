#include <iostream>
using namespace std;

#include <map>

/*
map/multimap属于关联式容器，二叉树实现
map中所有元素都是pair<key, val> 键值对
所有元素都会根据key值排序
可以根据key值快速找到value值

map中不允许有重复的键
而multimap允许键重复
*/

template <typename T1, typename T2>
void printMap(map<T1, T2>m) {
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << "key= " << it->first << "\tval= " << it->second << endl;
	}
	cout << endl;
}


class MapCompare
{
public:
	bool operator()(int k1, int k2) {
		return k1 > k2; //降序
	}
};

void func_65() {
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10)); // 插入匿名对象 , pair中的类型会被强制转换为map中的类型
	m1.insert(pair<int, int>(5, 50)); //会自动按照key排序
	m1.insert(pair<int, int>(6, 60));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(4, 40));
	printMap(m1);

	map<int, int>m2(m1); //拷贝构造
	printMap(m2);
	map<int, int>m3 = m1; //赋值
	printMap(m3);

	cout << "---------------------" << endl;
	// 大小和交换
	cout << "是否为空" << m1.empty() << endl;
	cout << "大小" << m1.size() << endl;
	m2.clear();
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(2, 20));
	cout << "交换前" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "交换后" << endl;
	printMap(m1);
	printMap(m2);

	cout << "---------------------" << endl;
	//插入 删除
	// 有4种插入方式
	m3.clear(); // 清空
	m3.insert(pair<int, int>(1, 123));
	m3.insert(make_pair(2, 223)); //比较简单
	m3.insert(map<int, int>::value_type(3, 333));
	m3[4] = 444; // 注意这种方式：m[key] 若key不存在则会先初始化一个m[key] = 0;
	// 一般不使用这种方式插入，但若已知key可以用这种方式访问
	printMap(m3);

	//删除
	m3.erase(m3.begin()); //按迭代器删除
	m3.erase(4); // 按键删除，若无此key则不删除
	printMap(m3);

	cout << "---------------------" << endl;
	//查找 统计
	auto mit = m1.find(2); // 查找key是否存在，存在返回其迭代器，不存在返回map.end()
	if (mit != m1.end())
	{
		cout << "找到元素--key=" << mit->first << "\tval=" << mit->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	cout << "个数:" << m1.count(2) << endl;

	cout << "---------------------" << endl;
	//排序 还是用仿函数
	map<int, int, MapCompare> m4;
	m4.insert(make_pair(1, 1));
	m4.insert(make_pair(2, 2));
	m4.insert(make_pair(3, 3));
	for (auto it=m4.begin();it!=m4.end();it++)
	{
		cout << "key= " << it->first << "\tval= " << it->second << endl;
	}
}