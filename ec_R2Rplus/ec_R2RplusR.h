/*

V0.5

ec_R2RplusR
Control five buttons with one analog input.

MIT License

Copyright (c) [2019 electronic-cosmos.de]

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software. if you meet the owner of electronic-cosmos.de and using his software you have to pay him a drink.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef ec_R2RplusR_h
#define ec_R2RplusR_h

#include "Arduino.h"
// Possibility 0
#define NO_KEY 0

// Possibility 1
#define DOWN_KEY 5

// Possibility 2
#define UP_KEY 4

// Possibility 3
#define UP_DOWN_KEY 45

// Possibility 4
#define RIGHT_KEY 3

// Possibility 5
#define DOWN_RIGHT_KEY 35


// Possibility 6
#define UP_RIGHT_KEY 34

// Possibility 7
#define UP_DOWN_RIGHT_KEY 345

// Possibility 8
#define LEFT_KEY 2

// Possibility 9
#define LEFT_DOWN_KEY 25

// Possibility 10
#define LEFT_UP_KEY 24

// Possibility 11
#define LEFT_UP_DOWN_KEY 234  

// Possibility 12
#define LEFT_RIGHT_KEY 23

// Possibility 13
#define LEFT_DOWN_RIGHT_KEY 245

// Possibility 14
#define LEFT_UP_RIGHT_KEY 235

// Possibility 15
#define LEFT_UP_DOWN_RIGHT_KEY 2345

// Possibility 16
#define SELECT_KEY 1

// Possibility 17
#define SELECT_DOWN_KEY 15

// Possibility 18
#define SELECT_UP_KEY 14

// Possibility 19
#define SELECT_UP_DOWN_KEY 145

// Possibility 20
#define SELECT_RIGHT_KEY 13

// Possibility 21
#define SELECT_DOWN_RIGHT_KEY 135

// Possibility 22
#define SELECT_UP_RIGHT_KEY 134

// Possibility 23
#define SELECT_UP_DOWN_RIGHT_KEY 1345

// Possibility 24
#define SELECT_LEFT_KEY 12

// Possibility 25
#define SELECT_LEFT_DOWN_KEY 125

// Possibility 26
#define SELECT_LEFT_UP_KEY 124

// Possibility 27
#define SELECT_LEFT_UP_DOWN_KEY 1245 

// Possibility 28
#define SELECT_LEFT_RIGHT_KEY 123

// Possibility 29
#define SELECT_LEFT_DOWN_RIGHT_KEY 1235

// Possibility 30
#define SELECT_LEFT_UP_RIGHT_KEY 1234

// Possibility 31
#define ALL_KEY 12345

class ec_R2RplusR
{
  public:
    ec_R2RplusR();
    int KeyGet();
    float VoltRefDivider(int, float, float);
    unsigned long KeyTime();
    int KeyCanged();
    void KeyRate(int);
    void KeyADC(int);
  private:
    int _KeyADCInput;
    unsigned long _counttime;
    unsigned long _currentMillis;
    unsigned long _previousMillis;
    int _ACount;
    int _ADCreadings;
    int _threshold;
    int _keyIn;
    unsigned long _curInput;
    int _curKey;
    int _prevInput;
    int _prevKey;
    int _actKey;
    boolean _change;
    unsigned long _oldTime;
};
#endif