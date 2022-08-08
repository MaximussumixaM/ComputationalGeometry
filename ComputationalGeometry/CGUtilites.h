#ifndef CGUTILITES_H
#define CGUTILITES_H

#include <string>

//------ �������� �� ��������� ----------------------------------------------
#define EPSgeo_default 0.10                    // �������� �������������� ����������
#define EPSmath_default 0.0000001              // �������� �������������� ����������
#define MaxDoubleValue 99999999999.0		   // ������������ ��� ����� (� �� Double::MaxValue �� ����� ��� ������ �����������)
#define MinDoubleValue -99999999999.0		   // ����������� ��� ����� (� �� Double::MinValue �� ����� ��� ������ �����������)

extern double EPSgeo, EPSmath;

namespace CGBase_NS {

    class CGUtilites
    {
    public:
		inline static const std::string path_object_log = "C:/Users/anuro/source/repos/ComputationalGeometry/ComputationalGeometry/Objects.txt";
		
		static constexpr double EPSgeo = EPSgeo_default;      // �������� �������������� ����������
        static constexpr double EPSmath = EPSmath_default;    // �������� �������������� ����������	
    	
	};	
}

#endif

    