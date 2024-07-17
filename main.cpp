#include "colorcoder.h"
#include <iostream>

namespace TelCoColorCoder {

    // Array of strings for MinorColor names
    const char* MinorColorNames[] = {
        "BLUE", "ORANGE", "GREEN", "BROWN", "SLATE"
    };

    // Array of strings for MajorColor names
    const char* MajorColorNames[] = {
        "WHITE", "RED", "BLACK", "YELLOW", "VIOLET"
    };

    // Function to convert ColorPair to string
    std::string ColorPair::ToString() {
        std::string colorPairStr;
        colorPairStr += MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }

    // Function to get ColorPair from pair number
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int totalPairs = numberOfMajorColors * numberOfMinorColors;
        if (pairNumber < 1 || pairNumber > totalPairs) {
            throw std::out_of_range("Invalid pair number");
        }

        int majorIndex = (pairNumber - 1) / numberOfMinorColors;
        int minorIndex = (pairNumber - 1) % numberOfMinorColors;

        MajorColor major = static_cast<MajorColor>(majorIndex);
        MinorColor minor = static_cast<MinorColor>(minorIndex);

        return ColorPair(major, minor);
    }

    // Function to get pair number from MajorColor and MinorColor
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    // Testing function: Number to ColorPair
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

    // Testing function: ColorPair to Number
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
