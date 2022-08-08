#pragma once
#ifndef CGBASE_H
#define CGBASE_H

#include <iostream>
#include "CGUtilites.h"

namespace CGBase_NS {

	enum class EntityType {
		BASE = -1, VERTEX2D, VECTOR2D, POLYLINE, SPLINE2D, ALL
	};
	
	class CGBase
	{
	public:
		static unsigned long long EntCounter;		// счетчик объектов (для идентификаторов)
		
		CGBase();
		
		CGBase(const CGBase& bg);//конструктор копирования

		virtual ~CGBase() {};
		
		EntityType EntType;			
	};
}

#endif
	