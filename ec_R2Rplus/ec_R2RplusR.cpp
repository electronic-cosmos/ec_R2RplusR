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

#include "Arduino.h"
#include "ec_R2RplusR.h"

// modificated by mjf
static int DEFAULT_THRESHOLD = 5;      // default 4
static int DEFAULT_ADCreadings = 250;  // default 250
static int DEFAULT_KeyADCInput = 0;    // default 0

 //that's read "analogue read value"
// Possibility 31
static int ALLKEY_R2R                   = 515;

// Possibility 30
static int SELECT_LEFT_UP_RIGHTKEY_R2R  = 524;

// Possibility 29
static int SELECT_LEFT_DOWN_RIGHTKEY_R2R= 539;

// Possibility 28
static int SELECT_LEFT_RIGHTKEY_R2R     = 549;

// Possibility 27
static int SELECT_LEFT_UP_DOWNKEY_R2R   = 566;

// Possibility 26
static int SELECT_LEFT_UPKEY_R2R        = 576;

// Possibility 25
static int SELECT_LEFT_DOWNKEY_R2R      = 592;

// Possibility 24
static int SELECT_LEFTKEY_R2R           = 605;

// Possibility 23
static int SELECT_UP_DOWN_RIGHTKEY_R2R  = 621;

// Possibility 22
static int SELECT_UP_RIGHTKEY_R2R       = 632;

// Possibility 21
static int SELECT_DOWN_RIGHTKEY_R2R     = 648;

// Possibility 20
static int SELECT_RIGHTKEY_R2R          = 660;

// Possibility 19
static int SELECT_UP_DOWNKEY_R2R        = 681;

// Possibility 18
static int SELECT_UPKEY_R2R             = 692;

// Possibility 17
static int SELECT_DOWNKEY_R2R           = 712;

// Possibility 16
static int SELECTKEY_R2R                = 727;

// Possibility 15
static int LEFT_UP_DOWN_RIGHTKEY_R2R    = 745;

// Possibility 14
static int LEFT_UP_RIGHTKEY_R2R         = 754;

// Possibility 13
static int LEFT_DOWN_RIGHTKEY_R2R       = 769;

// Possibility 12
static int LEFT_RIGHTKEY_R2R            = 782;

// Possibility 11
static int LEFT_UP_DOWNKEY_R2R          = 800;

// Possibility 10
static int LEFT_UPKEY_R2R               = 812;

// Possibility 9
static int LEFT_DOWNKEY_R2R             = 831;

// Possibility 8
static int LEFTKEY_R2R                  = 844;

// Possibility 7
static int UP_DOWN_RIGHTKEY_R2R         = 865;

// Possibility 6
static int UP_RIGHTKEY_R2R              = 876;

// Possibility 5
static int DOWN_RIGHTKEY_R2R            = 895;

// Possibility 4
static int RIGHTKEY_R2R                 = 908;

// Possibility 3
static int UP_DOWNKEY_R2R               = 931;

// Possibility 2
static int UPKEY_R2R                    = 944;

// Possibility 1
static int DOWNKEY_R2R                  = 968;

// Possibility 0
static int NOKEY_R2R                    = 983;

ec_R2RplusR::ec_R2RplusR(){	
  _ADCreadings = DEFAULT_ADCreadings;
  _KeyADCInput = DEFAULT_KeyADCInput;
  _threshold = DEFAULT_THRESHOLD;
  _keyIn = NO_KEY;
  _curInput = NO_KEY;
  _curKey = NO_KEY;
  _prevInput = NO_KEY;
  _prevKey = NO_KEY;
  _oldTime = 0;
}

