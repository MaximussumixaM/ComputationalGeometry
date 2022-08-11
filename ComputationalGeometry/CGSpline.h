//#pragma once
#include "CGBase.h"
#include "CGCurve.h"
#include "CGVertex.h"
#include "CGVector.h"

namespace CGBase_NS {

	//===========================  ��� 3D ========================================
	// NURBS ������
	//============================================================================
//� �������� �, � � �������� �.��� ����������� ��������.
//��������� �� � ������ ������ pragma once, 
//�� � ��� - �� � ����� ������ ��������, ���� � CGSpline.h 
//�� ����� ����������� Double_V, ���� ��������
//(� ����������� �� ���� ��� ������ ������ ����������).
	class Double_V;
	class CGSpline : public CGBase
	{
	public:

		CGSpline();
		CGSpline(const CGSpline&);		  // ����������� �����������
		CGSpline(CGCurve2d*);
		~CGSpline() { 

			delete KnotVector;
			delete ControlPoints;
			delete FitPoints;
			delete NormalVector;
			delete StartTangent;
			delete EndTangent;

			CGUtilites::Log_Writer(CGUtilites::path_object_log, "���������� CGSpline()");
		} ;
		double KnotTolerance;
		double ControlPointTolerance;
		double FitTolerance;

		Double_V* KnotVector;		
		Double_V HordaVector;
		CGVertex2d_V* ControlPoints;
		CGVertex2d_V* FitPoints;
		CGVector2d* NormalVector;			// ������ ������� ���������, ���� ������ �������
		CGVector2d* StartTangent;
		CGVector2d* EndTangent;

		int degree;				// ������� B-�������
		int KnotsNum;
		int ControlPointNum;
		int FitPointsNum;
		
		int SplineFlag;
		int K;	// ������� �������. � ����� k = degree+1, �� Acad � ����� �� ��������		 
		int N; // ���������� ������ �������� - 1
		bool rational, closed, periodic;
		bool tangentsExist;


		void ApproxByHorda(CGCurve2d*);		// �������� �������������
	};
}
