# Yet Another GBP Emulator (NeoGB Printer)
Yes, it's another Game Boy Printer emulator! The idea is just plug an SD card, print your images using a game compatible with Gameboy Printer and save as BMP image.


You can check the compatibility list here: [Game Boy Printer Emulator - Games Support](https://docs.google.com/spreadsheets/d/1RQeTHemyEQnWHbKEhUy16cPxR6vA3YfeBbyx2tIXWaU/edit#gid=0)

## Hardware Setup
Gameboy Original/Color Link Cable Pinout
```
 __________
|  6  4  2 |
 \_5__3__1_/ (at cable)

| Link Cable |  ESP32  |
|------------|---------|
| Pin 1      | Any pin | 
| Pin 2      | G19     |
| Pin 3      | G23     |
| Pin 4      |   N/A   |
| Pin 5      | G18     |
| Pin 6      | G       |

```

## SD/MicroSD Card Setup
You need use a [Micro SD Card Module](https://pt.aliexpress.com/item/4000002592780.html) or a [SD Card Module](https://pt.aliexpress.com/item/32523666863.html) to save the received data and the web server content. I highly recommend to get one, especially the [SD Card Module](https://pt.aliexpress.com/item/32523666863.html), It's more stable than [Micro SD Card Module](https://pt.aliexpress.com/item/4000002592780.html).
To use it, connect the pins following this schema
```
| SD ADAPTER |  ESP32  |
|------------|---------|
| CS         | G15     | 
| SCK        | G14     |
| MISO       | G27     | <-- DON'T USE THE G12... YOU CAN USE ANY OTHER PIN AVAILABLE
| MOSI       | G13     |
| GND        | G       |
| VCC/5v     | VIN     |
| 3v3        |   N/A   |

```


## OLED Display
You can add a [tiny oled display like this](https://pt.aliexpress.com/item/32672229793.html). To use it, you need to uncomment `#define USE_OLED` and the following lines   
The display will show the current wifi-config while in server mode, as well as the number of printed images when in printer mode  
```
| OLED DISPLAY|   ESP32   |
|-------------|-----------|
| GND         | GND       | 
| VIN         | 5v or 3v3 |
| SCL         | G22       | <-- YOU CAN USE ANY GPIO AVAILABLE
| SDA         | G21       | <-- YOU CAN USE ANY GPIO AVAILABLE

```

# ToDo List:
- [ ] Update documetation (wiring, compatible devices, etc)
- [x] Update the code to support all games
- [x] Use the original BMP library from Mofosyne C decompiler
- [ ] Create the file automatically when the emulator finishes to receive all the data (If possible)
- [ ] Write the BMP file on SD

# Based on:
* [Mofosyne - Arduino Gameboy Printer Emulator](https://github.com/mofosyne/arduino-gameboy-printer-emulator)
* [HerrZatacke - WiFi Game Boy Printer Emulator](https://github.com/HerrZatacke/wifi-gbp-emulator)
* [Raphaël BOICHOT - Gameboy Printer Paper Simulation](https://github.com/Raphael-Boichot/GameboyPrinterPaperSimulation)
