#include "gmock/gmock.h"
#include "Soundex.cpp"
TEST(SoundexEncoding, test1) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");
}

