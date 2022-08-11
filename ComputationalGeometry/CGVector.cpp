#include "pch.h"
#include "CGVector.h"
#include <cmath>

namespace CGBase_NS {
								// === Constructors === //
	CGVector2d::CGVector2d(double x, double y) {
		double s = sqrt(x * x + y * y);
		if (s > CGUtilites::EPSmath)
		{
			A = x / s;
			B = y / s;
		}
		this->EntType = EntityType::VECTOR2D;		

	}
	
	CGVector2d::CGVector2d(CGVertex2d const &  p1, CGVertex2d const & p2) : A(1.0), B(0.0) {
		
		double a = p2.GetX() - p1.GetX();
		double b = p2.GetY() - p1.GetY();
		double s = sqrt(a * a + b * b);
		if (s > CGUtilites::EPSmath)
		{
			A = a / s;
			B = b / s;
		}
		this->EntType = EntityType::VECTOR2D;
	}
}
