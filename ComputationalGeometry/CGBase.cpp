#include "pch.h"
#include "CGBase.h"

namespace CGBase_NS {

	unsigned long long CGBase::EntCounter;

						// === Constructors === //
	CGBase::CGBase() {
		
		this->EntType = EntityType::BASE;			
		++EntCounter;			
	}
//Copy Constructor
	CGBase::CGBase(const CGBase& bg) {		
				
		EntType = bg.EntType;			
	}	
}