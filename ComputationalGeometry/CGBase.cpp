#include "pch.h"
#include "CGBase.h"

namespace CGBase_NS {

	unsigned long long CGBase::EntCounter;

						// ===  онструкторы === //
	CGBase::CGBase() {
		
		this->EntType = EntityType::BASE;			
		++EntCounter;			
	}
//конструктор копировани€
	CGBase::CGBase(const CGBase& bg) {		
				
		EntType = bg.EntType;			
	}	
}