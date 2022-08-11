#include "pch.h"
#include "CGVertex.h"
#include <math.h>

namespace CGBase_NS {
							// === Constructors === //
			
	CGVertex2d::CGVertex2d() {

		x = y = 0.0;
		A = 1.0; B = 0.0;
		EntType = EntityType::VERTEX2D;
	};

	CGVertex2d::CGVertex2d(const CGVertex2d& vv) {

		this->x = vv.GetX();
		this->y = vv.GetY();
		this->A = vv.GetA();
		this->B = vv.GetB();
		EntType = EntityType::VERTEX2D;
	}
					//=== Create vertex by two coordinates===//
	CGVertex2d::CGVertex2d(double xx, double yy) {

		x = xx; y = yy;
		A = 1.0; B = 0.0;
		EntType = EntityType::VERTEX2D;			
	}
						//=== Create vertex by two coordinates and unit vector components===//
	CGVertex2d::CGVertex2d(double xx, double yy, double a, double b) {
		x = xx; y = yy;
		double s = sqrt(a * a + b * b);
		if (s != 0.0) {
			A = a / s;
			B = b / s;
		}
		else
		{
			A = a; B = b;
		}
		EntType = EntityType::VERTEX2D;	
	}								
	
						//==Create vertex on v1 to v2 direction===//
	CGVertex2d::CGVertex2d(CGVertex2d *  p1, CGVertex2d *  p2) {
	
		x = p1->x;
		y = p1->y;  A = 1.0; B = 0.0;
		double a = p2->GetX() - p1->GetX();
		double b = p2->GetY() - p1->GetY();
		double s = sqrt(a * a + b * b);
		if (s > CGUtilites::EPSmath)
		{
			A = a / s;
			B = b / s;
		}
		else { A = a; B = b; }
		EntType = EntityType::VERTEX2D;	
	}
							//===Distance between vertices===//
	double
		CGVertex2d::Distance(CGVertex2d* V2) {

		double dx(V2->GetX() - this->GetX()), dy(V2->GetY() - this->GetY());

		return sqrt(dx * dx + dy * dy);
	}

}