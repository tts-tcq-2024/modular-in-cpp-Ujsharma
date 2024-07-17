#ifndef COLORCODER_H // Corrected header guard name
#define COLORCODER_H

#include <string>

namespace TelCoColorCoder {

    // Define enums for MajorColor and MinorColor
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    // Array of strings for MinorColor names
    extern const char* MinorColorNames[];
    
    // Number of MajorColors (assuming it's the count of enum values)
    const int numberOfMajorColors = 5;
    const int numberOfMinorColors = 5;

    // Class ColorPair definition
    class ColorPair {
    private:
        MajorColor majorColor;
        MinorColor minorColor;

    public:
        // Constructor
        ColorPair(MajorColor major, MinorColor minor) :
            majorColor(major), minorColor(minor) {}

        // Getter methods
        MajorColor getMajor() const { return majorColor; }
        MinorColor getMinor() const { return minorColor; }

        // Method to convert ColorPair to string
        std::string ToString();
    };

    // Function to get ColorPair from pair number
    ColorPair GetColorFromPairNumber(int pairNumber);

    // Function to get pair number from MajorColor and MinorColor
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);

    // Function prototypes for testing functions
    void testNumberToPair(int pairNumber,
                          TelCoColorCoder::MajorColor expectedMajor,
                          TelCoColorCoder::MinorColor expectedMinor);

    void testPairToNumber(TelCoColorCoder::MajorColor major,
                          TelCoColorCoder::MinorColor minor,
                          int expectedPairNumber);

} // namespace TelCoColorCoder

#endif // COLORCODER_H
