#ifndef DCLINK_H
#define DCLINK_H
//双向循环链表
typedef int datatype;
//方便修改
//当然也可以写成模板来适应更多的数据类型
struct dclink{
	datatype data;//数据定义
	struct dclink *pre;
	struct dclink *next;//前驱和后继指针
};
class DCLink
{
public:
	DCLink();//default constructor
	DCLink(datatype data);//单参constructor
	void add(datatype data);//添加data到链表中去
	datatype getData(int pos)const;//获得指定位置的数据
	int deleteData(int pos);//删除指定位置的数据
	int modify(int pos, datatype data);//更改指定位置的数据
	int insert(int pos, datatype data);//在指定位置插入数据
	void sort()const;//循环链表排序
	int rePrint()const;//双向循环链表转置没啥意义，转置输出还有那么点意义
	int print()const;//打印链表
	~DCLink();//destructor
	int getLength()const;//得到链表的长度
private:
	//DCLink operator=(const DCLink &dcl){}//assignment constructor 禁止
	//DCLink (const DCLink &dcl){}//copy constructor 禁止
	struct dclink *head;//头指针
	struct dclink *cur;//当前指针
	int size;//大小
};
#endif