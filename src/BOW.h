#ifndef BAGOFWORDS_BOW_H
#define BAGOFWORDS_BOW_H

#include "PictureDatabase.h"
#include "VisualDictionary.h"
#include "ResultVector.h"
#include "SIFTDictionary.h"
#include "SIFTandLBPDictionary.h"
#include "LBPDescriptor.h"
#include "HOGDescriptorExtractor.hpp"
#include "HOGDictionary.hpp"
#include "OrthogonalLBPDescriptor.hpp"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <cmath>


enum Mode {SIFT_DESCRIPTOR, SIFTandLBP_DESCRIPTOR, HOG_DESCRIPTOR, LBP_DESCRIPTOR, ORTHOGONAL_LBP_DESCRIPTOR, COLOR_ORTHOGONAL_LBP_DESCRIPTOR};
/*
 * Główna klasa tworząca interfejs korzystania z metody BOW. Umożliwia stworzenie słownika(lub wczytanie go, jeśli
 * istnieje), utworzenie bazy obrazów, wczytanie obrazów do niej, zapisanie jej w pliku, odczyt z pliku oraz
 * umożliwia tworzenie zapytań.
 */
class BOW
{
private:
    const double DISTANCE_MAX_VALUE = 270.0;
    string pathToImages;
    string databasePath;
    string dictionaryPath = "../dictionary.xml";
    VisualDictionary * visualDictionary;
    PictureDatabase * pictureDatabase;
   // double precision;
   // double recall;
    Mode mode;

    void addPictureToDatabase(string pathToPicture);
    void saveDatabase();


public:
    double comparePictureHistograms(PictureInformation p1, PictureInformation p2);
    double compareOrthogonalLBPHistograms(PictureInformation p1, PictureInformation p2);
    PictureInformation computeHistogram(string pathToPicture);
    void testDictionary();

    BOW(int sizeOfDictionary, string pathToImages, string databaseName, string mode);
    ~BOW();
    //void prepareDictionary();
    void createDatabase();
    void updateDatabase(string pathToDatabase);
    void loadDatabase();
    void listDatabase();
    ResultVector makeQuery(string pathToPicture, int resultNumber);
   // double getPrecision() {return this->precision;}
    //double getRecall() {return this->recall; }
    //void computePrecisionAndRecall(ResultVector vec, int numberOfAskedPictures);
    std::pair<double, double> getPrecisionAndRecall(ResultVector vec, int numberOfAskedPictures);
    vector<string> splitString(string s);
    void testPicture(int min, int max, int step, int questionNumber);
    void compareDictionaryEntries();
    void init();
    static void printMatrix(Mat matrix);

    string removeLastPathSegment(string path);
    string getDatabasePath();
    string getDictionaryPath();

    PictureInformation computeLBPHistogram(string pathToPicture);

    PictureInformation computeOrthogonalLBPHistogram(string pathToPicture);

    int countImagesInCategory(string pathToCategoryDirectory);
};


#endif //BAGOFWORDS_BOW_H