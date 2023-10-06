#ifndef CANVAS2D_H
#define CANVAS2D_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <string>
#include <cmath>

// Here's my data structure
class Canvas2D
{
     public:
        Canvas2D(); // Default - Parameterless
        Canvas2D(int rows, int cols);
        Canvas2D(int rows, int cols, int intDefaultPixel);
        Canvas2D(const Canvas2D& objOriginal);

        // Accessor member functions
        int getPixel(int row, int col) const;
        int getRows() const;
        int getCols() const;

        // Mutator member function
        void setPixel(int row, int col, int intPixel);

        // Member function for drawing the big circle
        void drawBigCircle(double dblRadius);

        // Member function for drawing the right eye
        void drawRightEye(double dblRadius);

        // Member function for drawing the left eye
        void drawLeftEye(double dblRadius);

        // Member function for drawing the nose
        void drawNose(int length);

        // Member function for drawing the mouth
        void drawMouth(int length);

        // Class constants
        static const int DEFAULT_PIXEL = 255;
        static const int DEFAULT_ROWS = 701;
        static const int DEFAULT_COLS = 701;
        static const int ERROR_MIN = -2;
        static const int ERROR_MAX = -1;
        static const int SUCCESS = 0;
        static const int MAX_LENGTH = 10000;
        static const int MAX_INTENSITY = 255;
        static const int MIN_INTENSITY = 0;

        // member function to create a PGM string
        std::string toPGM() const;

        ~Canvas2D(); // Destructor
     private:
        void checkRange(int intValue, int intMin, int intMax) const;
        int xCircle;
        int yCircle;
        int** _pixels;
        int rows;
        int cols;
};

#endif // CANVAS2D_H