int ec_R2RplusR::KeyGet(){
    //analogReference(INTERNAL);
	analogReference(DEFAULT);
    _currentMillis = millis();
    _prevInput = _curInput;
    analogRead(_KeyADCInput);    // for waste
    _curInput = 0; 
    for (int i=0; i <= _ADCreadings; i++){
    _curInput += analogRead(_KeyADCInput);
    _ACount=i;
   } 
   _curInput=_curInput/(_ACount+1);
   
    if (_curInput > _prevInput - _threshold && _curInput < _prevInput + _threshold ) 
    {
      _change = false;
      _curKey = _prevKey;
    }
    else
    {
      _change = true;
      _prevKey = _curKey;
     //if (_curInput > NOKEY_R2R - _threshold && _curInput < NOKEY_R2R + _threshold ) _curKey = NO_KEY;
     if (_curInput > NOKEY_R2R - _threshold ) _curKey = NO_KEY;
        else if (_curInput > DOWNKEY_R2R - _threshold && _curInput < DOWNKEY_R2R + _threshold ) _curKey = DOWN_KEY;
        else if (_curInput > UPKEY_R2R - _threshold && _curInput < UPKEY_R2R + _threshold ) _curKey = UP_KEY;
        else if (_curInput > UP_DOWNKEY_R2R - _threshold && _curInput < UP_DOWNKEY_R2R + _threshold ) _curKey = UP_DOWN_KEY;
        else if (_curInput > RIGHTKEY_R2R - _threshold && _curInput < RIGHTKEY_R2R + _threshold ) _curKey = RIGHT_KEY;  
        else if (_curInput > DOWN_RIGHTKEY_R2R - _threshold && _curInput < DOWN_RIGHTKEY_R2R + _threshold ) _curKey = DOWN_RIGHT_KEY;  
        else if (_curInput > UP_RIGHTKEY_R2R - _threshold && _curInput < UP_RIGHTKEY_R2R + _threshold ) _curKey = UP_RIGHT_KEY;
        else if (_curInput > UP_DOWN_RIGHTKEY_R2R - _threshold && _curInput < UP_DOWN_RIGHTKEY_R2R + _threshold ) _curKey = UP_DOWN_RIGHT_KEY;
        else if (_curInput > LEFTKEY_R2R - _threshold && _curInput < LEFTKEY_R2R + _threshold ) _curKey = LEFT_KEY;
        else if (_curInput > LEFT_DOWNKEY_R2R - _threshold && _curInput < LEFT_DOWNKEY_R2R + _threshold ) _curKey = LEFT_DOWN_KEY;
        else if (_curInput > LEFT_UPKEY_R2R - _threshold && _curInput < LEFT_UPKEY_R2R + _threshold ) _curKey = LEFT_UP_KEY;       
        else if (_curInput > LEFT_UP_DOWNKEY_R2R - _threshold && _curInput < LEFT_UP_DOWNKEY_R2R + _threshold ) _curKey = LEFT_UP_DOWN_KEY;
        else if (_curInput > LEFT_RIGHTKEY_R2R - _threshold && _curInput < LEFT_RIGHTKEY_R2R + _threshold ) _curKey = LEFT_RIGHT_KEY;
        else if (_curInput > LEFT_DOWN_RIGHTKEY_R2R - _threshold && _curInput < LEFT_DOWN_RIGHTKEY_R2R + _threshold ) _curKey = LEFT_DOWN_RIGHT_KEY;
        else if (_curInput > LEFT_UP_RIGHTKEY_R2R - _threshold && _curInput < LEFT_UP_RIGHTKEY_R2R + _threshold ) _curKey = LEFT_UP_RIGHT_KEY;
        else if (_curInput > LEFT_UP_DOWN_RIGHTKEY_R2R - _threshold && _curInput < LEFT_UP_DOWN_RIGHTKEY_R2R + _threshold ) _curKey = LEFT_UP_DOWN_RIGHT_KEY;
        else if (_curInput > SELECTKEY_R2R - _threshold && _curInput < SELECTKEY_R2R + _threshold ) _curKey = SELECT_KEY;
        else if (_curInput > SELECT_DOWNKEY_R2R - _threshold && _curInput < SELECT_DOWNKEY_R2R + _threshold ) _curKey = SELECT_DOWN_KEY;
        else if (_curInput > SELECT_UPKEY_R2R - _threshold && _curInput < SELECT_UPKEY_R2R + _threshold ) _curKey = SELECT_UP_KEY;
        else if (_curInput > SELECT_UP_DOWNKEY_R2R - _threshold && _curInput < SELECT_UP_DOWNKEY_R2R + _threshold ) _curKey = SELECT_UP_DOWN_KEY;
        else if (_curInput > SELECT_RIGHTKEY_R2R - _threshold && _curInput < SELECT_RIGHTKEY_R2R + _threshold ) _curKey = SELECT_RIGHT_KEY;
        else if (_curInput > SELECT_DOWN_RIGHTKEY_R2R - _threshold && _curInput < SELECT_DOWN_RIGHTKEY_R2R + _threshold ) _curKey = SELECT_DOWN_RIGHT_KEY;
        else if (_curInput > SELECT_UP_RIGHTKEY_R2R - _threshold && _curInput < SELECT_UP_RIGHTKEY_R2R + _threshold ) _curKey = SELECT_UP_RIGHT_KEY;
        else if (_curInput > SELECT_UP_DOWN_RIGHTKEY_R2R - _threshold && _curInput < SELECT_UP_DOWN_RIGHTKEY_R2R + _threshold ) _curKey = SELECT_UP_DOWN_RIGHT_KEY;
        else if (_curInput > SELECT_LEFTKEY_R2R - _threshold && _curInput < SELECT_LEFTKEY_R2R + _threshold ) _curKey = SELECT_LEFT_KEY;
        else if (_curInput > SELECT_LEFT_DOWNKEY_R2R - _threshold && _curInput < SELECT_LEFT_DOWNKEY_R2R + _threshold ) _curKey = SELECT_LEFT_DOWN_KEY;
        else if (_curInput > SELECT_LEFT_UPKEY_R2R - _threshold && _curInput < SELECT_LEFT_UPKEY_R2R + _threshold ) _curKey = SELECT_LEFT_UP_KEY;
        else if (_curInput > SELECT_LEFT_UP_DOWNKEY_R2R - _threshold && _curInput < SELECT_LEFT_UP_DOWNKEY_R2R + _threshold ) _curKey = SELECT_LEFT_UP_DOWN_KEY;
        else if (_curInput > SELECT_LEFT_RIGHTKEY_R2R - _threshold && _curInput < SELECT_LEFT_RIGHTKEY_R2R + _threshold ) _curKey = SELECT_LEFT_RIGHT_KEY;
        else if (_curInput > SELECT_LEFT_DOWN_RIGHTKEY_R2R - _threshold && _curInput < SELECT_LEFT_DOWN_RIGHTKEY_R2R + _threshold ) _curKey = SELECT_LEFT_DOWN_RIGHT_KEY;
        else if (_curInput > SELECT_LEFT_UP_RIGHTKEY_R2R - _threshold && _curInput < SELECT_LEFT_UP_RIGHTKEY_R2R + _threshold ) _curKey = SELECT_LEFT_UP_RIGHT_KEY;
        else if (_curInput > ALLKEY_R2R - _threshold && _curInput < ALLKEY_R2R + _threshold ) _curKey = ALL_KEY;
   }
   if (_change) {
                _actKey=_curKey;
                _previousMillis = _currentMillis;
                _counttime = _currentMillis - _previousMillis;
                return _actKey;
            } 
   else{
       _counttime = _currentMillis - _previousMillis;
       return _actKey;
    }
    
}
float ec_R2RplusR::VoltRefDivider(int AdcInput,float R1, float R2){
    analogReference(INTERNAL);          //hang on internal reference 1.1 Volt
    analogRead(AdcInput);               //just for waste 
    analogRead(AdcInput);               //just for waste
    float Volt= (((R1+R2)/R2)*(analogRead(AdcInput)*0.001074218));
    analogReference(DEFAULT);           //release on default reference
    return Volt;
	
}

unsigned long ec_R2RplusR::KeyTime(){
    return _counttime;
}

int ec_R2RplusR::KeyCanged(){
    return _change;
}

void ec_R2RplusR::KeyRate(int rate){
    _ADCreadings = rate;
}

void ec_R2RplusR::KeyADC(int ADCInput){
    _KeyADCInput = ADCInput;
}