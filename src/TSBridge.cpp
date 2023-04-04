// Copyright (c) Alessandro Felicetti. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "TSBridge.h"

void TSBridge::begin() {
    Sharer.init(115200);
    shareVars();
}

void TSBridge::begin(Stream* theStream) {
    _stream = theStream;
    //_stream->begin(115200);
    Sharer.init(theStream);
    shareVars();
}

void TSBridge::shareVars() {
    // Variabili in uscita
    Sharer_ShareVariable(float, throttle);
    Sharer_ShareVariable(float, brake);
    Sharer_ShareVariable(float, reverser);
    Sharer_ShareVariable(float, horn);
    Sharer_ShareVariable(float, sander);
    Sharer_ShareVariable(float, pantograph);
    Sharer_ShareVariable(float, startup);
    Sharer_ShareVariable(float, lights);
    Sharer_ShareVariable(float, vigilReset);
    Sharer_ShareVariable(float, AWSReset);    
    Sharer_ShareVariable(float, CMD40);
    Sharer_ShareVariable(float, CMDFree);
    Sharer_ShareVariable(float, CMDW);
    Sharer_ShareVariable(float, emergency);
    //Sharer_ShareVariable(float, wipers); 
    /*/Sharer_ShareVariable(float, doorRight);
    Sharer_ShareVariable(float, doorLeft);*/

    // Variabili di conferma
    Sharer_ShareVariable(int, thCH);
    Sharer_ShareVariable(int, brCH);
    Sharer_ShareVariable(int, revCH);
    Sharer_ShareVariable(int, hCH);
    Sharer_ShareVariable(int, sCH);
    Sharer_ShareVariable(int, pCH);
    Sharer_ShareVariable(int, startCH);
    Sharer_ShareVariable(int, lCH);
    Sharer_ShareVariable(int, VIGILCH);
    Sharer_ShareVariable(int, AWSRCH);
    Sharer_ShareVariable(int, C40CH);
    Sharer_ShareVariable(int, CFCH);
    Sharer_ShareVariable(int, CMDWCH);
    Sharer_ShareVariable(int, eCH);

    // Variabili in ingresso
    Sharer_ShareVariable(float, kph);
    Sharer_ShareVariable(float, ammeter);
    Sharer_ShareVariable(float, vigilAlarm);
    Sharer_ShareVariable(float, AWS);
    Sharer_ShareVariable(float, PZB40);
    Sharer_ShareVariable(float, PZB55);
    Sharer_ShareVariable(float, PZB70);
    Sharer_ShareVariable(float, PZB85);
    Sharer_ShareVariable(float, PZB500);
    Sharer_ShareVariable(float, PZB1000);
    Sharer_ShareVariable(float, PZBWarn);
}
void TSBridge::run() {
    Sharer.run();
    if (beat == true) {
        thCH = 0;
        brCH = 0;
        revCH = 0;
        hCH = 0;
        sCH = 0;
        pCH = 0;
        startCH = 0;
        lCH = 0;
        VIGILCH = 0;
        AWSRCH = 0;
        C40CH = 0;
        CFCH = 0;
        CMDWCH = 0;
        eCH = 0;
    }
    beat = false;
}

void TSBridge::setThrottle(float value) {
    throttle = value;
    thCH = 1;
}
void TSBridge::setBrakes(float value) {
    brake = value;
    brCH = 1;
}
void TSBridge::setReverser(float value) {
    reverser = value;
    revCH = 1;
}
void TSBridge::setHorn(int value) {
    horn = (float)value;
    hCH = 1;
}
void TSBridge::setSander(int value) {
    sander = (float)value;
    sCH = 1;
}
void TSBridge::setPantograph(int value) {
    pantograph = (float)value;
    pCH = 1;
}
void TSBridge::setStartup(int value) {
    startup = (float)value;
    startCH = 1;
}
void TSBridge::setLights(int value) {
    lights = value;
    lCH = 1;
}
void TSBridge::setVigilReset(int value) {
    vigilReset = (float)value;
    VIGILCH = 1;
}
void TSBridge::setAwsReset(int value) {
    AWSReset = (float)value;
    AWSRCH = 1;
}
void TSBridge::setCMD40(int value) {
    CMD40 = (float)value;
    C40CH = 1;
}
void TSBridge::setCMDFree(int value) {
    CMDFree = (float)value;
    CFCH = 1;
}
void TSBridge::setCMDW(int value) {
    CMDW = (float)value;
    CMDWCH = 1;
}
void TSBridge::setEmergency(int value) {
    emergency = (float)value;
    eCH = 1;
}





