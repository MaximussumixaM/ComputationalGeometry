#include "pch.h"
#include "CGBase.h"

namespace CGBase_NS {

	unsigned long long CGBase::EntCounter;

						// === Конструкторы === //
	CGBase::CGBase() {
		
		this->EntType = EntityType::BASE;			
		++EntCounter;			
	}
//конструктор копирования
	CGBase::CGBase(const CGBase& bg) {		
				
		EntType = bg.EntType;			
	}	
}