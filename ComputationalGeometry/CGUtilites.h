#ifndef CGUTILITES_H
#define CGUTILITES_H

#include <string>

//------ Точности по умолчанию ----------------------------------------------
#define EPSgeo_default 0.10                    // Точность геометрических построений
#define EPSmath_default 0.0000001              // Точность математических вычислений
#define MaxDoubleValue 99999999999.0		   // максимальное для дабла (а то Double::MaxValue не катит для разных фреймворков)
#define MinDoubleValue -99999999999.0		   // минимальное для дабла (а то Double::MinValue не катит для разных фреймворков)

extern double EPSgeo, EPSmath;

namespace CGBase_NS {

    class CGUtilites
    {
    public:
		inline static const std::string path_object_log = "C:/Users/anuro/source/repos/ComputationalGeometry/ComputationalGeometry/Objects.txt";
		
		static constexpr double EPSgeo = EPSgeo_default;      // Точность геометрических построений
        static constexpr double EPSmath = EPSmath_default;    // Точность математических вычислений	
    	
	};	
}

#endif

    