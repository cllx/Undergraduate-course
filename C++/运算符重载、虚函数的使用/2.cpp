# include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
class CArray
{
private:
    int* p;
	int* head;                          //存放数组的首地址
    int size;                           //数组元素的个数
public:
    CArray(int s=0);                    //构造函数
    CArray(const CArray& obj)           //拷贝构造函数 
	{
	    size = obj.size;
		p = obj.p;
		head = obj.head;
	}
    ~ CArray(){};                                                        //析构函数声明
    void getvalue();                                                     //数组元素初始化函数
    friend CArray operator-(CArray& a,CArray& b);                        //重载“＋”运算符
    void show();                                                         //数组元素输出函数o
};
CArray::CArray(int s)
{
    size = s;
} 
void CArray::getvalue()
{
	p = new int[size];
	head = p;
    for(int i=0;i<size;i++)
	{
		cout<<"输入数组的第"<<i+1<<"个数:";
		cin>>(*p);
		p++;
	}
	p = head;
} 
CArray operator-(CArray& a,CArray& b)       
{
	CArray tem(a.size);
	tem.p = new int[tem.size];
	tem.head = tem.p;
	for(int i=0;i<a.size;i++)
	{
	    *tem.p = *a.p - *b.p;
		tem.p++;a.p++;b.p++;
	}
	return tem;
	delete []tem.p;delete []a.p;delete []b.p;
}
void CArray::show()
{
    for(int i=0;i<size;i++)
	{
	    cout<<(*head)<<endl;
		head++;
	}
}  
void main()
{ 
    CArray array1(3); 
    array1.getvalue();                                    // array1数组元素初始化
    CArray array2(array1);
    //array2.getvalue();                                    // array2数组元素初始化
	CArray array3(3);
    array3 = array1-array2;                               //数组相加
    array3.show();                                        //输出数组元素
}
