#ifndef CGVERTEX_H
#define CGVERTEX_H

#include "CGBase.h"

namespace CGBase_NS {

								// === CGVertex2d === //
	class CGVertex2d : CGBase
	{   
	private:
		double x, y;                     // Vertex coordinates
		double A, B;                     // Unit vectors components		
		bool VectorDefined;				// is Vector defined on vertex
	public:
							// === Constructors ===//
		CGVertex2d();

		CGVertex2d(double, double);  // Create vertex by two coordinates

		CGVertex2d(double, double, double, double);   // Create vertex by two coordinates and unit vector components
													
		CGVertex2d(const CGVertex2d&); // Copy constructor

		~CGVertex2d() = default;

		CGVertex2d& operator=  (const CGVertex2d& v) {//Assignment operator	

			if (this == &v) {
				return *this;
			}
			this->x = v.x; this->y = v.y;
			this->A = v.A; this->B = v.B;

			return *this;
		}

		CGVertex2d(CGVertex2d *  v1, CGVertex2d *  v2);//Create vertex on v1 to v2 direction
	
		void SetCoord(double, double, double);// Set coordinates
		void SetCoord(const CGVertex2d*);// Set coordinates by another vertex
		void SetX(double xx) { x = xx; };// Set x coordinate
		void SetY(double yy) { y = yy; };// Set y coordinate
		void SetA(double a) { A = a; }// Set A component
		void SetB(double b) { B = b; }// Set B component	

		double  GetX() const { return x; };// Get x coordinate
		double  GetY() const { return y; };// Get y coordinate		
		double  GetA() const { return A; };// Get A component
		double  GetB() const { return B; };// Get B component

		double Distance(CGVertex2d*);//distance between vertices	
	};	

									// === CGVertex2d_V === //	
	typedef std::vector<CGVertex2d>::value_type value_type_CGVertex2d_V;
	typedef std::vector<CGVertex2d>::size_type  size_type_CGVertex2d_V;
	typedef std::vector<CGVertex2d>::iterator  iterator_CGVertex2d_V;

	class CGVertex2d_V { // Контейнер для хранения вертексов
	
	public:
		CGVertex2d_V() = default;
		CGVertex2d_V(const CGVertex2d_V& v_v) {	// Конструктор копирования

			//if (v_v == nullptr || v_v->size() == 0)
			//	return;
			//
			for (auto i = v_v.adaptee.begin(); i != v_v.adaptee.end(); i++) {
				this->adaptee.push_back(*i);
			}
					

		};	

		CGVertex2d_V& operator=  (const CGVertex2d_V& v_v) {//Assignment operator	

			//for (auto i = v_v->begin(); i != v_v->end(); i++) {
			//	this->push_back(*i);
			//}
			for (auto i = v_v.adaptee.begin(); i != v_v.adaptee.end(); i++) {
				this->adaptee.push_back(*i);
			}
			return *this;
		}

		CGVertex2d_V(CGVertex2d_V&& other) noexcept // Оператор присваивания перемещением (move assignment)
		{
			swap(*this, other);
		}

		CGVertex2d_V& operator=(CGVertex2d_V&& other) noexcept // Оператор присваивания перемещением (move assignment)
		{
			swap(*this, other);
			return *this;
		}

		friend void swap(CGVertex2d_V& l, CGVertex2d_V& r)
		{
			using std::swap;
			swap(l.adaptee, r.adaptee);
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
		std::vector<CGVertex2d> adaptee;//adapter
	};	
}
#endif //CGVERTEX_H