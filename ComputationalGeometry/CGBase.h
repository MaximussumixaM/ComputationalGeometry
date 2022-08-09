#pragma once
#ifndef CGBASE_H
#define CGBASE_H

#include <iostream>
#include "CGUtilites.h"

namespace CGBase_NS {
								//===Geometry types===//
	enum class EntityType {
		BASE = -1, VERTEX2D, VECTOR2D, POLYLINE, SPLINE2D, ALL
	};
									//===CGBase===//
	class CGBase
	{
	public:
		static unsigned long long EntCounter;// Objects counter
		
		CGBase();
		
		CGBase(const CGBase& bg);//copy constructor

		virtual ~CGBase() {};
		
		EntityType EntType;			
	};
}

#endif//CGBASE_H
	