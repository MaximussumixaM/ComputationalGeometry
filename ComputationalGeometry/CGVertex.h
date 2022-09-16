#ifndef CGVERTEX_H
#define CGVERTEX_H

#include "CGBase.h"

namespace CGBase_NS {
	//May use Zero-idiom(all constructors default)		
	//Using copy-swap idiom

								// === CGVertex2d === //
	class CGVertex2d : CGBase
	{  	
	
	public:
								// === Constructors ===//
		CGVertex2d() :
			x(0.0),
			y(0.0),
			A(1.0),
			B(0.0),
			VectorDefined(false)			
		{
			EntType = EntityType::VERTEX2D;
		
		};
						//=== Create vertex by two coordinates===//
		CGVertex2d(double xx, double yy) :
			x(xx),
			y(yy),
			A(1.0),
			B(0.0),
			VectorDefined(false)
		{
			EntType = EntityType::VERTEX2D;

		};
			 
				//=== Create vertex by two coordinates and unit vector components===//

		CGVertex2d(double xx, double yy, double aa, double bb) :
			x(xx),
			y(yy),			
			VectorDefined(true)
		{
			double s = sqrt(aa * aa + bb * bb);
			if (s != 0.0) {
				A = aa / s;
				B = bb / s;
			}
			else
			{
				A = aa; B = bb;
			}
		
			EntType = EntityType::VERTEX2D;

		};
		
							//==Create vertex on v1 to v2 direction===//

		CGVertex2d(const CGVertex2d& p1, const CGVertex2d& p2) :
			x(p1.x),
			y(p1.y),			
			VectorDefined(false) {
			
			double a = p2.GetX() - p1.GetX();
			double b = p2.GetY() - p1.GetY();
			double s = sqrt(a * a + b * b);
			if (s > CGUtilites::EPSmath)
			{
				A = a / s;
				B = b / s;
			}
			else { A = a; B = b; }
		
		}
													
		CGVertex2d(const CGVertex2d& vv) :// Copy constructor
			x(vv.x),
			y(vv.y),
			A(vv.A),
			B(vv.B),
			VectorDefined(vv.VectorDefined)
		{}; 

		CGVertex2d& operator=(CGVertex2d vv)
		{
			swap(*this, vv); 

			return *this;
		}		

		CGVertex2d(CGVertex2d&& other) noexcept // Оператор присваивания перемещением (move assignment)
			: CGVertex2d()
		{
			swap(*this, other);
		}

		friend void swap(CGVertex2d& l, CGVertex2d& r)
		{
			using std::swap;

			swap(l.x, r.x);
			swap(l.y, r.y);
			swap(l.A, r.A);
			swap(l.B, r.B);			
			swap(l.VectorDefined, r.VectorDefined);
		}

		~CGVertex2d() = default;
							
								// === Methods ===//
	
		void SetCoord(double xx, double yy) { // Set coordinates

			x = xx;
			y = yy;
		};
		void SetCoord(const CGVertex2d& vv) {
		
			x = vv.x;
			y = vv.y;

		};// Set coordinates by another vertex
		void SetX(double xx) { x = xx; };// Set x coordinate
		void SetY(double yy) { y = yy; };// Set y coordinate
		void SetA(double aa) { A = aa; }// Set A component
		void SetB(double bb) { B = bb; }// Set B component	

		double  GetX() const { return x; };// Get x coordinate
		double  GetY() const { return y; };// Get y coordinate		
		double  GetA() const { return A; };// Get A component
		double  GetB() const { return B; };// Get B component

		double Distance(const CGVertex2d&);//distance between vertices

	private:
		double x, y;                     // Vertex coordinates
		double A, B;                     // Unit vectors components		
		bool VectorDefined;				// is Vector defined on vertex
	};	

									// === CGVertex2d_V === //	

	typedef std::vector<CGVertex2d>::value_type value_type_CGVertex2d_V;
	typedef std::vector<CGVertex2d>::size_type  size_type_CGVertex2d_V;
	typedef std::vector<CGVertex2d>::iterator  iterator_CGVertex2d_V;

//May use Zero-idiom(all constructors default)		
//Using copy-swap idiom
	class CGVertex2d_V { // Контейнер для хранения вертексов	

	public:

		CGVertex2d_V() = default;

		CGVertex2d_V(const CGVertex2d_V& vv) {	// Конструктор копирования

			std::copy(vv.values.begin(), vv.values.end(), std::back_inserter(values));					

		};	

		CGVertex2d_V& operator=  (CGVertex2d_V vv) {//Assignment operator	

			swap(*this, vv);

			return *this;
		}

		CGVertex2d_V(CGVertex2d_V&& vv) noexcept //move constructor
			: CGVertex2d_V()
		{
			swap(*this, vv);
		}		

		friend void swap(CGVertex2d_V& l, CGVertex2d_V& r)
		{
			l.values.swap(r.values);
		}

		~CGVertex2d_V() {};

					//===Vector composition insteed inheritence===//
	
		size_type_CGVertex2d_V size() const;

		size_type_CGVertex2d_V capacity() const;

		iterator_CGVertex2d_V begin();

		iterator_CGVertex2d_V end();

		bool empty() const;

		const CGVertex2d& front() const;

		const CGVertex2d& back() const;

		void push_back(value_type_CGVertex2d_V const& value);

		void pop_back();

		void reserve(size_type_CGVertex2d_V capacity);

		void resize(size_type_CGVertex2d_V size);

		void clear();

		CGVertex2d& at(size_type_CGVertex2d_V n);

		CGVertex2d& operator[](size_type_CGVertex2d_V i);

	private:
		std::vector<CGVertex2d> values;//adapter
	
	};	
}
#endif //CGVERTEX_H