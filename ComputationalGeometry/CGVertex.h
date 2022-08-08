//#pragma once
#ifndef CGVERTEX_H
#define CGVERTEX_H

#include "CGBase.h"

namespace CGBase_NS {
// Класс для хранения и изменения параметров вершины в 2D
	class CGVertex2d : CGBase
	{   
	public:
		double x, y;                     // Координаты точки 
		double A, B;                     // Компоненты единичного вектора
		double Bulge;                    // Выпуклость (Тангенс четверти центрального угла)
		int index;						// для учета положения в каких-либо массивах
		double t;						// параметр вершины (когда вершина на сплайне)
		bool VectorDefined;				// Определен вектор или нет		
		double knucle_angle;				// угол слома в вершине
	
							// === Конструкторы ===//
		CGVertex2d();

		CGVertex2d(double, double);   // Создание вершины по трем координатам

		CGVertex2d(double, double, double, double);   // Создание вершины по трем координатам и компонентам единичного вектора
													
		CGVertex2d(const CGVertex2d&);  // Конструктор копирования

		~CGVertex2d() {};

		CGVertex2d& operator=  (const CGVertex2d& v) {     // оператор присваивания	

			this->x = v.x; this->y = v.y;
			this->A = v.A; this->B = v.B;
			this->Bulge = v.Bulge;
			this->index = v.index;	

			return *this;
		}
		CGVertex2d(CGVertex2d *  v1, CGVertex2d *  v2);     // Создается вершина с началом в v1 и напр. в v2
	
		void SetCoord(double, double, double);        // Установка значений координат
		void SetCoord(const CGVertex2d*);             // Установка значений координат
		
		void SetCoord(CGVertex2d* p);                  // Установка значений координат от двумерной точки
		
		double GetX() { return x; };                    // Получение координаты x
		double GetY() { return y; };                    // Получение координаты y
		
		void SetX(double xx) { x = xx; };               // Установка значения координаты x
		void SetY(double yy) { y = yy; };               // Установка значения координаты y
	
		void SetA(double a) { A = a; }
		void SetB(double b) { B = b; }

		double Distance(CGVertex2d*);		
	};	
}
#endif