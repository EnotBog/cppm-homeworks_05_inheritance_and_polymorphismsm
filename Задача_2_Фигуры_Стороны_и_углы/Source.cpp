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

	Figure() :Figure(0, "Фигура:") {};



	void print_info()
	{
		std::cout << name << "\n" << get_sides() << get_corn() << "" << " " << " " << "\n"; // 
	}


protected:

	Figure(int sides_count, std::string name)
	{
		this->sides_count = sides_count;
		this->name = name;
	}


	virtual std::string get_sides()
	{
		return " ";
	}
	virtual std::string get_corn()
	{
		return " ";
	}
	int get_sides_count()
	{
		return sides_count;
	}

	

	int sides_count;
	std::string name;




};


class Triangle : public Figure //треугольник скц
{
public:

	Triangle() :Triangle(3, "Треугольник:") {};
	Triangle(int a, int b, int c, int A, int B, int C) :Triangle(a, b, c, A, B, C, 3, "Треугольник:") {};

protected:

	Triangle(int sides_count, std::string name)
	{
		this->name = name;
		this->sides_count = sides_count;
	}
	Triangle(int a, int b, int c, int A, int B, int C, int sides_count, std::string name)
	{

		{
			this->a = a; this->b = b; this->c = c;
			this->A = A; this->B = B; this->C = C;
			this->name = name;
			this->sides_count = sides_count;
		}
	}

	std::string get_sides()override
	{
		std::string buf = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n" };
		return buf;
	}
	std::string get_corn() override
	{
		std::string buf = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n" };
		return buf;
	}

	
	int a = 0, b = 0, c = 0;
	int A = 0, B = 0, C = 0;



};

class Equilateral_triangle :public Triangle //равносторонний треугольник
{
public:
	Equilateral_triangle(int a) :Triangle(a, a, a, 60, 60, 60, 3, "Равносторонний треугольник: ")
	{

	}
};


class Isosceles_triangle :public Triangle // равнобедренный треугольник
{
public:
	Isosceles_triangle(int a, int c, int A, int B) :Triangle(a, a, c, A, B, A, 3, "Равнобедренный треугольник: ")
	{

	}
};


class Rectangular_triangle :public Triangle //прямоугольный треугольник
{
public:
	Rectangular_triangle(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90, 3, "Прямоугольный треугольник: ")
	{

	}
};



class Quadrangle : public Figure
{
public:
	Quadrangle() { };

	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) :Quadrangle(a, b, c, d, A, B, C, D, 4, "Четырехугольник:") {};


protected:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, int sides_count, std::string name)
	{
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C; this->D = D;
		this->name = name;
		this->sides_count = sides_count;
	}
	std::string get_sides() override
	{
		std::string buf = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n" };
		return buf;
	}
	std::string get_corn() override
	{
		std::string buf = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D) + "\n" };
		return buf;
	}
	//void print_info() override
	//{
	//	std::cout << name << "\n" << Quadrangle::get_sides() << Quadrangle::get_corn() << "" << "\n"; // 
	//}

	int a = 0, b = 0, c = 0, d = 0;
	int A = 0, B = 0, C = 0, D = 0;

};

class Parallelogram : public Quadrangle // параллелограмм
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrangle(a, b, a, b, A, B, A, B, 4, "Параллелограм: ")
	{

	}
protected:
	Parallelogram(int a, int b, int A, int B, int sides_count, std::string name) :Quadrangle(a, b, a, b, A, B, A, B, sides_count, name)
	{

	}

};

class My_Rectangle : public Parallelogram // Прямоугольник
{
public:
	My_Rectangle(int a, int b) :Parallelogram(a, b, 90, 90, 4, "Прямоугольник: ")
	{

	}
protected:
	My_Rectangle(int a, int b, int sides_count, std::string name) :Parallelogram(a, b, 90, 90, sides_count, name)
	{

	}
};

class Square : public My_Rectangle // квадрат
{
public:
	Square(int a) :My_Rectangle(a, a, 4, "Квадрат: ")
	{

	}

};

class Rhomb : public Parallelogram //ромб
{
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B, 4, "Ромб: ")
	{

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