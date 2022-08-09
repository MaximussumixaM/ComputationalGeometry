#ifndef CGVERTEX_H
#define CGVERTEX_H

#include "CGBase.h"

namespace CGBase_NS {
	class CGVertex2d : CGBase
	{   
	public:
		double x, y;                     // Vertex coordinates
		double A, B;                     // Unit vectors components		
		bool VectorDefined;				// is Vector defined on vertex
	
							// === Constructors ===//
		CGVertex2d();

		CGVertex2d(double, double);  // Create vertex by two coordinates

		CGVertex2d(double, double, double, double);   // Create vertex by two coordinates and unit vector components
													
		CGVertex2d(const CGVertex2d&); // Copy constructor

		~CGVertex2d() {};

		CGVertex2d& operator=  (const CGVertex2d& v) {    //Assignment operator	

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

		double GetX() { return x; };// Get x coordinate
		double GetY() { return y; };// Get y coordinate		

		double Distance(CGVertex2d*);//distance between vertices	
	};	
}
#endif