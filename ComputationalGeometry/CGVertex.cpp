#include "pch.h"
#include "CGVertex.h"
#include <math.h>

namespace CGBase_NS {			
						
							//===Distance between vertices===//
	double
		CGVertex2d::Distance(CGVertex2d* V2) {

		double dx(V2->GetX() - this->GetX()), dy(V2->GetY() - this->GetY());

		return sqrt(dx * dx + dy * dy);
	}
							
								// === CGVertex2d_V === //	
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