#ifndef BAGOFWORDS_BASICDESCRIPTOR_HPP
#define BAGOFWORDS_BASICDESCRIPTOR_HPP


#include <opencv2/opencv.hpp>
#include "PictureInformation.h"
#include "VisualDictionary.h"

using namespace std;
using namespace cv;

class BasicDescriptor
{
public:
    virtual int getHistogramSize() = 0;
    virtual int getDictionarySize() = 0;
    virtual PictureInformation computeHistogram(string pathToPicture) = 0;
};


#endif //BAGOFWORDS_BASICDESCRIPTOR_HPP
