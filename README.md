# falmec-hob2hood
Hob2Hood implementation for falmec kitchen hoods.

## Prerequisites

- hob2hood compatible kitchen hob (AEG, Electrolux, ..etc)
- falmec kitchen hood that supports remote control
- Arduino board (I've tested with uno & micro)
- infrared sensor (I've used TSOP34838)
- Radio frequency transmitter
- `IRremote` arduino library
- `RCSwitch` arduino library

## Guide

### IR sensor

- Wire ground & 5v to correct pins on your arduino board
- Wire DATA pin to pin 11 (make sure to change `IR_RECEIVE_PIN` value in the script if you plan to use some other pin)

### RF Transmitter
- Wire ground & 5v to correct pins on your arduino board
- Wire DATA pin to pin 10 (make sure to change `RF_SEND_PIN` value in the script if you plan to use some other pin)

### Workflow

- upload the provided script to your arduino
- make sure your IR sensor has direct vision to your hob
- turn on your hob and see the falmec hood turn on its lights, this means that you made it!

### Debugging

If your hood does not seem to receive the commands then check the serial monitor for command debug logs, those are printed every time your IR sensor receives a command from your hob. If you see the logs then it means that you can successfully read the commands from the hob side and the problem is somewhere with the RF transmitter. For me it helped when I attached an antenna to the transmitter.

If you don't even get the logs from the IR sensor then it means that you probably need to double check your connections or have a problem with the sensor itself.
