#ifndef CGVERTEX_H
#define CGVERTEX_H

#include "CGBase.h"
#include "Containers.h"

using namespace Containers_NS;

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

		~CGVertex2d() {};

		CGVertex2d& operator=  (const CGVertex2d& v) {//Assignment operator	

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
	
	class CGVertex2d_V : public CGList<CGVertex2d*> { // Контейнер для хранения вертексов
	
	public:
		CGVertex2d_V() {};
		CGVertex2d_V(CGVertex2d_V* v_v) {	// Конструктор копирования

			if (v_v == nullptr || v_v->size() == 0)
				return;

			for (auto i = v_v->begin(); i != v_v->end(); i++) {			
				this->push_back(*i);
			}
			

		};

		~CGVertex2d_V() {};

		CGVertex2d_V& operator=  (CGVertex2d_V* v_v) {//Assignment operator	

			for (auto i = v_v->begin(); i != v_v->end(); i++) {
				this->push_back(*i);
			}
			return *this;
		}
	};	
}
#endif //CGVERTEX_H