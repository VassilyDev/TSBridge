// Copyright (c) Alessandro Felicetti. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <Sharer.h>
#if ARDUINO > 22
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Stream.h"

class TSBridge {
public:
    // RECEIVED
    float kph = 0.0;
    float ammeter = 0.0;
    float vigilAlarm = 0.0;
    float AWS = 0.0;
    float PZB40 = 0.0;
    float PZB55 = 0.0;
    float PZB70 = 0.0;
    float PZB85 = 0.0;
    float PZB500 = 0.0;
    float PZB1000 = 0.0;
    float PZBWarn = 0.0;
    // SENT
    float throttle = 0.0;
    float brake = 0.0;
    float reverser = 0.0;
    float horn = 0.0;
    float wipers = 0.0;  
    float sander = 0.0;    
    float pantograph = 0.0;
    float startup = 0.0;
    float lights = 0.0;
    float vigilReset = 0.0;
    float AWSReset = 0.0;
    float CMD40 = 0.0;
    float CMDFree = 0.0;
    float CMDW = 0.0;
    float emergency = 0.0;
    float doorRight = 0.0;
    float doorLeft = 0.0;

  void begin();
  void begin(Stream* theStream);
  void run();


private:
    void shareVars();
    Stream* _stream;
};


