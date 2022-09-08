#include "pch.h"
#include "CGCurve.h"

namespace CGBase_NS {
							
						//===Get vertex by index===//
	CGVertex2d*
		CGCurve2d::GetVertex(int i) {
		//if (i < 0 || i >= Curve->size()) return nullptr;
		//CGVertex2d* v = new CGVertex2d(Curve->at(i));
		CGVertex2d* v = new CGVertex2d();
		return v;
	}
						//=== Извлечь последнюю вершину===//
	CGVertex2d*
		CGCurve2d::GetLastVertex() {
	
			//if (this->Curve->size() == 0) return nullptr;
			
			//CGVertex2d* v = new CGVertex2d(Curve->at(Curve->size() - 1));
		CGVertex2d* v;
			return v = new CGVertex2d();
	}
}

	
