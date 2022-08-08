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
		static unsigned long long EntCounter;		// ������� �������� (��� ���������������)
		
		CGBase();
		
		CGBase(const CGBase& bg);//����������� �����������

		virtual ~CGBase() {};
		
		EntityType EntType;			
	};
}

#endif
	