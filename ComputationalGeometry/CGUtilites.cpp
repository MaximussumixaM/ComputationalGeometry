#include "pch.h"
#include "CGUtilites.h"

namespace CGBase_NS {		
						//===Vector composition insteed inheritence===//
	
					//===Vector composition insteed inheritence===//
	size_type_double_v Double_V::size() const {
		return values.size();
	}

	size_type_double_v Double_V::capacity() const {
		return values.capacity();
	}

	iterator_double_v Double_V::begin() {
		return values.begin();
	}

	iterator_double_v Double_V::end()
	{
		return values.end();
	}

	bool Double_V::empty() const {
		return values.empty();
	}

	const double& Double_V::front() const {
		return values.front();
	}

	const double& Double_V::back() const {
		return values.back();
	}

	void Double_V::push_back(value_type_double_v const& value) {
		values.push_back(value);
	}

	void Double_V::pop_back() {
		values.pop_back();
	}

	void Double_V::reserve(size_type_double_v capacity) {
		values.reserve(capacity);
	}

	void Double_V::resize(size_type_double_v size) {

		values.reserve(size);
	}

	void Double_V::clear() {

		values.clear();
	}

	double& Double_V::at(size_type_double_v n) {

		return values.at(n);

	}

	double &Double_V::operator[](size_type_double_v i) {

		return values[i];
	}
	
}