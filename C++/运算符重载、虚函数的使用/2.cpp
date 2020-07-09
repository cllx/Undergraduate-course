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
	int* head;                          //���������׵�ַ
    int size;                           //����Ԫ�صĸ���
public:
    CArray(int s=0);                    //���캯��
    CArray(const CArray& obj)           //�������캯�� 
	{
	    size = obj.size;
		p = obj.p;
		head = obj.head;
	}
    ~ CArray(){};                                                        //������������
    void getvalue();                                                     //����Ԫ�س�ʼ������
    friend CArray operator-(CArray& a,CArray& b);                        //���ء����������
    void show();                                                         //����Ԫ���������o
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
		cout<<"��������ĵ�"<<i+1<<"����:";
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
    array1.getvalue();                                    // array1����Ԫ�س�ʼ��
    CArray array2(array1);
    //array2.getvalue();                                    // array2����Ԫ�س�ʼ��
	CArray array3(3);
    array3 = array1-array2;                               //�������
    array3.show();                                        //�������Ԫ��
}
