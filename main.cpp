#include "colorcoder.h"
#include <iostream>

namespace TelCoColorCoder {

    const char* MinorColorNames[] = {
        "BLUE", "ORANGE", "GREEN", "BROWN", "SLATE"
    };
    const char* MajorColorNames[] = {
        "WHITE", "RED", "BLACK", "YELLOW", "VIOLET"
    };
    std::string ColorPair::ToString() {
        std::string colorPairStr;
        colorPairStr += MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int totalPairs = numberOfMajorColors * numberOfMinorColors;
        if (pairNumber < 1 || pairNumber > totalPairs) {
            throw std::out_of_range("Invalid pair number");
        }

        int majorIndex = (pairNumber - 1) / numberOfMinorColors;
        int minorIndex = (pairNumber - 1) % numberOfMinorColors;
        MajorColor major = static_cast<MajorColor>(majorIndex);
        MinorColor minor = static_cast<MinorColor>(minorIndex);
        return ColorPair(major, minor);}

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    void testNumberToPair(int pairNumber,
                          TelCoColorCoder::MajorColor expectedMajor,
                          TelCoColorCoder::MinorColor expectedMinor) {
        ColorPair colorPair = GetColorFromPairNumber(pairNumber);
        if (colorPair.getMajor() == expectedMajor && colorPair.getMinor() == expectedMinor) {
            std::cout << "Pass" << std::endl;
        } else {
            std::cout << "Fail" << std::endl;
        }
    }
    void testPairToNumber(TelCoColorCoder::MajorColor major,
                          TelCoColorCoder::MinorColor minor,
                          int expectedPairNumber) {
        int pairNumber = GetPairNumberFromColor(major, minor);
        if (pairNumber == expectedPairNumber) {
            std::cout << "Pass" << std::endl;
        } else {
            std::cout << "Fail" << std::endl;
        }
    }

} // namespace TelCoColorCoder
