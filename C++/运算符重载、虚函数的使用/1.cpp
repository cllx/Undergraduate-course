#include <iostream>
using namespace std;
class CShape
{
private:
    double x,y;
public: 
    CShape(double a=0,double b=0)
	{
	    x = a;
		y = b;
	};
    virtual double area(){return 0;}; 
    double getx();
    double gety();
};
double CShape::getx()
{
    return x;
}
double CShape::gety()
{
    return y;
}
class CRectangler: public CShape
{
private:
	double s;
public:
    CRectangler(double a,double b): CShape(a,b){};
    double area();
};
double CRectangler::area()
{
    s = getx()*gety();
	return s;
}
class CCircle: public CShape
{
private:
	double s;
public:
    CCircle(double a): CShape(a){};
	double area();
};
double CCircle::area()
{
    s = getx()*getx()*3.14;
	return s;
}
void main()
{
    CRectangler r(12.0,5.0);
    CCircle c(3.0);
    CShape *pt;                      //基类对象指针
    pt=&c;                           //基类对象指针pt指向派生类对象c
    cout<<pt->area()<<endl; 
    pt=&r;                           //基类对象指针pt指向派生类对象r
    cout<<pt->area()<<endl; 
}