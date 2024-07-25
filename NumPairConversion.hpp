#ifndef TEST_COLORCODER_HPP
#define TEST_COLORCODER_HPP

#include "colorcoder.h"

void testNumberToPair(int pairNumber,
                      TelCoColorCoder::MajorColor expectedMajor,
                      TelCoColorCoder::MinorColor expectedMinor);

void testPairToNumber(TelCoColorCoder::MajorColor major,
                      TelCoColorCoder::MinorColor minor,
                      int expectedPairNumber);

#endif // TEST_COLORCODER_HPP
