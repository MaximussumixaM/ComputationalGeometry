#ifndef CGUTILITES_H
#define CGUTILITES_H

#include <string>
#include <vector>
#include<algorithm> // for copy() and assign() 
#include<iterator> // for back_inserter 

							  //=== Default accuracies ===//
#define EPSgeo_default 0.10                    // geometry accuracy
#define EPSmath_default 0.0000001              // math accuracy
#define MaxDoubleValue 99999999999.0		   // Double::MaxValue
#define MinDoubleValue -99999999999.0		   // Double::MinValue

extern double EPSgeo, EPSmath;

namespace CGBase_NS {

								// === CGUtilites === //
    class CGUtilites
    {
    public:				
		static constexpr double EPSgeo = EPSgeo_default;      // “очность геометрических построений
        static constexpr double EPSmath = EPSmath_default;    // “очность математических вычислений	
    };	

								// === Double_V === //	
//May use Zero-idiom(all constructors default)		
//Using copy-swap idiom
	typedef std::vector<double>::value_type value_type_double_v;
	typedef std::vector<double>::size_type  size_type_double_v;
	typedef std::vector<double>::iterator  iterator_double_v;

	// Double List - for future math structures
	class Double_V {
	public:

		Double_V() = default;

		Double_V(const Double_V& vv) {	// copy constructor

			//for (auto i = vv.adaptee.begin(); i != vv.adaptee.end(); i++) {
			//	this->adaptee.push_back(*i);
			//}
			//std::copy(vv.adaptee.begin(), vv.adaptee.end(), adaptee);
//https://www.geeksforgeeks.org/ways-copy-vector-c/			
			std::copy(vv.adaptee.begin(), vv.adaptee.end(), std::back_inserter(adaptee));
		};

		Double_V& operator=  (Double_V vv) {//Assignment operator	

			//for (auto i = vv.adaptee.begin(); i != vv.adaptee.end(); i++) {
			//	this->adaptee.push_back(*i);
			//}
			swap(*this, vv);

			return *this;
		};

		Double_V(Double_V&& vv) noexcept : // Move_Constructor
			Double_V()
		{			
				swap(*this, vv);
		};

			//Double_V& operator=(Double_V && other) noexcept { // move operator
			//	swap(*this, other);
			//	return *this;
			//};

		friend void swap(Double_V& l, Double_V& r)
		{
			//using std::swap;
			//swap(l.adaptee, r.adaptee);

//https://www.geeksforgeeks.org/difference-between-stdswap-and-stdvectorswap/
			l.adaptee.swap(r.adaptee);
		}

		~Double_V() = default;
		
						//===Vector composition insteed inheritence===//


		size_type_double_v size() const;

		size_type_double_v capacity() const;

		iterator_double_v begin();

		iterator_double_v end();

		bool empty() const;

		const double& front() const;

		const double& back() const;

		void push_back(value_type_double_v const& value);

		void pop_back();

		void reserve(size_type_double_v capacity);

		void resize(size_type_double_v size);

		void clear();

		double& at(size_type_double_v n);

		double& operator[](size_type_double_v i);

		
		

	private:
		std::vector<double> adaptee;//adapter
		
	};
}

#endif//CGUTILITES_H
