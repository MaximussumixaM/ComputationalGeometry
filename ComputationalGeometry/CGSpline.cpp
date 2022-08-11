#include "pch.h"
#include "CGSpline.h"


namespace CGBase_NS {

	//=====================================================================
	// Конструктор по умолчанию
	CGSpline::CGSpline() {


		NormalVector = new CGVector2d(0.0, 0.0);			// Вектор направления
		//StartTangent	= gcnew GeoVector3d();
		//EndTangent		= gcnew GeoVector3d();

		//this->KnotVector->clear();
		KnotVector = new Double_V();
		ControlPoints = new CGVertex2d_V();
		FitPoints = new CGVertex2d_V();
		degree = 3;		// по умолчанию
		EntType = EntityType::SPLINE2D;
		KnotTolerance = ControlPointTolerance = 0.0;
		FitTolerance = 0.001;

		CGUtilites::Log_Writer(CGUtilites::path_object_log, "Конструктор CGSpline()");
		
	}
	
	//=====================================================================
	CGSpline::CGSpline(const CGSpline& spl) : CGBase((const CGBase&)spl) {		  // Конструктор копирования
	
		//this->KnotVector->clear();
		KnotVector = new Double_V();
		ControlPoints = new CGVertex2d_V();
		FitPoints = new CGVertex2d_V();
		this->HordaVector.clear();
	
		for (auto i = spl.ControlPoints->begin(); i != spl.ControlPoints->end(); i++) {
			//CGVertex2d p(*i);
			//this->ControlPoints->push_back(& p);
			this->ControlPoints->push_back(*i);
		}
		for (auto i = spl.FitPoints->begin(); i != spl.FitPoints->end(); i++) {
			//CGVertex2d p(*i);
			//this->FitPoints->push_back(&p);
			this->FitPoints->push_back(*i);
		}
		for (auto i = spl.KnotVector->begin(); i != spl.KnotVector->end(); i++) {
			//double p(*i);
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
		if (spl.StartTangent != nullptr) {
			this->StartTangent = new CGVector2d;
			this->StartTangent = spl.StartTangent;
		}
		if (spl.EndTangent != nullptr) {
			this->EndTangent = new CGVector2d;
			this->EndTangent = spl.EndTangent;
		}
		this->SplineFlag = spl.SplineFlag;
		this->closed = spl.closed;
		this->rational = spl.rational;
		this->tangentsExist = spl.tangentsExist;
		this->periodic = spl.periodic;
		//this->HordaVector.AddRange(% spl->HordaVector);
		this->K = spl.K;
		this->N = spl.N;
		
		EntType = EntityType::SPLINE2D;

		CGUtilites::Log_Writer(CGUtilites::path_object_log, "Конструктор CGSpline(CGSpline* spl)");
		
	}
	//=====================================================================
	CGSpline::CGSpline(CGCurve2d* cur) {
	
		//CGSpline* spl = new CGSpline();
		//spl->InterpolateThroughPoints(cur);
		//spl->MatchProperties(cur);
		//*this = spl;

		CGUtilites::Log_Writer(CGUtilites::path_object_log, "Конструктор CGSpline(CGCurve2d* cur)");
		
	}

	//=====================================================================
// неравномерная хордовая аппроксимация как в акаде (только нормализованная)
	void
		CGSpline::ApproxByHorda(CGCurve2d* horda_cur) {
	
		if (horda_cur->Size() < 4) return;
		HordaVector.clear();
	
	
		double S_curr = 0.0;	// текущая сумма
		KnotVector->clear();
		int k = this->K;
		int n = horda_cur->Size() - 1;
		HordaVector.push_back(0.0);
		// текущие длины хорд
		//for (int i = 1; i < horda_cur->Size(); i++) {
			
			//double dist = CGUtilites::Distance(horda_cur->GetVertex(i), horda_cur->GetVertex(i - 1));
			//HordaVector->push_back(HordaVector->at(i - 1) + dist);
		//}
		for (auto i = horda_cur->Curve.begin() + 1; i != horda_cur->Curve.end(); i++) {
			
			int index = distance(horda_cur->Curve.begin(), i);
			//double dist = CGUtilites::Distance(horda_cur->GetVertex(index), horda_cur->GetVertex(index - 1));
			double dist = horda_cur->GetVertex(index)->Distance(horda_cur->GetVertex(index - 1));
			HordaVector.push_back(HordaVector.at(index - 1) + dist);
		}
		// Узловой вектор
		auto test = HordaVector[0];//
		auto test2 = *HordaVector.begin();//
		for (int i = 0; i < k; i++)	KnotVector->push_back(HordaVector.at(0));
		for (int i = 1; i < n; i++)	KnotVector->push_back(HordaVector.at(i));
		for (int i = 0; i < k; i++)	KnotVector->push_back(HordaVector.at(HordaVector.at(HordaVector.size() - 1)));
	
		this->KnotsNum = KnotVector->size();
	}
}