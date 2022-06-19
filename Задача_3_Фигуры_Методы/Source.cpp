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

	Figure(): sides_count(0),name ("Фигура:") {};

	
	
	void print_info() 
	{
		std::cout << name << "\n" << check << "\n" << "Количество сторон: " << sides_count << "\n" << get_sides() << get_corn() << "" << " " << " " << "\n"; // 
	}

protected:
	Figure(int sides_count, std::string name):sides_count(3),name ("Фигура:")
	{

	}

	virtual bool check_bool() 
	{
		if (sides_count==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual void check_func()
	
	{
		if (check_bool())
		{
			check = "Правильная";
		}
		else {
			check = "Неправильная";
		}
	}

	virtual std::string get_sides()
	{
		return " ";
	}
	virtual std::string get_corn()
	{
		return " ";
	}
	


	int sides_count;
	std::string name;
	std::string sides;
	std::string corn;
	std::string check;

};

/////////////////////////////////////////////////////////////////////////////////////////////

class Triangle : public Figure //треугольник скц
{
public:
	Triangle():Figure(3,"Треугольник")
	{
	
	}
	Triangle(const int a, const int b, const int c, const int A, const int B, const int C):Triangle(a,b,c,A,B,C,3, "Треугольник:")
	{

	}

protected:

	Triangle (const int a, const int b, const int c, const int A, const int B, const int C, const int sides_count, const std::string name)
	{
		this->a = a; this->b = b; this->c = c;
		this->A = A; this->B = B; this->C = C;
		this->name = name;
		this->sides_count = sides_count;
		check_func();
	}


	std::string get_sides() override
	{
		std::string buf = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n" };
		return buf;
	}
	std::string get_corn() override
	{
		std::string buf = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n" };
		return buf;
	}

	//void print_info() override
	//{
	//	std::cout <<name <<"\n" << check << "\n" << "Количество сторон: " << sides_count << "\n" << Triangle::get_sides() << Triangle::get_corn() << "" << " " << " " << "\n"; // 
	//}

	bool check_bool() override
	{
		if((A+B+C)==180)
		{
			return true;
		}
		else 
		{
			return false; 
		}
	}
	

	int a=0, b=0, c=0;
	int A=0, B=0, C=0;
};
/////////////////////////////////////////////////////////////////////////////////////////////////

class Equilateral_triangle:public Triangle //равносторонний треугольник
{
public:
	Equilateral_triangle(int a):Triangle( a,a,a,60,60,60,3, "Равносторонний треугольник: ")
	{
	
	}
protected:
	

	bool check_bool () override
	{
		if ((Triangle::check_bool()) && (a==b)&&(b==c)&&(c==a))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



class Isosceles_triangle:public Triangle // равнобедренный треугольник
{
public:
	Isosceles_triangle(int a,int b,int A,int B):Triangle(a,b,a,A,B,A,3, "Равнобедренный треугольник: ")
	{
		
	}
protected:
	bool check_bool() override
	{
		if ((Triangle::check_bool()) && (a==c)&&(A==C))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



class Rectangular_triangle:public Triangle //прямоугольный треугольник
{
public:
	Rectangular_triangle(int a, int b, int c, int A, int B):Triangle(a,b,c,A,B,90,3, "Прямоугольный треугольник: ")
	{

	}

protected:
	bool check_bool() override
	{
		if ((Triangle::check_bool()) && (C == 90))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Quadrangle : public Figure
{
public:
	Quadrangle():Figure(4, "Четырехугольник:") {}

	Quadrangle(const int a, const int b, const int c, const int d, const int A, const int B, const int C, const int D):Quadrangle(a,b,c,d,A,B,C,D,4, "Четырехугольник:") {}

protected:

	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D,int sides_count, std::string name)
	{
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C; this->D = D;
		this->name = name;
		this->sides_count = sides_count;
		check_func();
	}

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
	//void print_info() override
	//{
	//	std::cout << this->name << "\n" << this->check << "\n" << "Количество сторон: " << sides_count << "\n"  << Quadrangle::get_sides() << Quadrangle::get_corn() << "" << "\n"; // 
	//}

	bool check_bool() override
	{
		if ((A+B+C+D)==360) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int a = 0, b = 0, c = 0, d = 0;
	int A = 0, B = 0, C = 0, D = 0;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Parallelogram : public Quadrangle // параллелограмм
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrangle(a, b, a, b, A, B, A, B, 4, "Параллелограм: ")
	{

	}
	//параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
protected:

	Parallelogram(int a, int b, int A, int B, int sides_count, std::string name) :Quadrangle(a, b, a, b, A, B, A, B, sides_count, name)
	{

	}

	bool check_bool() override
	{
		if ((Quadrangle::check_bool())&&(a == c && b == d) && (A == C && B == D))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



class My_Rectangle : public Parallelogram // Прямоугольник
{
public:
	My_Rectangle(int a, int b) :Parallelogram(a, b, 90, 90,4, "Прямоугольник: ")
	{

	}

protected:

	My_Rectangle(int a, int b, int sides_count, std::string name) :Parallelogram(a, b, 90, 90, sides_count, name)
	{

	}
	
	bool check_bool() override
	{
		if ((a == c && b == d) && a != b && (A == 90 && B == 90 && C == 90 && D == 90))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};



class Square : public My_Rectangle // квадрат
{
public:
	Square(int a) :My_Rectangle(a, a, 4, "Квадрат: ")
	{

	}
protected:

	bool check_bool() override
	{
		if ((a == c && b == d) && (a == b && c == d) && (A == 90 && B == 90 && C == 90 && D == 90))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
};

class Rhomb: public Parallelogram //ромб
{
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B, 4, "Ромб: ")
	{

	}

protected:

	bool check_bool() override
	{
		if ((a == c && b == d) && (a == b && c == d) && (A == C && B == D)&&(A+B==180))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
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
	Triangle triagle = {10,20,30,50,60,70};
	Rectangular_triangle r_triagle = {10,20,30,60,60};
	Isosceles_triangle i_triagle = { 10,20,50,60 }; 
	Equilateral_triangle e_triagle = { 10 };

	Quadrangle quadrangle = {10,20,30,40,100,100,70,80}; // четырех угольник
	Parallelogram parallelogram = { 20,30,30,40 }; //параллелограмм
	My_Rectangle rectangle = { 10,20 };//прямоугольник
	Square square = { 20 }; // квадрат
	Rhomb rhomb = {10,126,54}; // ромб

	
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