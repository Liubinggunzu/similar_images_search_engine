#include "BOW.hpp"

BOW::BOW(int sizeOfDictionary, string pathToImages, string databaseName, string mode)
{
    this->pathToImages = pathToImages;
    //this->databasePath = removeLastPathSegment(this->pathToImages) + databaseName;
    this->databasePath = databaseName;//removeLastPathSegment(this->pathToImages) + databaseName;
    this->dictionaryPath = databasePath + "_dictionary.xml";

    cout << databasePath << endl;
    cout << dictionaryPath << endl;

    if(mode == "sift")
    {
        descriptor = new SIFTDescriptorExtractor(sizeOfDictionary, pathToImages, dictionaryPath);
    }
    else if(mode == "siftlbp")
    {
        descriptor = new SIFTLBPDescriptorExtractor(sizeOfDictionary, pathToImages, dictionaryPath);

    }
    else if(mode == "HOG")
    {
        descriptor = new HOGDescriptorExtractor(sizeOfDictionary, pathToImages, dictionaryPath);
    }
    else if(mode == "lbp")
    {
        descriptor = new LBPDescriptor();
    }
    else if(mode == "orthogonallbp")
    {
        descriptor = new OrthogonalLBPDescriptor();
    }
    else if(mode == "colororthogonallbp")
    {
        descriptor = new ColorOrthogonalLBPDescriptor();
    }
    else if(mode == "hue")
    {
        descriptor = new HueDescriptor();
    }
    else if(mode == "siftlbpseparate")
    {
        descriptor = new SIFTandLBPSeparateDescriptorExtractor(sizeOfDictionary, pathToImages, dictionaryPath);
        comparator = new SIFTLBPSeparateComparator(descriptor->getDictionarySize(), 0.8, 0.2);
    }
    else if(mode == "siftlbphue")
    {
        descriptor = new SIFT_LBP_HUEDescriptorExtractor(sizeOfDictionary, pathToImages, dictionaryPath);
        comparator = new SIFT_LBP_HUEComparator(descriptor->getDictionarySize(), 0.4, 0.3, 0.3);
    }
    else if(mode == "siftorthogonallbp")
    {
        descriptor = new SIFT_OrthogonalLBPDescriptorExtractor(sizeOfDictionary, pathToImages, dictionaryPath);
        comparator = new SIFT_OrthogonalLBPComparator(descriptor->getDictionarySize(), 0.8, 0.2);
    }
    else if(mode == "siftorthogonallbphue")
    {
        descriptor = new SIFT_OrthogonalLBP_HUEDescriptorExtractor(sizeOfDictionary, pathToImages, dictionaryPath);
        comparator = new SIFT_OrthogonalLBP_HUEComparator(descriptor->getDictionarySize(), 0.4, 0.3, 0.3);
    }
    else if(mode == "hoglbp")
    {
        descriptor = new HOGLBPDescriptor(sizeOfDictionary, pathToImages, dictionaryPath);
        comparator = new HOGLBPComparator(descriptor->getDictionarySize(), 0.8, 0.2);
    }

    distanceMode = IntersectionOfHistograms;

    if(comparator == nullptr)
    {
        if (distanceMode == IntersectionOfHistograms)
            comparator = new IntersectionOfHistogramsComparator();
        else
            comparator = new DifferenceBySumComparator();
    }

    this->pictureDatabase = new PictureDatabase(descriptor->getHistogramSize());
}

BOW::~BOW()
{
    delete this->pictureDatabase;
    delete this->descriptor;
    delete this->comparator;
}


void BOW::init()
{
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
    std::ofstream ofs(this->databasePath);
    boost::archive::text_oarchive oa(ofs);
    oa << this->pictureDatabase;
    cout << "Database created" << endl;
}

void BOW::loadDatabase()
{
    std::ifstream ifs(this->databasePath);
    boost::archive::text_iarchive ia(ifs);
    ia >> this->pictureDatabase;
    cout << "Database loaded" << endl;
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
    PictureInformation pi = descriptor->computeHistogram(pathToPicture);

    if(pi.getHistogramSize() != 0)
        this->pictureDatabase->addPicture(pi);
    else
        cout << pi.getName() << endl;
}


ResultVector BOW::makeQuery(string pathToPicture, int resultNumber)
{
    PictureInformation queryPicture = descriptor->computeHistogram(pathToPicture);
    if(queryPicture.getHistogramSize() == 0)
        return ResultVector(0, 0);

    cout << pathToPicture << endl;
    double minDistance;

    minDistance = this->comparator->compare(queryPicture, this->pictureDatabase->getPicture(0));

    double distance = minDistance;
    ResultVector resultVector(resultNumber, DISTANCE_MAX_VALUE);
    resultVector.tryAdd(make_pair(this->pictureDatabase->getPicture(0).getName(), distance));
    int databaseSize = this->pictureDatabase->getSize();
    for(int i = 1; i < databaseSize; ++i)
    {
        string firstName = queryPicture.getName();
        string secondName = this->pictureDatabase->getPicture(i).getName();

        distance = this->comparator->compare(queryPicture, this->pictureDatabase->getPicture(i));


        resultVector.tryAdd(make_pair(this->pictureDatabase->getPicture(i).getName(), distance));
    }

    return resultVector;
}

/*double BOW::comparePictureHistograms(PictureInformation p1, PictureInformation p2)
{
    double distance = 0.0, sumOfMinElements = 0.0;
    int size = p1.getHistogramSize();

    for(int i = 0; i < size; ++i)
        sumOfMinElements += std::min(p1.getValueAt(i), p2.getValueAt(i));

    distance = 1 - sumOfMinElements;
    return distance;
}

double BOW::compareDifferenceBySum(PictureInformation p1, PictureInformation p2)
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
}*/


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

string BOW::getLastTwoPathSegments(string path)
{
    {
        bool firstSlash = false;
        int beginIndex = -1;

        for(int i = path.length() - 1; i >= 0; --i)
        {
            if(path.at(i) == '/')
            {
                if(!firstSlash)
                    firstSlash = true;
                else
                {
                    beginIndex = i;
                    break;
                }
            }
        }

        return path.substr(beginIndex + 1, path.length() - beginIndex);
    }
}
