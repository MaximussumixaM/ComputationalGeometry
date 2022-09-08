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
		CGVector2d() { A = 1.0; B = 0.0; this->EntType = EntityType::VECTOR2D; }
	
		CGVector2d(CGVertex2d const & , CGVertex2d const &);
	
		CGVector2d(double, double);    

		CGVector2d(const CGVector2d& vec) { A = vec.A; B = vec.B; }	//Copy constructor

		CGVector2d& operator=  (const CGVector2d& vec) { //Assignment operator	

			this->A = vec.A; 
			this->B = vec.B;
			return *this;
		}

		CGVector2d(CGVector2d&& other) noexcept // �������� ������������ ������������ (move assignment)
		{
			swap(*this, other);
		}

		CGVector2d& operator=(CGVector2d&& other) noexcept // �������� ������������ ������������ (move assignment)
		{
			swap(*this, other);
			return *this;
		}

		friend void swap(CGVector2d& l, CGVector2d& r)
		{
			using std::swap;
			swap(l.A, r.A);
			swap(l.B, r.B);			
		}

		~CGVector2d() {};

		double GetA() const { return A; };      // Get A Component
		double GetB() const { return B; };      // Get B Component

		double SetA(double a) { A = a; };      // Set A Component
		double SetB(double b) { B = b; };      // Set B Component

	};
}

#endif//CGVECTOR_H