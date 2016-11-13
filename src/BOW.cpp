#include "BOW.h"
#include "ColorOrthogonalLBPDescriptor.hpp"

BOW::BOW(int sizeOfDictionary, string pathToImages, string databaseName, string mode)
{
    this->pathToImages = pathToImages;
    this->databasePath = removeLastPathSegment(this->pathToImages) + databaseName;
    this->dictionaryPath = databasePath + "_dictionary.xml";

    cout << databasePath << endl;
    cout << dictionaryPath << endl;
    //this->visualDictionary = new VisualDictionary(sizeOfDictionary, pathToImages, this->dictionaryPath);
    //this->visualDictionary = new SIFTDictionary(sizeOfDictionary, pathToImages, this->dictionaryPath);

    if(mode == "s")
    {
        this->mode = Mode::SIFT_DESCRIPTOR;
        this->visualDictionary = new SIFTDictionary(sizeOfDictionary, pathToImages, this->dictionaryPath);
    }
    else if(mode == "sl")
    {
        this->mode = Mode::SIFTandLBP_DESCRIPTOR;
        this->visualDictionary = new SIFTandLBPDictionary(sizeOfDictionary, pathToImages, this->dictionaryPath);
    }
    else if(mode == "h")
    {
        this->mode = Mode::HOG_DESCRIPTOR;
        this->visualDictionary = new HOGDictionary(sizeOfDictionary, pathToImages, this->dictionaryPath);
    }
    else if(mode == "l")
    {
        this->mode = Mode::LBP_DESCRIPTOR;
        sizeOfDictionary = 256;
        this->visualDictionary = nullptr;
    }
    else if(mode == "ol")
    {
        this->mode = ORTHOGONAL_LBP_DESCRIPTOR;
        sizeOfDictionary = 32;
        this->visualDictionary = nullptr;
    }
    else if(mode == "col")
    {
        this->mode = COLOR_ORTHOGONAL_LBP_DESCRIPTOR;
        sizeOfDictionary = 96;
        this->visualDictionary = nullptr;
    }

    this->pictureDatabase = new PictureDatabase(sizeOfDictionary);
}

BOW::~BOW()
{
    delete this->visualDictionary;
    delete this->pictureDatabase;
}


void BOW::init()
{
    if(mode != LBP_DESCRIPTOR && mode != ORTHOGONAL_LBP_DESCRIPTOR && mode != COLOR_ORTHOGONAL_LBP_DESCRIPTOR)
        this->visualDictionary->prepareDictionary();

    std::ifstream f(this->databasePath);
    if(f.good())
    {
        loadDatabase();
    }
    else
    {
        createDatabase();
    }
}

void BOW::createDatabase()
{
    this->updateDatabase(this->pathToImages);
    this->saveDatabase();
}

void BOW::saveDatabase()
{
    //std::ofstream ofs("/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/database");
    std::ofstream ofs(this->databasePath);
    boost::archive::text_oarchive oa(ofs);
    oa << this->pictureDatabase;
    cout << "Database created" << endl;
}

void BOW::loadDatabase()
{
    // create and open an archive for input
    //std::ifstream ifs("/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/database");
    std::ifstream ifs(this->databasePath);
    boost::archive::text_iarchive ia(ifs);
    // read class state from archive
    ia >> this->pictureDatabase;
    cout << "Database loaded" << endl;
}

void BOW::listDatabase()
{
    for(int i = 0; i < this->pictureDatabase->getSize(); ++i)
    {
        PictureInformation pi = this->pictureDatabase->getPicture(i);
        cout << pi.getName() << endl;
        for(int j = 0; j < this->visualDictionary->getSize(); ++j)
        {
            cout << pi.getValueAt(j) << endl;
        }
    }

    /*for(int i = 0; i < this->pictureDatabase->getSize(); ++i)
    {
        double sum = 0.0;
        PictureInformation pi = this->pictureDatabase->getPicture(i);
        for(int j = 0; j < this->visualDictionary->getSize(); ++j)
        {
            sum += pi.getValueAt(j);
        }
        cout <<"Obrazek numer " << i << "" << sum << endl;
    } */
}


void BOW::updateDatabase(string pathToDatabase)
{
    path p(pathToDatabase);
    recursive_directory_iterator dir(p), end;
    int picNum = 0;

    while (dir != end)
    {
        file_status fs = status(dir->path());

        if (!is_directory(fs))
        {
            //TODO move it inside braces
            string s = dir->path().string();
            this->addPictureToDatabase(s);
            cout << "Picture nr: " << picNum++ << endl;
        }

        ++dir;
    }
}

