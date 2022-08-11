#ifndef CGVECTOR_H
#define CGVECTOR_H

#include "CGBase.h"
#include "CGVertex.h"

namespace CGBase_NS {
							// === CGVector2d === //
	class CGVector2d : public CGBase
	{
	public:
		double A; //Components of unit vector
		double B;
	public:
		CGVector2d() {this->EntType = EntityType::VECTOR2D; }
	
		CGVector2d(CGVertex2d const & , CGVertex2d const &);
	
		CGVector2d(double, double);    

		CGVector2d(const CGVector2d& vec) { A = vec.A; B = vec.B; }	//Copy constructor

		CGVector2d& operator=  (const CGVector2d& vec) { //Assignment operator	

			this->A = vec.A; 
			this->B = vec.B;
			return *this;
		}

		~CGVector2d() {};

		double GetA() const { return A; };      // Get A Component
		double GetB() const { return B; };      // Get B Component

		double SetA(double a) { A = a; };      // Set A Component
		double SetB(double b) { B = b; };      // Set B Component

	};
}

#endif//CGVECTOR_H