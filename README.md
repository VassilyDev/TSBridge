![GitHub](https://img.shields.io/github/license/rufus31415/sharer)
![.NET Framework 3.5](https://img.shields.io/badge/.NET_Framework-3.5-blueviolet)
![Arduino Uno](https://img.shields.io/badge/Arduino-any-blue)

TSBridge is an Arduino library for controlling Train Simulator, based on RailDriver.dll and Sharer.dll. The project is completed by a Windows application that must run when Train Simulator is running, communicating with the board with a referesh rate of about 10Hz.
This project is in development, and any contribution is appreciated.

# Overview

### How to install the application 
Please download the windows application here [Releases](https://github.com/VassilyDev/TSBridge/releases/). Extract the entire content of the archive in the "Plugins" directory of Train Simulator. You can launch the app directly from this folder or as a shortcut from the Desktop.

### Project info
A list of currently supported loco and library keywords is available in the wiki.
Please see [Compatible loco](https://github.com/VassilyDev/TSBridge/wiki/Compatible-loco-and-trains) and [Documentation](https://github.com/VassilyDev/TSBridge/wiki/Documentation) for details.

# Download and install Arduino library
This library depends on Sharer (by Rufus31415) to communicate with the Arduino board. Please download it from the library Manager or
https://github.com/Rufus31415/Sharer
The library has been tested on Arduino Uno/Micro/Mega. Other boards should be supported, as the Serial interface is user-configurable.

### Using the Arduino IDE Library Manager

1. Choose `Sketch` -> `Include Library` -> `Add .ZIP Library...`
2. Select the library downloaded from GitHub as ZIP.

### Direct download

Download the library archive:
https://github.com/VassilyDev/TSBridge/archive/refs/heads/main.zip
Extract so that you get a TSBridge directory in your Arduino "libraries" directory : ```C:\Program Files (x86)\Arduino\libraries\TSBridge```
You can then enjoy the examples by restarting your Arduino IDE and go to menu ```File / examples / TSBridge```.

### Using Git

```sh
cd ~/Documents/Arduino/libraries/
git clone https://github.com/VassilyDev/TSBridge
```

### Examples

See [examples](examples) folder.

## License

This library is [licensed](LICENSE) under the [MIT Licence](http://en.wikipedia.org/wiki/MIT_License).

