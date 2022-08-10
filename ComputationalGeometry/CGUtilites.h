#ifndef CGUTILITES_H
#define CGUTILITES_H

#include <string>
#include "Containers.h"

using namespace Containers_NS;

							  //=== Default accuracies ===//
#define EPSgeo_default 0.10                    // geometry accuracy
#define EPSmath_default 0.0000001              // math accuracy
#define MaxDoubleValue 99999999999.0		   // Double::MaxValue
#define MinDoubleValue -99999999999.0		   // Double::MinValue

extern double EPSgeo, EPSmath;

namespace CGBase_NS {

								// === CGUtilites === //
    class CGUtilites
    {
    public:				
		static constexpr double EPSgeo = EPSgeo_default;      // “очность геометрических построений
        static constexpr double EPSmath = EPSmath_default;    // “очность математических вычислений	
    };	

								// === Double_V === //			
	// Double List - for future math structures
	class Double_V : public CGList<double> {
	public:

		Double_V() {};

		Double_V(Double_V* vv) {	// copy constructor
			if (vv == nullptr || vv->size() == 0)
				return;

			for (auto i = vv->begin(); i != vv->end(); i++) {
				this->push_back(*i);
			}
		};
		~Double_V() {};
	};
}

#endif//CGUTILITES_H

    