void BOW::addPictureToDatabase(string pathToPicture)
{
    PictureInformation pi;
    if(mode != LBP_DESCRIPTOR && mode != ORTHOGONAL_LBP_DESCRIPTOR && mode != COLOR_ORTHOGONAL_LBP_DESCRIPTOR)
        pi = this->computeHistogram(pathToPicture);
    else if(mode == LBP_DESCRIPTOR)
        //pi = this->computeLBPHistogram(pathToPicture);
        pi = LBPDescriptor::computeHistrogramForWholePicture(pathToPicture);
    else if(mode == ORTHOGONAL_LBP_DESCRIPTOR)
        //pi = this->computeOrthogonalLBPHistogram(pathToPicture);
        pi = OrthogonalLBPDescriptor::computeHistrogramForWholePicture(pathToPicture);
    else
        pi = ColorOrthogonalLBPDescriptor::computeHistrogramForWholePicture(pathToPicture);

    if(pi.getHistogramSize() != 0)
        this->pictureDatabase->addPicture(pi);
    else
        cout << pi.getName() << endl;
}


PictureInformation BOW::computeHistogram(string pathToPicture)
{
    int vectorLength = 0;
    if(mode == Mode::SIFT_DESCRIPTOR)
        vectorLength = 128;
    else if(mode == Mode::SIFTandLBP_DESCRIPTOR)
        vectorLength = 192;
    else if(mode == Mode::HOG_DESCRIPTOR)
        vectorLength = 36;

    vector<KeyPoint> keyPoints;

    Mat onlySIFT = Mat(0, 128, CV_32FC1, Scalar(0));
    Mat onlyHOG = Mat(0, 36, CV_32FC1, Scalar(0));

    cv::Mat picture = imread(pathToPicture, CV_LOAD_IMAGE_GRAYSCALE);

    if (!picture.data)
    {
        cout << "Could not open or find the image" << std::endl;
        exit(-1);
    }

    Mat features = Mat(0, vectorLength, CV_32FC1, Scalar(0));
    Mat lbpFeatures = Mat(0, 64, CV_32FC1, Scalar(0));
    if(mode == Mode::SIFT_DESCRIPTOR)
    {
        SIFTDescriptorExtractor::computeSIFTfeatures(picture, features, keyPoints);
    }
    else if(mode == Mode::SIFTandLBP_DESCRIPTOR)
    {
        SIFTDescriptorExtractor::computeSIFTfeatures(picture, onlySIFT, keyPoints);
        LBPDescriptor::computeLBPfeatures(picture, lbpFeatures, keyPoints);

        for (int i = 0; i < features.rows; ++i)
        {
            for (int j = 0; j < 192; ++j)
            {
                if(j < 128)
                {
                    features.at<float>(i, j) = onlySIFT.at<float>(i, j);
                }
                else
                {
                    features.at<float>(i, j) = lbpFeatures.at<float>(i, j % 64);
                }
            }
        }
    }
    else if(mode == HOG_DESCRIPTOR)
    {
        HOGDescriptorExtractor::computeHOGfeatures(picture, features);
    }

    PictureInformation pictureInformation(pathToPicture, this->visualDictionary->getSize());


    Mat currentRow(1, vectorLength, CV_32FC1, Scalar(0));
    Mat currentWord(1, vectorLength, CV_32FC1, Scalar(0));
    Mat difference(1, vectorLength, CV_32FC1, Scalar(0));

    std::cout << features.rows << std::endl;
    //std::cout << pathToPicture << std::endl;

    int i, j;
    for(i = 0; i < features.rows; ++i)
    {
        int minSumIndex = 0;
        float minSum = -1;
        features.row(i).copyTo(currentRow.row(0));
        for(j = 0; j < this->visualDictionary->getSize(); ++j)
        {
            float currentSum = 0;
            this->visualDictionary->getWord(j).copyTo(currentWord.row(0));
            absdiff(currentRow, currentWord, difference);

            for(int k = 0; k < vectorLength; ++k)
                currentSum += difference.at<float>(0, k);

            if(minSum == -1 || currentSum < minSum)
            {
                minSum = currentSum;
                minSumIndex = j;
            }
        }
        pictureInformation.addOneAt(minSumIndex);
    }

/*    for(int t = 0; t < 1000; ++t)
    {
        cout << pictureInformation.getValueAt(t) << " ";
    }
    cout << endl;*/

    pictureInformation.normalize(features.rows);

   /* double total = 0;
    for(int a = 0; a < this->visualDictionary->getSize(); ++a)
    {
        total += pictureInformation.getValueAt(a);
    }
    cout << "Total value: " << total << endl;

    for(int i = 0; i < this->visualDictionary->getSize(); ++i)
        cout << pictureInformation.getValueAt(i) << endl; */

    return pictureInformation;
}


