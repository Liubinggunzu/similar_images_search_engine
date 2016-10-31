#include "HOGDescriptorExtractor.hpp"

void HOGDescriptorExtractor::computeHOGfeatures(const Mat &currentImage, Mat &features)
{
    HOGDescriptor * featureExtractor;
    vector<Point> keyPoints;
    vector<float> descriptors;

    int alignedWidth = currentImage.cols - currentImage.cols % 8;
    int alignedHeight = currentImage.rows - currentImage.rows %8;
    int blockSize = 8;
    int blockStride = 8;
    int cellSize = 4;
    int nBins = 9;

    Mat currentFeatures = Mat(1, 36, CV_32FC1, Scalar(0));

    featureExtractor = new HOGDescriptor(Size(alignedWidth, alignedHeight)
            , Size(blockSize, blockSize), Size(blockStride, blockStride), Size(cellSize, cellSize), nBins);

    featureExtractor->compute(currentImage, descriptors, Size(0, 0), Size(0, 0), keyPoints);
    //std::cout << "cols " << alignedWidth << endl;
    //std::cout << "rows " << alignedHeight << endl;
    //std::cout << descriptors.size() << endl;

    int blocksInImage = (alignedWidth / 8) * (alignedHeight / 8);
    int descNumber = 0;
    for(int i = 0; i < blocksInImage; ++i)
    {
        for(int j = 0; j < 36; ++j, descNumber++)
        {
            currentFeatures.at<float>(0, j) = descriptors[descNumber];
        }
         //Dokonkatenuj pobrane cechy
        vconcat(currentFeatures, features, features);
    }
    //cout << features.rows << " col " << features.cols << endl;

    delete featureExtractor;
}
