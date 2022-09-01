#include <iostream>

//#include "CGVertex.h"
#include "CGUtilites.h"
#include "CGCurve.h"
#include "CGSpline.h"
#include <memory>
#include <vector>

using namespace std;
using namespace CGBase_NS;

int main()
{
                                //===Double_V Test===//
    std::vector<double> vec;
    vec.push_back(5.0);
    double test_num_vec = vec[0];


    Double_V matrix = Double_V();

    Double_V* matrix_new = new Double_V();

    matrix_new->push_back(5.9);
    matrix.push_back(5.9);

    double test_num = matrix[0];

    double test_num_new = (*matrix_new)[0];

    matrix.clear();

    delete matrix_new;



                                //===Other Test===//
    CGVertex2d* v1 = new CGVertex2d(2, 4);
    CGVertex2d* v2 = new CGVertex2d(3, 5);

    CGVertex2d_V* v_v = new CGVertex2d_V();
   

    v_v->push_back(*v1);
    CGCurve2d* cur = new CGCurve2d();
    CGCurve2d* cur1 = new CGCurve2d(v_v);
    cur->Add(*v2);

    CGVertex2d_V* v_v2 = new CGVertex2d_V();
    for (auto i = cur->Curve->begin(); i != cur->Curve->end(); i++) {
        v_v2->push_back(*i);
    }
    //CGCurve2d* cur2 = new CGCurve2d(*cur);
    CGCurve2d cur5 = CGCurve2d(v_v);
    CGCurve2d cur2 = std::move(cur5);
   // CGVertex2d_V* v_v4 = new CGVertex2d_V(*cur2->Curve);
    CGVertex2d_V* v_v3 = new CGVertex2d_V(*cur->Curve);


    delete v1;
    delete v2;
    delete v_v;
    delete v_v2;
    delete v_v3;
    //delete v_v4;
    delete cur;
    delete cur1;

 
   
    /*CGSpline2d* spl = new CGSpline2d();
    spl->EndTangent = CGVector2d(2,3);
    CGVertex2d_V ControlPoints = CGVertex2d_V(*spl->ControlPoints);
    CGVector2d EndTangent = spl->EndTangent;

    auto spl_p = std::make_unique<CGSpline2d>();    
   
    spl_p->EndTangent = CGVector2d(2, 3);
    CGVertex2d_V ControlPoints2 = CGVertex2d_V(*spl_p->ControlPoints);
    CGVector2d EndTangent2 = spl_p->EndTangent;

   // spl1->
    //spl1->EndTangent = CGVector2d(2, 3);
   // CGVertex2d_V ControlPoints = CGVertex2d_V(spl1->ControlPoints);
   // CGVector2d EndTangent = spl1->EndTangent;

    delete spl;
    //delete ControlPoints;
    //delete v_v;*/
    return 0;
}