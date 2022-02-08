#include <iostream>
using namespace std;
#include <vector>

//vector和数组非常相似
//是动态扩展的（每次扩容都要新建空间，拷贝过去，然后释放原有空间）

template <typename T>
void printVector(vector<T>& v) {
	for (auto it = v.begin(); it != v.end(); it++) // 长的类型就用auto 省事
	{
		cout << *it << " ";
	}
	cout << endl;
}

void func_31() {
	//构造函数
	vector<int> v1; // 最普通的无参构造
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	printVector(v1);

	vector<int>v2(v1.begin() + 1, v1.end() - 1); //使用区间的方式构造
	printVector(v2);

	vector<int>v3(5, 6); // n个m 5个6
	printVector(v3);

	vector<int>v4(v3); //拷贝构造
	printVector(v4);

	cout << "-------------------" << endl;
	// 赋值

	v2 = v1; // 直接赋值
	printVector(v2);

	v2.assign(v1.begin() + 1, v1.end() - 1); // 将 n到m之间的数据拷贝赋值给v2
	printVector(v2);

	v3.assign(10, 6); // 将n个m赋值给v3
	printVector(v3);
	cout << "-------------------" << endl;

	// vector 的容量和大小
	cout << v1.empty() << endl; //判断是否为空
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.resize(10); // 重新指定容器长度，若变长则填充默认值(一般是0)，变短则移除多余的
	printVector(v1);

	v1.resize(15, 6); //重新指定容器长度 并指定默认值为6
	printVector(v1);

	cout << "-------------------" << endl;
	//插入和删除

	v1.push_back(3); //尾部插入
	printVector(v1);

	v1.pop_back(); //尾部删除
	printVector(v1);

	v1.insert(v1.begin() + 1, 666); //向位置1插入 注意这个位置必须用迭代器
	printVector(v1);

	v1.insert(v1.begin() + 1, 2, 223); //向位置n插入m个 ele
	printVector(v1);

	v1.erase(v1.begin() + 1); // 删除迭代器指向位置的元素
	printVector(v1);

	v1.erase(v1.begin() + 1, v1.end() - 1); //删除迭代器指向位置之间的所有元素
	printVector(v1);

	v1.clear(); //清空所有元素
	cout << "容量：" << v1.capacity() << "\t大小:" << v1.size() << endl;

	cout << "-------------------" << endl;
	v2.resize(5);
	// vector数据存取
	// 除了可以用迭代器，还能用其他方式
	v2.at(1) = 123;
	v2[2] = 666;
	v2.front() = 456; // 返回第一个元素的引用
	v2.back() = 789; //返回最后一个元素的引用
	printVector(v2);

	cout << "-------------------" << endl;
	// 两个vector容器互换，实质是指向互换
	cout << "v2: ";
	printVector(v2);
	cout << "v3: ";
	printVector(v3);

	cout << "互换后" << endl;
	v2.swap(v3);
	cout << "v2: ";
	printVector(v2);
	cout << "v3: ";
	printVector(v3);

	// 利用好swap可以收缩空间（注意resize只会修改size不会修改容量）
	// 因为动态数组扩容时，并不一定是插入一个数据扩容一次（这样频繁扩容效率低），在有时候是提前扩容更多空间
	// 但是如果数组不再变化了，这些多余的空间就浪费了
	// 可以通过swap来收缩

	for (int i = 0; i < 1000 ; i++)
	{
		v3.push_back(i);
	}

	cout << "v3容量： " << v3.capacity() << endl;
	cout << "v3大小： " << v3.size() << endl;
	
	vector<int>(v3).swap(v3);  //用一个匿名的对象，以v3内数据做拷贝构造，然后把匿名对象和v3互换
	// 匿名对象当前行执行后就释放
	
	cout << "收缩后\nv3容量： " << v3.capacity() << endl;
	cout << "v3大小： " << v3.size() << endl;

	cout << "-------------------" << endl;
	// 预留空间，若知道自己的数据量大概是多少，可以设置好这个预留空间，有效减少动态扩容的次数
	// 预留空间不同于resize，其操作的是容量，不会给予初始化默认值
	cout << "v4容量： " << v4.capacity() << endl;
	cout << "v4大小： " << v4.size() << endl;
	v4.reserve(100); //设置预留的空间
	cout << "v4容量： " << v4.capacity() << endl;
	cout << "v4大小： " << v4.size() << endl;


}