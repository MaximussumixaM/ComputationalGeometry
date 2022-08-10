#include "pch.h"
#include "CGCurve.h"#

namespace CGBase_NS {
							// === Constructors === //
	CGCurve2d::CGCurve2d() {
		Curve.clear();
		EntType = EntityType::POLYLINE;	
	}

	CGCurve2d::CGCurve2d(int n) {

		Curve.clear(); 
		Curve.resize(n);
		for (auto i = Curve.begin(); i != Curve.end(); i++) {	
			this->Add(*i);
		}
	
		EntType = EntityType::POLYLINE;		
	}	
	
	CGCurve2d::CGCurve2d(const CGCurve2d& cur) {
		//Curve->clear();
	
		for (auto i = Curve.begin(); i != Curve.end(); i++) {	
			this->Add(*i);
		}
		EntType = EntityType::POLYLINE;
		
	}
					//===Add Vertex to the end of curve===//	
	void
		CGCurve2d::Add(CGVertex2d* const & v) {
		
			Curve.push_back(v);	
	}

	
						//===Get vertex by index===//
	CGVertex2d*
		CGCurve2d::GetVertex(int i) {
		if (i < 0 || i >= Curve.size()) return nullptr;
		CGVertex2d* v = new CGVertex2d(*Curve.at(i));
		
		return v;
	}
						//=== Извлечь последнюю вершину===//
	CGVertex2d*
		CGCurve2d::GetLastVertex() {
	
			if (this->Curve.size() == 0) return nullptr;
			
			CGVertex2d* v = new CGVertex2d(*(Curve.at(Curve.size() - 1)));
			return v;
	}
}

	