PictureInformation BOW::computeLBPHistogram(string pathToPicture)
{
    int vectorLength = 64;
    vector<KeyPoint> keyPoints;

    Mat onlySIFT = Mat(0, 128, CV_32FC1, Scalar(0));
    cv::Mat picture = imread(pathToPicture, CV_LOAD_IMAGE_GRAYSCALE);

    if (!picture.data)
    {
        cout << "Could not open or find the image" << std::endl;
        exit(-1);
    }

    Mat features = Mat(0, vectorLength, CV_32FC1, Scalar(0));
    SIFTDescriptorExtractor::computeSIFTfeatures(picture, onlySIFT, keyPoints);

    if(keyPoints.size() == 0)
        return PictureInformation(pathToPicture, 0);

    LBPDescriptor::computeLBPfeatures(picture, features, keyPoints);


    PictureInformation pictureInformation(pathToPicture, 256);
    int i, j;
    for(i = 0; i < features.rows; ++i)
    {
        for(j = 0; j < features.cols; ++j)
        {
            pictureInformation.addOneAt((int)features.at<float>(i, j));
        }
    }

    pictureInformation.normalize(features.rows * features.cols);

    return pictureInformation;
}

PictureInformation BOW::computeOrthogonalLBPHistogram(string pathToPicture)
{
    int vectorLength = 128;
    vector<KeyPoint> keyPoints;

    Mat onlySIFT = Mat(0, 128, CV_32FC1, Scalar(0));
    cv::Mat picture = imread(pathToPicture, CV_LOAD_IMAGE_GRAYSCALE);

    if (!picture.data)
    {
        cout << "Could not open or find the image" << std::endl;
        exit(-1);
    }

    Mat features = Mat(0, vectorLength, CV_32FC1, Scalar(0));
    SIFTDescriptorExtractor::computeSIFTfeatures(picture, onlySIFT, keyPoints);

    if(keyPoints.size() == 0)
        return PictureInformation(pathToPicture, 0);

    OrthogonalLBPDescriptor::computeOrthogonalLBPfeatures(picture, features, keyPoints);


    PictureInformation pictureInformation(pathToPicture, 32);
    int i, j;
    for(i = 0; i < features.rows; ++i)
    {
        for(j = 0; j < features.cols; j+=2)
        {
            pictureInformation.addOneAt((int)features.at<float>(i, j));
            pictureInformation.addOneAt((int)features.at<float>(i, j) + 16);
        }
    }

    pictureInformation.normalize(features.rows * features.cols / 2);

    return pictureInformation;
}


