//#pragma once
#include "CGBase.h"
#include "CGCurve.h"
#include "CGVertex.h"
#include "CGVector.h"

namespace CGBase_NS {

	//===========================  Для 3D ========================================
	// NURBS Сплайн
	//============================================================================
//А включает Б, а Б включает А.Это бесконечная рекурсия.
//Разрывает ее в данном случае pragma once, 
//но в что - то в любом случае страдает, либо в CGSpline.h 
//не видно содержимого Double_V, либо наоборот
//(в зависимости от того что вперед успело включиться).
	class Double_V;
	class CGSpline : public CGBase
	{
	public:

		CGSpline();
		CGSpline(const CGSpline&);		  // Конструктор копирования
		CGSpline(CGCurve2d*);
		~CGSpline() { 

			delete KnotVector;
			delete ControlPoints;
			delete FitPoints;
			delete NormalVector;
			delete StartTangent;
			delete EndTangent;

			CGUtilites::Log_Writer(CGUtilites::path_object_log, "Деструктор CGSpline()");
		} ;
		double KnotTolerance;
		double ControlPointTolerance;
		double FitTolerance;

		Double_V* KnotVector;		
		Double_V HordaVector;
		CGVertex2d_V* ControlPoints;
		CGVertex2d_V* FitPoints;
		CGVector2d* NormalVector;			// Вектор нормали плоскости, если сплайн плоский
		CGVector2d* StartTangent;
		CGVector2d* EndTangent;

		int degree;				// степень B-сплайна
		int KnotsNum;
		int ControlPointNum;
		int FitPointsNum;
		
		int SplineFlag;
		int K;	// порядок сплайна. В книге k = degree+1, но Acad с этоим не согласен		 
		int N; // количество вершин полигона - 1
		bool rational, closed, periodic;
		bool tangentsExist;


		void ApproxByHorda(CGCurve2d*);		// хордовая аппроксимация
	};
}
