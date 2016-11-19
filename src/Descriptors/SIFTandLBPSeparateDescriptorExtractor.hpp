#ifndef BAGOFWORDS_SIFTANDLBPSEPARATEDESCRIPTOREXTRACTOR_HPP
#define BAGOFWORDS_SIFTANDLBPSEPARATEDESCRIPTOREXTRACTOR_HPP

#include "BasicDescriptor.hpp"
#include "../Dictionaries/VisualDictionary.hpp"
#include "../Dictionaries/SIFTDictionary.hpp"
#include "LBPDescriptor.hpp"

class SIFTandLBPSeparateDescriptorExtractor : public BasicDescriptor
{
private:
    const int LBP_HISTOGRAM_SIZE = 256;
    SIFTDescriptorExtractor * siftDescriptorExtractor;

public:
    virtual int getHistogramSize() override;
    virtual int getDictionarySize() override;

    SIFTandLBPSeparateDescriptorExtractor(int dictionarySize, string pathToDatabase, string pathToDictionary);
    ~SIFTandLBPSeparateDescriptorExtractor();

    virtual PictureInformation computeHistogram(string pathToPicture) override;
};


#endif //BAGOFWORDS_SIFTANDLBPSEPARATEDESCRIPTOREXTRACTOR_HPP
