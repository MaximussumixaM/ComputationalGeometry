#ifndef CGCURVE_H
#define CGCURVE_H

#include "CGBase.h"
#include "CGVertex.h"
#include <vector>

namespace CGBase_NS {
	//class CGVertex2d_V;
								// === CGCurve2d === //
	class CGCurve2d : CGBase
	{  
//Using copy-swap idiom
	public:

		CGCurve2d() : //Default constructor
			Curve(CGVertex2d_V())
		{
			EntType = EntityType::POLYLINE;
		};

		CGCurve2d(int n) :
			Curve(CGVertex2d_V())
		{
			Curve.resize(n);
			EntType = EntityType::POLYLINE;
		};

		CGCurve2d(const CGVertex2d_V& vv)
			:CGCurve2d()

		{
			Curve = CGVertex2d_V(vv);
		};

		CGCurve2d(const CGCurve2d& cc)// Конструктор копирования
		{	
			Curve = CGVertex2d_V(cc.Curve);
		};

		CGCurve2d& operator=  (CGCurve2d cc) {//Assignment operator	

			swap(*this, cc);

			return *this;
		}

		CGCurve2d(CGCurve2d&& cc) noexcept //move constructor
			: CGCurve2d()
		{
			swap(*this, cc);
		}

		friend void swap(CGCurve2d& l, CGCurve2d& r)
		{			
			swap(l.Curve, r.Curve);
		}

		~CGCurve2d() {};		

		size_t Size() { return Curve.size(); }//Number of vertecies
		bool isEmpty();//Line is empty
		void Clear() { this->Curve.clear();}

		void Add(const CGVertex2d& v) {//Add Vertex to the end of curve	
		
			Curve.push_back(v);
		
		};

		CGVertex2d GetVertex(int i) { return Curve.at(i); };//Get vertex by index
		CGVertex2d GetLastVertex() { return Curve.at(Curve.size() - 1); };//Get last vertex	

	private:
		CGVertex2d_V Curve;
	};
}
#endif