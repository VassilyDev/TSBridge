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
    void setThrottle(float value);
    void setBrakes(float value);
    void setReverser(float value);
    void setHorn(int value);
    void setSander(int value);
    void setPantograph(int value);
    void setStartup(int value);
    void setLights(int value);
    void setVigilReset(int value);
    void setAwsReset(int value);
    void setCMD40(int value);
    void setCMDFree(int value);
    void setCMDW(int value);
    void setEmergency(int value);
    void begin();
    void begin(Stream* theStream);
    void run();

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


private:
    void shareVars();
    Stream* _stream;
    boolean beat = false;
    // INTERNAL CHANGE CONDITION
    int thCH = 0;
    int brCH = 0;
    int revCH = 0;
    int hCH = 0;
    int sCH = 0;
    int pCH = 0;
    int startCH = 0;
    int lCH = 0;
    int VIGILCH = 0;
    int AWSRCH = 0;
    int C40CH = 0;
    int CFCH = 0;
    int CMDWCH = 0;
    int eCH = 0;

    // SENT   
    float throttle = 0.0;
    float brake = 0.0;
    float reverser = 0.0;
    float horn = 0.0;
    //float wipers = 0.0;  
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
};


