#include<iostream>
#include<vector>
#include<cmath>
float f(float x, float y)
{
	return ((4 * x * x) - 2) * cos(y);
}
std::vector<float> zeros(int n) {
	std::vector<float> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	return arr;
}
std::vector<float> generateArray(int n, float h) {
	std::vector<float> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = i * h;
	}
	return arr;
}
void Out(std::vector<float> array)
{
	for (int i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	setlocale(0, "");
	int n = 10, k = 0;
	float
		x0 = 0,
		xN = 1,
		eps = 0.0001,
		h = (xN - x0) / n;
	std::vector<float>y;
	std::vector<float>x;
	float a, b, c, d, s, y1, y2, e;
	while (k < n + 1) 
	{
		x = generateArray(n + 1, h);
		y = zeros(n + 1);
		y[0] = 1;
		
		for (int k = 0; k < 4; k++)
		{
			a = h * f(x[k], y[k]);
			b = h * f(x[k] + (h / 2), y[k] + (a / 2));
			c = h * f(x[k] + (h / 2), y[k] + (b / 2));
			d = h * f(x[k] + h, y[k] + c);
			y[k+1] = y[k] + (a + (2 * b) + (2 * c) + d) / 6.;
		}
		
		k = 4;
		
		while (k < n + 1)
		{
			y1 = y[k - 4] + (4 * h) / 3 * (2 * f(x[k - 3], y[k - 3]) - f(x[k - 2], y[k - 2]) + 2 * f(x[k - 1], y[k - 1]));
			y2 = y[k - 2] + (h / 3) * (f(x[k - 2], y[k - 2]) + 4 * f(x[k - 1], y[k - 1]) + f(x[k], y1));
			e = abs(y2 - y1) / 29.;
			if (e < eps) 
			{
				y[k] = y2;
			}
			else
			{
				h /= 2;
				n *= 2;
				break;
			}
			k++;
		}
		if (k == n) 
		{
			break;
		}
	}
	Out(x);
	Out(y);
	system("pause");
}