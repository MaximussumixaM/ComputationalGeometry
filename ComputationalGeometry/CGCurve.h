#ifndef CGCURVE_H
#define CGCURVE_H

#include "CGBase.h"
#include "CGVertex.h"

namespace CGBase_NS {
								// === CGCurve2d === //
	class CGCurve2d : CGBase
	{   
	public:
		CGVertex2d_V Curve;

		CGCurve2d();//Default constructor
		CGCurve2d(int);                            
		CGCurve2d(const CGCurve2d&);//Copy constructor
		CGCurve2d(CGVertex2d_V*);   
		CGCurve2d& operator=  (const CGCurve2d& v) {//Assignment operator	

			for (auto i = Curve.begin(); i != Curve.end(); i++) {
				this->Add(*i);
			}
			EntType = EntityType::POLYLINE;

			return *this;
		}
		~CGCurve2d() {};

		unsigned int Size() { return Curve.size(); }//Number of vertecies
		bool isEmpty();//Line is empty
		void Clear() { this->Curve.clear();}

		void Add(CGVertex2d* const& v);//Add Vertex to the end of curve	

		CGVertex2d* GetVertex(int);//Get vertex by index
		CGVertex2d* GetLastVertex();//Get last vertex		
	};
}
#endif