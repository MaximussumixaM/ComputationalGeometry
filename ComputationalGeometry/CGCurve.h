#ifndef CGCURVE_H
#define CGCURVE_H

#include "CGBase.h"
#include "CGVertex.h"
#include <vector>

namespace CGBase_NS {
								// === CGCurve2d === //
	class CGCurve2d : CGBase
	{   
	public:
		//CGVertex2d_V* Curve;
		std::shared_ptr<CGVertex2d_V> Curve;
	

		CGCurve2d();//Default constructor
		CGCurve2d(int);                            
		CGCurve2d(const CGCurve2d&);//Copy constructor
		CGCurve2d(const CGVertex2d_V&);
		CGCurve2d& operator=  (const CGCurve2d& cur) {//Assignment operator	

			for (auto i = cur.Curve->begin(); i != cur.Curve->end(); i++) {
				this->Add(*i);
			}
			EntType = EntityType::POLYLINE;

			return *this;
		}
		CGCurve2d(CGCurve2d&& cur)noexcept : Curve(std::move(cur.Curve))  {

			//Curve->clear();
			Curve = std::move(cur.Curve);
			EntType = EntityType::POLYLINE;
			//Может сделать Curve.Clear, но в базовом clear уже есть
			cur.Curve = nullptr;
			cur.EntType = EntityType::BASE;

		}

		CGCurve2d& operator=(CGCurve2d&& cur) noexcept
		{
			//assert(this != &cur); // assert if this is not a temporary
			if (this != &cur)
			{
				Curve = std::move(cur.Curve);
			}
			cur.Curve = nullptr;
			cur.EntType = EntityType::BASE;

			return *this;
		}
		~CGCurve2d() {
			//delete Curve;
		};

		size_t Size() { return Curve->size(); }//Number of vertecies
		bool isEmpty();//Line is empty
		void Clear() { this->Curve->clear();}

		void Add(CGVertex2d& v);//Add Vertex to the end of curve	

		CGVertex2d* GetVertex(int);//Get vertex by index
		CGVertex2d* GetLastVertex();//Get last vertex		
	};
}
#endif