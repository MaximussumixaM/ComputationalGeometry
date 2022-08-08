//#pragma once
#ifndef CGVERTEX_H
#define CGVERTEX_H

#include "CGBase.h"

namespace CGBase_NS {
// ����� ��� �������� � ��������� ���������� ������� � 2D
	class CGVertex2d : CGBase
	{   
	public:
		double x, y;                     // ���������� ����� 
		double A, B;                     // ���������� ���������� �������
		double Bulge;                    // ���������� (������� �������� ������������ ����)
		int index;						// ��� ����� ��������� � �����-���� ��������
		double t;						// �������� ������� (����� ������� �� �������)
		bool VectorDefined;				// ��������� ������ ��� ���		
		double knucle_angle;				// ���� ����� � �������
	
							// === ������������ ===//
		CGVertex2d();

		CGVertex2d(double, double);   // �������� ������� �� ���� �����������

		CGVertex2d(double, double, double, double);   // �������� ������� �� ���� ����������� � ����������� ���������� �������
													
		CGVertex2d(const CGVertex2d&);  // ����������� �����������

		~CGVertex2d() {};

		CGVertex2d& operator=  (const CGVertex2d& v) {     // �������� ������������	

			this->x = v.x; this->y = v.y;
			this->A = v.A; this->B = v.B;
			this->Bulge = v.Bulge;
			this->index = v.index;	

			return *this;
		}
		CGVertex2d(CGVertex2d *  v1, CGVertex2d *  v2);     // ��������� ������� � ������� � v1 � ����. � v2
	
		void SetCoord(double, double, double);        // ��������� �������� ���������
		void SetCoord(const CGVertex2d*);             // ��������� �������� ���������
		
		void SetCoord(CGVertex2d* p);                  // ��������� �������� ��������� �� ��������� �����
		
		double GetX() { return x; };                    // ��������� ���������� x
		double GetY() { return y; };                    // ��������� ���������� y
		
		void SetX(double xx) { x = xx; };               // ��������� �������� ���������� x
		void SetY(double yy) { y = yy; };               // ��������� �������� ���������� y
	
		void SetA(double a) { A = a; }
		void SetB(double b) { B = b; }

		double Distance(CGVertex2d*);		
	};	
}
#endif