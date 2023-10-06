#include "Canvas2D.h"

using namespace std;

Canvas2D::Canvas2D() : Canvas2D(DEFAULT_ROWS, DEFAULT_COLS, DEFAULT_PIXEL)
{
}

Canvas2D::Canvas2D(int rows, int cols) : Canvas2D(rows, cols, DEFAULT_PIXEL)
{
}

Canvas2D::Canvas2D(int rows, int cols, int intDefaultPixel)
{
    /** Enforcing the range **/
    checkRange(rows, 0, MAX_LENGTH - 1);
    checkRange(cols, 0, MAX_LENGTH - 1);
    checkRange(intDefaultPixel, MIN_INTENSITY, MAX_INTENSITY);

    // Make sure the rows are odd by checking if the remainder is 1
    assert(rows % 2 == 1);
    // Make sure the columns are odd by checking if the remainder is 1
    assert(cols % 2 == 1);
    // Make sure the rows and columns are the same size
    assert(rows == cols);

    // Even number is basically 2k ,where k is an element of Z
    // Odd number is when 2k + 1

    /** Allocating memory **/
    this->rows = rows;
    this->cols = cols;
    _pixels = new int*[rows];
    for(int r = 0; r < rows; r++)
    {
        _pixels[r] = new int[cols];
        for(int c = 0; c < cols; c++)
        {
            _pixels[r][c] = intDefaultPixel;
        }
    }
}

Canvas2D::Canvas2D(const Canvas2D& objOriginal) : Canvas2D(objOriginal.rows, objOriginal.cols)
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            _pixels[r][c] = objOriginal._pixels[r][c];
        }
    }
}

int Canvas2D::getPixel(int row, int col) const
{
    checkRange(row, 0, rows - 1);
    checkRange(col, 0, cols - 1);
    return _pixels[row][col];
}

int Canvas2D::getRows() const
{
    return rows;
}

int Canvas2D::getCols() const
{
    return cols;
}

void Canvas2D::setPixel(int row, int col, int intPixel)
{
    checkRange(row, 0, rows - 1);
    checkRange(col, 0, cols - 1);
    _pixels[row][col] = intPixel;
}

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Canvas2D::drawBigCircle(double dblRadius)
{
    xCircle = (rows + 1) / 2;
    yCircle = (cols + 1) / 2;
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(distance(r, c, xCircle, yCircle) <= dblRadius)
            {
                _pixels[r][c] = 128;
            }
        }
    }
}

double midpoint(int x1, int x2)
{
    return (x1 + x2) / 2;
}

void Canvas2D::drawNose(int length)
{
    for(int r = xCircle - length; r < xCircle + length; r++)
    {
        for(int c = yCircle - length; c < yCircle + length; c++)
        {
            _pixels[r][c] = 0;
        }
    }
}

void Canvas2D::drawMouth(int length)
{
    int x1 = midpoint(rows - 1, xCircle);
    int y1 = midpoint(yCircle, yCircle);
    for(int r = x1 - length; r < x1 + length; r++)
    {
        for(int c = y1 - (3 * length); c < yCircle + (3 * length); c++)
        {
            _pixels[r][c] = 0;
        }
    }
}



void Canvas2D::drawLeftEye(double dblRadius)
{
    int x1 = midpoint(0, xCircle);
    int y1 = midpoint(0, yCircle);
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(distance(x1, y1, r, c) <= dblRadius)
            {
                _pixels[r][c] = 0;
            }
        }
    }
}

void Canvas2D::drawRightEye(double dblRadius)
{
    int x1 = midpoint(0, xCircle);
    int y1 = midpoint(cols - 1, yCircle);
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(distance(x1, y1, r, c) <= dblRadius)
            {
                _pixels[r][c] = 0;
            }
        }
    }
}

string Canvas2D::toPGM() const
{
    stringstream ssPGM;
    ssPGM << "P2" << endl
          << cols << ' ' << rows << endl
          << "255" << endl;
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            ssPGM << _pixels[r][c] << ' ';
        }
        ssPGM << endl;
    }
    return ssPGM.str();
}

Canvas2D::~Canvas2D()
{
    assert(_pixels != nullptr);
    for(int r = 0; r < rows; r++)
    {
        delete [] _pixels[r];
    }
    delete [] _pixels;
    _pixels = nullptr;
}

void Canvas2D::checkRange(int intValue, int intMin, int intMax) const
{
    if(intValue < intMin)
    {
        cerr << intValue << " is less than the mininum " << intMin << endl;
        exit(ERROR_MIN);
    }
    if(intValue > intMax)
    {
        cerr << intValue << " is less than the maximum " << intMax << endl;
        exit(ERROR_MAX);
    }
}
