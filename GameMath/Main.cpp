#include <iostream>
#include <cmath>

int main()
{

	int x = 2;
	int y;

	std::cin >> x;

	y = x * x;

	std::cout << y << std::endl;

	// closed 
	// 1

	int z;
	int w;

	std::cin >> z;

	w = z * 2;

	std::cout << w << std::endl;
	
	// 2

	int b;
	int c;

	std::cin >> b;
	
	c = b * b * b;

	std::cout << c <<  std::endl;
	
	// 3

	float radian;
	float degree;

	std::cin >> degree;

	radian = (degree * 3.14) / 180;

	std::cout << "the radian is " << radian << std::endl;

	// 4

	float radian2;
	float degree2;

	std::cin >> radian;

	degree = (radian * 180) / 3.14;

	std::cout << "degree is " << degree << std::endl;
	
	//open
	//1

	float o;
	float k;

	std::cin >> o;

	k = o * 2 + 2 * o - 7;

	std::cout << k << std::endl;

	//2 MKI

	float ab;
	float ba;
	float aa;
	float bb;

	std::cin >> bb;
	std::cin >> ab;
	std::cin >> ba;

	aa = -bb / (2 * 4) + sqrt( bb - 4 * ab * ba) / 2 * ab;

	std::cout << aa << " is the answer for the Quadratic equation" << std::endl;

	//2 MKII

	float start;
	float end;
	float alpha;
	float Final;

	std::cin >> start;
	std::cin >> end;
	std::cin >> alpha;

	Final = start + alpha *(end - start);

	std::cout << Final << std::endl;

	float p1y;
	float p1x;
	float p2y;
	float p2x;
	float D;

	std::cout << "Input the x and y for your 2 points" << std::endl;
	std::cin >> p1y;
	std::cin >> p1x;
	std::cin >> p2y;
	std::cin >> p2x;

	D = std::sqrt((p2y - p1y) / 2 + (p2x - p1x) / 2);

	std::cout << "The distance between the given points are" << D << std::endl;



	while(true) {}

}