ResultVector BOW::makeQuery(string pathToPicture, int resultNumber)
{
    PictureInformation queryPicture;
    if(mode != LBP_DESCRIPTOR && mode != ORTHOGONAL_LBP_DESCRIPTOR && mode != COLOR_ORTHOGONAL_LBP_DESCRIPTOR)
        queryPicture = this->computeHistogram(pathToPicture);
    else if(mode == LBP_DESCRIPTOR)
        //queryPicture = this->computeLBPHistogram(pathToPicture);
        queryPicture = LBPDescriptor::computeHistrogramForWholePicture(pathToPicture);
    else if(mode == ORTHOGONAL_LBP_DESCRIPTOR)
        //queryPicture = this->computeOrthogonalLBPHistogram(pathToPicture);
        queryPicture = OrthogonalLBPDescriptor::computeHistrogramForWholePicture(pathToPicture);
    else
        queryPicture = ColorOrthogonalLBPDescriptor::computeHistrogramForWholePicture(pathToPicture);

    if(queryPicture.getHistogramSize() == 0)
        return ResultVector(0, 0);

    cout << pathToPicture << endl;
    double minDistance;

    //Wybierz czy porównywać metodą zwykłą czy suma przez różnicę
    if(mode != ORTHOGONAL_LBP_DESCRIPTOR && mode != LBP_DESCRIPTOR && mode != COLOR_ORTHOGONAL_LBP_DESCRIPTOR)
        minDistance = this->comparePictureHistograms(queryPicture, this->pictureDatabase->getPicture(0));
    else
        minDistance = this->compareOrthogonalLBPHistograms(queryPicture, this->pictureDatabase->getPicture(0));

    double distance = minDistance;
    ResultVector resultVector(resultNumber, DISTANCE_MAX_VALUE);
    resultVector.tryAdd(make_pair(this->pictureDatabase->getPicture(0).getName(), distance));
    int dataaseSize = this->pictureDatabase->getSize();
    for(int i = 1; i < dataaseSize; ++i)//this->visualDictionary->getSize(); ++i)
    {
        string firstName = queryPicture.getName();
        string secondName = this->pictureDatabase->getPicture(i).getName();

        if(mode != ORTHOGONAL_LBP_DESCRIPTOR && mode != LBP_DESCRIPTOR && mode != COLOR_ORTHOGONAL_LBP_DESCRIPTOR)
            distance = this->comparePictureHistograms(queryPicture, this->pictureDatabase->getPicture(i));
        else
            distance = this->compareOrthogonalLBPHistograms(queryPicture, this->pictureDatabase->getPicture(i));

        resultVector.tryAdd(make_pair(this->pictureDatabase->getPicture(i).getName(), distance));
    }

  /*  cout << "Porównano z :" << k << endl;
    for(int i = 0; i < 200; ++i)
    {
        double sum = 0;
        for(int j = 0; j < 10000; ++j)
        {
            sum += this->pictureDatabase->getPicture(i).getValueAt(j);
        }
        cout << sum << endl;
    } */


    //this->computePrecisionAndRecall(resultVector, resultNumber);

   /* for(int i = 0; i < this->pictureDatabase->getSize(); ++i)
    {
        cout << distances[i] << endl;
    } */

    return resultVector;
}

double BOW::comparePictureHistograms(PictureInformation p1, PictureInformation p2)
{
    double distance = 0.0, sumOfMinElements = 0.0;
    int size;
    if(mode != LBP_DESCRIPTOR && mode != ORTHOGONAL_LBP_DESCRIPTOR && mode != COLOR_ORTHOGONAL_LBP_DESCRIPTOR)
        size = this->visualDictionary->getSize();
    else if(mode == LBP_DESCRIPTOR)
        size = 256;
    else if(mode == ORTHOGONAL_LBP_DESCRIPTOR)
        size = 32;
    else
        size = 96;


    for(int i = 0; i < size; ++i)
        sumOfMinElements += std::min(p1.getValueAt(i), p2.getValueAt(i));

    distance = 1 - sumOfMinElements;
    return distance;
}

double BOW::compareOrthogonalLBPHistograms(PictureInformation p1, PictureInformation p2)
{
    int size = p1.getHistogramSize();
    double sum = 0;
    for(int i = 0; i < size; ++i)
    {
        double x = p1.getValueAt(i);
        double q = p2.getValueAt(i);
        if(x + q != 0)
            sum += std::abs(x - q)/(x + q);
    }

    return sum;
}


std::pair<double, double> BOW::getPrecisionAndRecall(ResultVector vec, int numberOfAskedPictures)
{
    vector<string> splittedString = this->splitString(vec.getPairAt(0).first);
    string queryPictureCategory = splittedString[3];
    string queryPictureCategoryPath = removeLastPathSegment(vec.getPairAt(0).first);
    int imagesInCategory = countImagesInCategory(queryPictureCategoryPath);
    double numberOfSimilarPictures = 0.0;
    string currentPicCategory;

    for(int i = 1; i < numberOfAskedPictures; ++i)
    {
        splittedString = this->splitString(vec.getPairAt(i).first);
        currentPicCategory = splittedString[3];

        if(queryPictureCategory == currentPicCategory)
            ++numberOfSimilarPictures;
    }

    return std::make_pair(numberOfSimilarPictures/(numberOfAskedPictures - 1), numberOfSimilarPictures/imagesInCategory);
}



vector<string> BOW::splitString(string stringToSplit)
{
    stringstream stream(stringToSplit);
    std::string stringPart = "/";
    std::vector<std::string> splittedString;

    while(std::getline(stream, stringPart, '/'))
    {
        splittedString.push_back(stringPart);
    }
    return splittedString;
}

