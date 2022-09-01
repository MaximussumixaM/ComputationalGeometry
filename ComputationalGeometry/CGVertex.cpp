#include "pch.h"
#include "CGVertex.h"
#include <math.h>

namespace CGBase_NS {
							// === Constructors === //
			
	CGVertex2d::CGVertex2d() {

		x = y = 0.0;
		A = 1.0; B = 0.0;
		VectorDefined = false;
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
		VectorDefined = false;
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
		VectorDefined = true;
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



							//===Vector composition insteed inheritence===//
	

	size_type_CGVertex2d_V CGVertex2d_V::size() const {
		return adaptee.size();
	}

	size_type_CGVertex2d_V CGVertex2d_V::capacity() const {
		return adaptee.capacity();
	}

	iterator_CGVertex2d_V CGVertex2d_V::begin() {
		return adaptee.begin();
	}

	iterator_CGVertex2d_V CGVertex2d_V::end() {
		return adaptee.end();
	}

	bool CGVertex2d_V::empty() const {
		return adaptee.empty();
	}

	const CGVertex2d& CGVertex2d_V::front() const {
		return adaptee.front();
	}

	const CGVertex2d& CGVertex2d_V::back() const {
		return adaptee.back();
	}



	void CGVertex2d_V::push_back(value_type_CGVertex2d_V const& value) {
		adaptee.push_back(value);
	}

	void CGVertex2d_V::pop_back() {
		adaptee.pop_back();
	}

	void CGVertex2d_V::reserve(size_type_CGVertex2d_V capacity) {
		adaptee.reserve(capacity);
	}

	void CGVertex2d_V::resize(size_type_CGVertex2d_V size) {

		adaptee.reserve(size);
	}

	void CGVertex2d_V::clear() {

		adaptee.clear();
	}

	CGVertex2d& CGVertex2d_V::at(size_type_CGVertex2d_V n) {

		return adaptee.at(n);

	}

	CGVertex2d& CGVertex2d_V::operator[](size_type_CGVertex2d_V i) {

		return adaptee[i];
	}

}