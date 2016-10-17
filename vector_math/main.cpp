#include "vector_math.h"
#include <vector>
#include <functional>

int arr[5][5];

int getArr(function<bool(int)> func)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (func(arr[i][j]))
			{
				return arr[i][j];
			}
		}
	}

	return -1;
}

void show(int two)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i * 10 +j == two)
			{
				cout << i << "\t" << j << endl;
			}
		}
	}
}

float FastInvSqrt(float x) {
	float xhalf = 0.5f * x;
	int i = *(int*)&x;         // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);  // what the fuck?
	x = *(float*)&i;
	x = x*(1.5f - (xhalf*x*x));
	return x;
}

int main()
{
	cout << "输入三个坐标:";
	int x, y, z;
	cin >> x >> y >> z;

	auto v = Vector_math(x, y, z);

	cout << "再输入三个坐标:";
	cin >> x >> y >> z;

	auto u = Vector_math(x, y, z);
	cout << "相乘的结果为:" << v*u << endl;

	system("pause");
	return 0;
}