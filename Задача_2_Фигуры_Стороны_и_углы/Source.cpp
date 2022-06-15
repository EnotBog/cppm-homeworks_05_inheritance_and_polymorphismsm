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

	Figure() { sides_count = 0; this->name = "Фигура:"; };



	virtual void print_info()
	{
		std::cout << get_name() << "\n " << get_corn() << get_sides() << "" << "\n";
	}

protected:
	std::string get_sides()
	{
		return " ";
	}
	std::string get_corn()
	{
		return " ";
	}
	int get_sides_count()
	{
		return sides_count;
	}

	std::string get_name()
	{
		return name;
	}

	int sides_count;
	std::string name;
	std::string sides;
	std::string corn;
};


class Triangle : public Figure //треугольник скц
{
public:
	Triangle() { sides_count = 3; }
	Triangle(int a, int b, int c, int A, int B, int C)
	{
		this->a = a; this->b = b; this->c = c;
		this->A = A; this->B = B; this->C = C;
		this->name = "Треугольник:";
		this->sides_count = 3;
	}

protected:
	std::string get_sides()
	{
		std::string buf = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n" };
		return buf;
	}
	std::string get_corn()
	{
		std::string buf = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n" };
		return buf;
	}

	void print_info() override
	{
		std::cout << Triangle::get_name() << "\n" << Triangle::get_sides() << Triangle::get_corn() << "" << " " << " " << "\n"; // 
	}


	int a = 0, b = 0, c = 0;
	int A = 0, B = 0, C = 0;


};

class Equilateral_triangle :public Triangle //равносторонний треугольник
{
public:
	Equilateral_triangle(int a) :Triangle(a, a, a, 60, 60, 60)
	{
		this->name = "Равносторонний треугольник: ";
	}
};


class Isosceles_triangle :public Triangle // равнобедренный треугольник
{
public:
	Isosceles_triangle(int a, int c, int A, int B) :Triangle(a, a, c, A, B, A)
	{
		this->name = "Равнобедренный треугольник: ";
	}
};


class Rectangular_triangle :public Triangle //прямоугольный треугольник
{
public:
	Rectangular_triangle(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90)
	{
		this->name = "Прямоугольный треугольник: ";
	}
};



class Quadrangle : public Figure
{
public:
	Quadrangle() { };

	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C; this->D = D;
		this->name = "Четырехугольник:";
		this->sides_count = 4;
	}

protected:
	std::string get_sides()
	{
		std::string buf = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n" };
		return buf;
	}
	std::string get_corn()
	{
		std::string buf = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D) + "\n" };
		return buf;
	}
	void print_info() override
	{
		std::cout << Quadrangle::get_name() << "\n" << Quadrangle::get_sides() << Quadrangle::get_corn() << "" << "\n"; // 
	}


	int a = 0, b = 0, c = 0, d = 0;
	int A = 0, B = 0, C = 0, D = 0;
};

class Parallelogram : public Quadrangle // параллелограмм
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrangle(a, b, a, b, A, B, A, B)
	{
		this->name = "Параллелограм: ";
	}
};

class My_Rectangle : public Parallelogram // Прямоугольник
{
public:
	My_Rectangle(int a, int b) :Parallelogram(a, b, 90, 90)
	{
		this->name = "Прямоугольник: ";
	}

};

class Square : public My_Rectangle // квадрат
{
public:
	Square(int a) :My_Rectangle(a, a)
	{
		this->name = "Квадрат: ";
	}

};

class Rhomb : public Parallelogram //ромб
{
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
	{
		this->name = "Ромб: ";
	}

};

void print_info(Figure* q) 
{
	q->print_info();
}



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure f = {};
	Triangle triagle = { 10,20,30,50,60,70 };
	Rectangular_triangle r_triagle = { 10,20,30,50,60 };
	Isosceles_triangle i_triagle = { 10,20,10,60 };
	Equilateral_triangle e_triagle = { 10 };

	Quadrangle quadrangle = { 10,20,30,40,50,60,70,80 }; // четырех угольник
	My_Rectangle rectangle = { 10,20 };//прямоугольник
	Square square = { 20 }; // квадрат
	Parallelogram parallelogram = { 20,30,30,40 }; //параллелограмм
	Rhomb rhomb = { 30,30,40 }; // ромб


	Figure* p_triagle = &triagle;
	Figure* p_equilateral_triangle = &e_triagle;
	Figure* p_isosceles_triangle = &i_triagle;
	Figure* p_rectangular_triangle = &r_triagle;

	Figure* p_rectangle = &rectangle;
	Figure* p_quadrangle = &quadrangle;
	Figure* p_square = &square;
	Figure* p_parallelogram = &parallelogram;
	Figure* p_rhomb = &rhomb;

	
	print_info(p_rectangular_triangle);
	print_info(p_isosceles_triangle);
	print_info(p_equilateral_triangle);

	print_info(p_quadrangle);
	print_info(p_rectangle);
	print_info(p_square);
	print_info(p_parallelogram);
	print_info(p_rhomb);


	return 0;
}