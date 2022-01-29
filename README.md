![GitHub](https://img.shields.io/github/license/rufus31415/sharer)
# Arduino TSBridge
An Arduino library for controlling Train Simulator, based on RailDriver.dll and Sharer.dll. The project consists of a Windows application that must run when Train Simulator is running, and an Arduino library.
This project is in development, and any contribution is appreciated.

## Project structure
Download the Windows application (.zip file). Copy the entire content of the archive in the "Plugins" directory of Train Simulator. You can launch the app directly from this folder or as a shortcut from the Desktop.

## Compatible Hardware
The library has been tested on Arduino Uno/Micro/Mega. Other boards should be supported, as the Serial interface is user-configurable.

## Installation

### Using the Arduino IDE Library Manager

1. Choose `Sketch` -> `Include Library` -> `Add .ZIP Library...`
2. Select the library downloaded from GitHub as ZIP.

### Using Git

```sh
cd ~/Documents/Arduino/libraries/
git clone https://github.com/VassilyDev/TSBridge
```

## Examples

See [examples](examples) folder.

## License

This library is [licensed](LICENSE) under the [MIT Licence](http://en.wikipedia.org/wiki/MIT_License).

