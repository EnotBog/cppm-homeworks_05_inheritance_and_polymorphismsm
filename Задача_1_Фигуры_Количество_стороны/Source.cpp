#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <windows.h>
#include <locale.h>
#include <fstream>

class Figure
{
public:
	Figure():Figure(0) {}
	

	int get_sides_count()
	{
		return sides_count;
	}

	std::string get_name()
	{
		return name;
	}

	std::string print_info()
	{
		std::string buf;
		buf = get_name() + " " + std::to_string(get_sides_count()) + "\n";
		return buf;
	}

protected:
	Figure(int n) 
	{
		sides_count = n; this->name = "Фигура:";
	}
	int sides_count;
	std::string name;
};



class Triangle : public Figure
{
public:
	Triangle():Figure(3) {this->name = "Треугольник:"; };
	
	std::string print_info() 
	{
		std::string buf;
		buf = get_name() + " " + std::to_string(get_sides_count())+"\n";
		return buf;
	}
};



class Quadrangle : public Figure
{
public:
	Quadrangle():Figure(4) {  this->name = "Четырехугольник:"; };
	
	std::string print_info()
	{
		std::string buf;
		buf = get_name() + " " + std::to_string(get_sides_count()) + "\n";
		return buf;
	}
};



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Quadrangle q = {};
	Triangle t = {};
	Figure f = {};

	std::cout << "Количество сторон:" << std::endl
			  << f.print_info() << t.print_info() << q.print_info();



	return 0;
}