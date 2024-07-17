#ifndef COLORCODER_H // Corrected header guard name
#define COLORCODER_H
#include <string>

namespace TelCoColorCoder {

    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};
    extern const char* MinorColorNames[];
    const int numberOfMajorColors = 5;
    const int numberOfMinorColors = 5;

    class ColorPair {
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor) :
            majorColor(major), minorColor(minor) {}
        // Getter methods
        MajorColor getMajor() const { return majorColor; }
        MinorColor getMinor() const { return minorColor; }
        // Method to convert ColorPair to string
        std::string ToString();
    };
    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void testNumberToPair(int pairNumber,
                          TelCoColorCoder::MajorColor expectedMajor,
                          TelCoColorCoder::MinorColor expectedMinor);
    void testPairToNumber(TelCoColorCoder::MajorColor major,
                          TelCoColorCoder::MinorColor minor,
                          int expectedPairNumber);
} // namespace TelCoColorCoder
#endif // COLORCODER_H
