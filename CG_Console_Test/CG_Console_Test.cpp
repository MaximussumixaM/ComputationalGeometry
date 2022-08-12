#include <iostream>

#include "CGVertex.h"
#include "CGUtilites.h"
#include "CGCurve.h"
#include "CGSpline.h"

using namespace CGBase_NS;

int main()
{
    /*CGVertex2d* v1 = new CGVertex2d(2, 4);
    CGVertex2d* v2 = new CGVertex2d(3, 5);

    CGVertex2d_V* v_v = new CGVertex2d_V();
   

    v_v->push_back(v1);

    CGCurve2d* cur = new CGCurve2d(v_v);
    cur->Add(v2);

    CGVertex2d_V* v_v2 = new CGVertex2d_V();
    for (auto i = cur->Curve.begin(); i != cur->Curve.end(); i++) {
        v_v2->push_back(*i);
    }

    delete v1;
    delete v2;
    delete v_v;
    delete v_v2;
    delete cur;*/

    CGSpline2d* spl = new CGSpline2d();
    spl->EndTangent = CGVector2d(2,3);
    CGVertex2d_V ControlPoints = CGVertex2d_V(spl->ControlPoints);
    CGVector2d EndTangent = spl->EndTangent;

    delete spl;
    //delete ControlPoints;
    //delete v_v;
    return 0;
}