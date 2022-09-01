#include "pch.h"
#include "CGUtilites.h"

namespace CGBase_NS {		
						//===Vector composition insteed inheritence===//
	
					//===Vector composition insteed inheritence===//
	size_type_double_v Double_V::size() const {
		return adaptee.size();
	}

	size_type_double_v Double_V::capacity() const {
		return adaptee.capacity();
	}

	iterator_double_v Double_V::begin() {
		return adaptee.begin();
	}

	iterator_double_v Double_V::end()
	{
		return adaptee.end();
	}

	bool Double_V::empty() const {
		return adaptee.empty();
	}

	const double& Double_V::front() const {
		return adaptee.front();
	}

	const double& Double_V::back() const {
		return adaptee.back();
	}

	void Double_V::push_back(value_type_double_v const& value) {
		adaptee.push_back(value);
	}

	void Double_V::pop_back() {
		adaptee.pop_back();
	}

	void Double_V::reserve(size_type_double_v capacity) {
		adaptee.reserve(capacity);
	}

	void Double_V::resize(size_type_double_v size) {

		adaptee.reserve(size);
	}

	void Double_V::clear() {

		adaptee.clear();
	}

	double& Double_V::at(size_type_double_v n) {

		return adaptee.at(n);

	}

	double &Double_V::operator[](size_type_double_v i) {

		return adaptee[i];
	}
	
}