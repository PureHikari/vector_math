#pragma once
#include <iostream>

using namespace std;

class Vector_math
{
private:
	//矢量在三个轴上的坐标：
	int _x;
	int _y;
	int _z;
public:
	Vector_math();

	//带参数的构造函数
	Vector_math(int x, int y, int z):_x(x),_y(y),_z(z){}

	void show();

	//获得矢量的模
	float getMagnitude(){return sqrt(_x*_x+_y*_y+_z*_z);}

	//重载==操作符，用于判断是否相等
	bool operator ==(const Vector_math &v) const;

	//重载+,返回一个加好的矢量
	Vector_math operator +(const Vector_math &v) const;
	//重载-
	Vector_math operator -(const Vector_math &v) const;

	//重载x
	Vector_math operator *(const float &k) const;

	float operator *(const Vector_math &v) const;

	//重载/
	Vector_math operator /(const float &k) const;
};

void Vector_math::show()
{
	cout << "x:" << _x << ",y:" << _y << ",z:" << _z << endl;
}

bool Vector_math::operator==(const Vector_math &v) const
{
	if(v._x==this->_x && v._y==this->_y && v._z==this->_z)
	{
		return true;
	}

	return false;
}

Vector_math Vector_math::operator+(const Vector_math &v) const
{
	auto x=v._x+this->_x;
	auto y=v._y+this->_y;
	auto z=v._z+this->_z;

	return Vector_math(x,y,z);
}

Vector_math Vector_math::operator-(const Vector_math &v) const
{
	auto x=v._x-this->_x;
	auto y=v._y-this->_y;
	auto z=v._z-this->_z;

	return Vector_math(-x,-y,-z);
}

Vector_math Vector_math::operator*(const float &k) const
{
	auto x=k*this->_x;
	auto y=k*this->_y;
	auto z=k*this->_z;

	return Vector_math(x,y,z);
}

float Vector_math::operator*(const Vector_math &v) const
{
	auto x = this->_x*v._x;
	auto y = this->_y*v._y;
	auto z = this->_z*v._z;

	return x + y + z;
}

Vector_math Vector_math::operator/(const float &k) const
{
	auto x=this->_x/k;
	auto y=this->_y/k;
	auto z=this->_z/k;

	return Vector_math(x,y,z);
}