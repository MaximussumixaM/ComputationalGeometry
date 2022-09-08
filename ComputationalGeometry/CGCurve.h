#ifndef CGCURVE_H
#define CGCURVE_H

#include "CGBase.h"
#include "CGVertex.h"
#include <vector>

namespace CGBase_NS {
								// === CGCurve2d === //
	class CGCurve2d : CGBase
	{  
//Using Zero - idiom(all constructors default)
	public:

		CGCurve2d(): //Default constructor
		Curve(std::make_shared<CGVertex2d_V>())
		{			
			EntType = EntityType::POLYLINE;
		};

		CGCurve2d(int n):
		Curve(std::make_shared<CGVertex2d_V>())
		{			
			Curve->resize(n);
			EntType = EntityType::POLYLINE;
		};
		CGCurve2d(const CGCurve2d&) = default;//Copy constructor

		CGCurve2d& operator=(const CGCurve2d&) = default;

		CGCurve2d(CGCurve2d&&) = default;

		CGCurve2d& operator=(CGCurve2d&&) = default;
		
		CGCurve2d(const CGVertex2d_V& v) 
		:CGCurve2d()

		{
			Curve = std::make_shared<CGVertex2d_V>(CGVertex2d_V(v));
		};		
		
		~CGCurve2d() = default;

		size_t Size() { return Curve->size(); }//Number of vertecies
		bool isEmpty();//Line is empty
		void Clear() { this->Curve->clear();}

		void Add(CGVertex2d& v);//Add Vertex to the end of curve	

		CGVertex2d* GetVertex(int);//Get vertex by index
		CGVertex2d* GetLastVertex();//Get last vertex	

	public:
		std::shared_ptr<CGVertex2d_V> Curve;
	};
}
#endif