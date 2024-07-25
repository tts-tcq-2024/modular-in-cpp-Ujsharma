#ifndef COLORCODER_HPP
#define COLORCODER_HPP

#include <string>

namespace TelCoColorCoder {

    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    const int numberOfMajorColors = 5;
    const int numberOfMinorColors = 5;

    class ColorPair {
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor) : majorColor(major), minorColor(minor) {}
        MajorColor getMajor() const { return majorColor; }
        MinorColor getMinor() const { return minorColor; }
        std::string ToString() const;
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);

} // namespace TelCoColorCoder

#endif // COLORCODER_HPP