void BOW::testPicture(int min, int max, int step, int questionNumber)
{
    for(int i = 0; i < questionNumber; ++i)
    {
        string pathToPic;
        cout << "Podaj nazwe pliku" << endl;
        cin >> pathToPic;
        for (int current = min; current <= max; current += step)
        {
            ResultVector res = this->makeQuery(pathToPic,
                                               current);//("/home/konrad/Dokumenty/CLionProjects/BagOfWords/BazaDanych/autobus2.jpg");
            cout << "Query for: " << current << endl;
          //  cout << "Precision: " << this->getPrecision() << ", recall: " << this->getRecall() << endl;
        }
    }
}

void BOW::testDictionary()
{
/*    Mat difference(1, 128, CV_32FC1, Scalar(0));

    for(int i = 0; i < this->visualDictionary->getSize(); ++i)
    {
        for(int j = i + 1; j < this->visualDictionary->getSize(); ++j)
        {
            absdiff(this->visualDictionary->getWord(i), this->visualDictionary->getWord(j), difference);

            double sum = 0;
            int k;
            for(k = 0; k < 128; ++k)
            {
                sum += difference.at<float>(0, k);;
            }

            if(sum == 0)
                cout << sum << endl;
        }
    }*/
    this->visualDictionary->testDictionaryK();
}

string BOW::removeLastPathSegment(string path)
{
    int i = path.length() - 1;

    path.erase(i, 1);
    i--;
    char c = path[i];

    while(c != '/')
    {
        path.erase(i, 1);
        --i;
        c = path[i];
    }

    return path;
}

string BOW::getDatabasePath()
{
    return this->databasePath;
}

string BOW::getDictionaryPath()
{
    return this->dictionaryPath;
}

void BOW::compareDictionaryEntries()
{
    int size = this->visualDictionary->getSize();
    int sameNumber = 0;
    for(int i = 0; i < size - 1; ++i)
    {
        Mat word = this->visualDictionary->getWord(i);
        for(int j = i + 1; j < size; ++j)
        {
            Mat cmp = this->visualDictionary->getWord(j);

            for(int k = 0; k < 36; ++k)
            {
                if(word.at<float>(0, k) == cmp.at<float>(0, k))
                {
                    //cout << "the same" << endl;
                    sameNumber++;
                }
            }
            if(sameNumber == 36)
            {
                cout << "same word" << endl;
                for(int t = 0; t < 36; ++t)
                {
                    cout << word.at<float>(0, t) << " ";
                }
                cout << endl;
                sameNumber = 0;
            }
        }
    }
    cout << sameNumber << endl;

}

void BOW::printMatrix(Mat matrix)
{
    std::cout << matrix << std::endl;
}

int BOW::countImagesInCategory(string pathToCategoryDirectory)
{
    path p(pathToCategoryDirectory);
    directory_iterator end_iter;
    int files = 0;
    for (directory_iterator iter(pathToCategoryDirectory); iter != end_iter; ++iter)
        files++;
    return files;
}


/* Sprawdza czy istnieje już słownik - jeśli tak to go wczytuje, w przeciwnym wypadku tworzy go */
/*void BOW::prepareDictionary()
{
    std::ifstream f("../dictionary.xml");
    //std::ifstream f("../dictionaryTest.xml");
    if(f.good())
    {
        std::cout << "Loading dictionary" << std::endl;
        this->visualDictionary->loadDictionary();
    }
    else
    {
        std::cout << "Constructing and saving dictionary" << std::endl;
        this->visualDictionary->constructDictionaryRandom();
        this->visualDictionary->saveDictionary();
    }
}*/

/*
void BOW::computePrecisionAndRecall(ResultVector vec, int numberOfAskedPictures)
{
    vector<string> splittedString = this->splitString(vec.getPairAt(0).first);
    string queryPictureCategory = splittedString[3];
    double numberOfSimilarPictures = 0.0;
    string currentPicCategory;

    for(int i = 1; i < vec.getSize(); ++i)
    {
        splittedString = this->splitString(vec.getPairAt(i).first);
        currentPicCategory = splittedString[3];

        if(queryPictureCategory == currentPicCategory)
            ++numberOfSimilarPictures;
    }

    this->precision = numberOfSimilarPictures/(numberOfAskedPictures - 1);
    this->recall = numberOfSimilarPictures/100;
}*/
