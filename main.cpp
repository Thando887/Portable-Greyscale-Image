#include <iostream>
#include "Canvas2D.h"

using namespace std;

int main()
{
    Canvas2D objCanvas(701, 701, 255);
    double radius = (objCanvas.getCols()) / 2;
    double radius1 = (objCanvas.getCols()) / 14;
    objCanvas.drawBigCircle(radius);
    objCanvas.drawRightEye(radius1);
    objCanvas.drawLeftEye(radius1);
    objCanvas.drawNose(28);
    objCanvas.drawMouth(28);
    cout << objCanvas.toPGM() << endl;
    return Canvas2D::SUCCESS;
}
