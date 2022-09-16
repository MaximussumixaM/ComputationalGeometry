#include "pch.h"
#include "CGVertex.h"
#include <math.h>

namespace CGBase_NS {		
	
						
							//===Distance between vertices===//
	double
		CGVertex2d::Distance(const CGVertex2d& vv) {

		double dx(vv.GetX() - this->GetX()), dy(vv.GetY() - this->GetY());

		return sqrt(dx * dx + dy * dy);
	}
							
								// === CGVertex2d_V === //	
						//===Vector composition insteed inheritence===//	

	size_type_CGVertex2d_V CGVertex2d_V::size() const {
		return values.size();
	}

	size_type_CGVertex2d_V CGVertex2d_V::capacity() const {
		return values.capacity();
	}

	iterator_CGVertex2d_V CGVertex2d_V::begin() {
		return values.begin();
	}

	iterator_CGVertex2d_V CGVertex2d_V::end() {
		return values.end();
	}

	bool CGVertex2d_V::empty() const {
		return values.empty();
	}

	const CGVertex2d& CGVertex2d_V::front() const {
		return values.front();
	}

	const CGVertex2d& CGVertex2d_V::back() const {
		return values.back();
	}



	void CGVertex2d_V::push_back(value_type_CGVertex2d_V const& value) {
		values.push_back(value);
	}

	void CGVertex2d_V::pop_back() {
		values.pop_back();
	}

	void CGVertex2d_V::reserve(size_type_CGVertex2d_V capacity) {
		values.reserve(capacity);
	}

	void CGVertex2d_V::resize(size_type_CGVertex2d_V size) {

		values.reserve(size);
	}

	void CGVertex2d_V::clear() {

		values.clear();
	}

	CGVertex2d& CGVertex2d_V::at(size_type_CGVertex2d_V n) {

		return values.at(n);

	}

	CGVertex2d& CGVertex2d_V::operator[](size_type_CGVertex2d_V i) {

		return values[i];
	}

}