#include "CGBase.h"
#include "CGCurve.h"
#include "CGVertex.h"
#include "CGVector.h"

namespace CGBase_NS {	
									//=== CGSpline2d ===//
	class Double_V;
	class CGSpline2d : public CGBase
	{
	public:
		CGSpline2d();
		CGSpline2d(const CGSpline2d&);		  // Copy constructor
		CGSpline2d(CGCurve2d*);

		CGSpline2d(CGSpline2d&& other) noexcept;

		CGSpline2d& operator=(CGSpline2d&& other) noexcept;

		friend void swap(CGSpline2d& l, CGSpline2d& r)
		{
			using std::swap;
			swap(l.KnotVector, r.KnotVector);
			swap(l.HordaVector, r.HordaVector);
			swap(l.ControlPoints, r.ControlPoints);
			swap(l.FitPoints, r.FitPoints);
			swap(l.NormalVector, r.NormalVector);
			swap(l.StartTangent, r.StartTangent);
			swap(l.EndTangent, r.EndTangent);

			//Standart structures may not swapping
			swap(l.KnotTolerance, r.KnotTolerance);
			swap(l.ControlPointTolerance, r.ControlPointTolerance);
			swap(l.FitTolerance, r.FitTolerance);
			swap(l.degree, r.degree);
			swap(l.KnotsNum, r.KnotsNum);
			swap(l.ControlPointNum, r.ControlPointNum);
			swap(l.FitPointsNum, r.FitPointsNum);
			swap(l.SplineFlag, r.SplineFlag);
			swap(l.K, r.K);
			swap(l.rational, r.rational);
			swap(l.closed, r.closed);
			swap(l.periodic, r.periodic);
		

		}

		~CGSpline2d() {};

		//Double_V* KnotVector;		
		//Double_V* HordaVector;
		std::shared_ptr<Double_V> KnotVector;
		std::shared_ptr<Double_V> HordaVector;
		std::shared_ptr<CGVertex2d_V> ControlPoints;
		std::shared_ptr<CGVertex2d_V> FitPoints;
		//CGVertex2d_V* ControlPoints;
		//CGVertex2d_V* FitPoints;
		CGVector2d NormalVector;// Normal vector to spline2d plane
		CGVector2d StartTangent;//Tangent at start of the spline
		CGVector2d EndTangent;//Tangent at the end of the spline

		double KnotTolerance;
		double ControlPointTolerance;
		double FitTolerance;
		int degree;				// B-spline degree
		int KnotsNum;
		int ControlPointNum;
		int FitPointsNum;
		
		int SplineFlag;
		int K;	//k = degree+1	 
		int N; // number of polygon verticies
		bool rational, closed, periodic;
	
		
	};
}
