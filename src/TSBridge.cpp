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
    Sharer_ShareVariable(float, throttle);
    Sharer_ShareVariable(float, brake);
    Sharer_ShareVariable(float, reverser);
    Sharer_ShareVariable(float, horn);
    Sharer_ShareVariable(float, wipers);
    Sharer_ShareVariable(float, kph);
    Sharer_ShareVariable(float, ammeter);
    Sharer_ShareVariable(float, sander);
    Sharer_ShareVariable(float, ammeter);
    Sharer_ShareVariable(float, pantograph);
    Sharer_ShareVariable(float, startup);
    Sharer_ShareVariable(float, lights);
    Sharer_ShareVariable(float, vigilReset);
    Sharer_ShareVariable(float, vigilAlarm);
    Sharer_ShareVariable(float, AWS);
    Sharer_ShareVariable(float, AWSReset);
    Sharer_ShareVariable(float, PZB40);
    Sharer_ShareVariable(float, PZB55);
    Sharer_ShareVariable(float, PZB70);
    Sharer_ShareVariable(float, PZB85);
    Sharer_ShareVariable(float, PZB500);
    Sharer_ShareVariable(float, PZB1000);
    Sharer_ShareVariable(float, PZBWarn);
    Sharer_ShareVariable(float, CMD40);
    Sharer_ShareVariable(float, CMDFree);
    Sharer_ShareVariable(float, CMDW);
    Sharer_ShareVariable(float, emergency);
    Sharer_ShareVariable(float, doorRight);
    Sharer_ShareVariable(float, doorLeft);
}
void TSBridge::run() {
    Sharer.run();
}





