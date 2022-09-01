#include "pch.h"
#include "CGSpline.h"


namespace CGBase_NS {

								// === Constructors === //
	CGSpline2d::CGSpline2d() {

		NormalVector = CGVector2d(0.0, 0.0);			// Вектор направления
		StartTangent = CGVector2d();
		EndTangent	= CGVector2d();

		//this->KnotVector->clear();
		//KnotVector = new Double_V();
		KnotVector = std::make_unique<Double_V>();
		ControlPoints = std::make_unique<CGVertex2d_V>();
		FitPoints = std::make_unique<CGVertex2d_V>();
		//ControlPoints = new CGVertex2d_V();
		//FitPoints = new CGVertex2d_V();
		degree = 3;		// default
		EntType = EntityType::SPLINE2D;
		KnotTolerance = ControlPointTolerance = 0.0;
		FitTolerance = 0.001;		
	}
	
	//=====================================================================
	CGSpline2d::CGSpline2d(const CGSpline2d& spl) : CGBase((const CGBase&)spl) {		  // Конструктор копирования
	
		//this->KnotVector->clear();
		//KnotVector = new Double_V();
		KnotVector = std::make_unique<Double_V>();
		ControlPoints = std::make_unique<CGVertex2d_V>();
		FitPoints = std::make_unique<CGVertex2d_V>();
		//ControlPoints = new CGVertex2d_V();
		//FitPoints = new CGVertex2d_V();
		this->HordaVector->clear();
	
		for (auto i = spl.ControlPoints->begin(); i != spl.ControlPoints->end(); i++) {
			
			//this->ControlPoints->push_back(*i);
		}
		for (auto i = spl.FitPoints->begin(); i != spl.FitPoints->end(); i++) {
			
			//this->FitPoints->push_back(*i);
		}
		for (auto i = spl.KnotVector->begin(); i != spl.KnotVector->end(); i++) {
			
			this->KnotVector->push_back(*i);
		}		
		
		
		this->KnotTolerance = spl.KnotTolerance;
		this->ControlPointTolerance = spl.ControlPointTolerance;
		this->FitTolerance = spl.FitTolerance;
		this->degree = spl.degree;
		this->KnotsNum = spl.KnotsNum;
		this->ControlPointNum = spl.ControlPointNum;
		this->FitPointsNum = spl.FitPointsNum;
		this->NormalVector = spl.NormalVector;
		//if (spl.StartTangent != nullptr) {
			//this->StartTangent = new CGVector2d;
			//this->StartTangent = spl.StartTangent;
		//}
		//if (spl.EndTangent != nullptr) {
			//this->EndTangent = new CGVector2d;
			//this->EndTangent = spl.EndTangent;
		//}
		this->SplineFlag = spl.SplineFlag;
		this->closed = spl.closed;
		this->rational = spl.rational;	
		this->periodic = spl.periodic;
		//this->HordaVector.AddRange(% spl->HordaVector);
		this->K = spl.K;
		this->N = spl.N;
		
		EntType = EntityType::SPLINE2D;

	}


	
}