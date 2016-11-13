#include <iostream>
#include "OrthogonalLBPDescriptor.hpp"

void OrthogonalLBPDescriptor::computeOrthogonalLBPfeatures(const Mat & image, Mat & lbpFeatures, const vector<KeyPoint> & keyPoints)
{
    for(KeyPoint p : keyPoints)
    {
        Mat dest;
        getRectSubPix(image, Size(10, 10), Point2f(p.pt.x, p.pt.y), dest);

        int flatNumber = 0;
        Mat currentFeatures = Mat(1, 128, CV_32FC1, Scalar(0));
        for(int r = 1; r < 9; ++r)
        {
            for (int c = 1; c < 9; ++c)
            {
                Scalar intensity = dest.at<uchar>(r, c);
                uchar mid = intensity.val[0];

                unsigned char numberOne = 0;
                unsigned char numberTwo = 0;

                //right middle
                intensity = dest.at<uchar>(r, c + 1);
                if(intensity.val[0] > mid)
                {
                    numberOne |= 1;
                }

                //bottom middle
                intensity = dest.at<uchar>(r + 1, c);
                if(intensity.val[0] > mid)
                {
                    numberOne |= 1 << 1;
                }

                //left middle
                intensity = dest.at<uchar>(r, c - 1);
                if(intensity.val[0] > mid)
                {
                    numberOne |= 1 << 2;
                }

                //right middle
                intensity = dest.at<uchar>(r - 1, c);
                if(intensity.val[0] > mid)
                {
                    numberOne |= 1 << 3;
                }

                //rigth bottom
                intensity = dest.at<uchar>(r + 1, c + 1);
                if(intensity.val[0] > mid)
                {
                    numberTwo |= 1;
                }


                //left bottom
                intensity = dest.at<uchar>(r + 1, c - 1);
                if(intensity.val[0] > mid)
                {
                    numberTwo |= 1 << 1;
                }


                //left top
                intensity = dest.at<uchar>(r - 1, c - 1);
                if(intensity.val[0] > mid)
                {
                    numberTwo |= 1 << 2;
                }


                //right top
                intensity = dest.at<uchar>(r - 1, c + 1);
                if(intensity.val[0] > mid)
                {
                    numberTwo |= 1 << 3;
                }


                currentFeatures.at<float>(0, flatNumber) = numberOne;
                flatNumber++;
                currentFeatures.at<float>(0, flatNumber) = numberTwo;
                flatNumber++;
            }
        }
        vconcat(currentFeatures, lbpFeatures, lbpFeatures);
    }
}

PictureInformation OrthogonalLBPDescriptor::computeHistrogramForWholePicture(string pathToPicture)
{
    int values = 0;

    cv::Mat image = imread(pathToPicture, CV_LOAD_IMAGE_GRAYSCALE);

    if (!image.data)
    {
        cout << "Could not open or find the image" << std::endl;
        exit(-1);
    }

    PictureInformation pictureInformation(pathToPicture, 32);
    for(int r = 1; r < image.rows - 1; ++r) //omit first and last row
    {
        for(int c = 1; c < image.cols - 1; ++c) //omit first and last column
        {
            Scalar intensity = image.at<uchar>(r, c);
            uchar mid = intensity.val[0];

            unsigned char numberOne = 0;
            unsigned char numberTwo = 0;

            //right middle
            intensity = image.at<uchar>(r, c + 1);
            if(intensity.val[0] > mid)
            {
                numberOne |= 1;
            }

            //bottom middle
            intensity = image.at<uchar>(r + 1, c);
            if(intensity.val[0] > mid)
            {
                numberOne |= 1 << 1;
            }

            //left middle
            intensity = image.at<uchar>(r, c - 1);
            if(intensity.val[0] > mid)
            {
                numberOne |= 1 << 2;
            }

            //right middle
            intensity = image.at<uchar>(r - 1, c);
            if(intensity.val[0] > mid)
            {
                numberOne |= 1 << 3;
            }

            //rigth bottom
            intensity = image.at<uchar>(r + 1, c + 1);
            if(intensity.val[0] > mid)
            {
                numberTwo |= 1;
            }


            //left bottom
            intensity = image.at<uchar>(r + 1, c - 1);
            if(intensity.val[0] > mid)
            {
                numberTwo |= 1 << 1;
            }


            //left top
            intensity = image.at<uchar>(r - 1, c - 1);
            if(intensity.val[0] > mid)
            {
                numberTwo |= 1 << 2;
            }


            //right top
            intensity = image.at<uchar>(r - 1, c + 1);
            if(intensity.val[0] > mid)
            {
                numberTwo |= 1 << 3;
            }

            values+=2;
            pictureInformation.addOneAt(numberOne);
            pictureInformation.addOneAt(numberTwo + 16);
        }
    }

    pictureInformation.normalize(values);
    return pictureInformation;
}
