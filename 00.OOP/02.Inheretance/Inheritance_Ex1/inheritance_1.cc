#include<iostream>

class parent
{
	private:
		int x;
		int y;
	public:
		parent() : x(0),y(0){}
		parent(int _x,int _y) : x(_x),y(_y){std::cout<<"ConstructorParentClass\n";}
		void setX(int _x){x=_x;}
		void setY(int _y){y=_y;}
		int getX(){return x;}
		int getY(){return y;}
		int getAddXY(){return x+y;}
		int getSubXY(){return x-y;}
		int getProductXY(){return x*y;}
		void print(){std::cout<<"Print fun of parent class\n";}
		~parent(){std::cout<<"DestructorParentClass\n";}
};

class child : public parent
{
	private:
		int z;
	public:
		child():parent(){z=0;}
		child(int _x,int _y,int _z):parent(_x,_y){z=_z;std::cout<<"ConstructorChildClass\n";}
		void setY(int _z){z=_z;}
		int getZ(){return z;}
		int getAdd(){return getAddXY()+z;}
		int getSub(){return z-getSubXY();}
		int getProduct(){return z*getProductXY();}
		void print(){std::cout<<"Print fun of child class\n";}
		~child(){std::cout<<"DestructorChildClass\n";}
};

int main()
{
	child c1(2,3,4);
	std::cout<<"Add: "<<c1.getAdd()<<"\n";
	std::cout<<"Sub: "<<c1.getSub()<<"\n";
	std::cout<<"Product: "<<c1.getProduct()<<"\n";
	c1.print();
	return 0;
}
