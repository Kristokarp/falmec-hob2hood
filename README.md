# falmec-hob2hood
Hob2Hood implementation for falmec kitchen hoods.

## Prerequisites

- hob2hood compatible kitchen hob (AEG, Electolux, ..etc)
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
