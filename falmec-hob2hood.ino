#include <Arduino.h>
#include <IRremote.hpp>
#include <RCSwitch.h>

#define IR_RECEIVE_PIN 11
#define RF_SEND_PIN 10
#define NO_LED_FEEDBACK_CODE

// Hob2Hood IR Codes
#define HOB_ON      0xE208293C 
#define HOB_LEVEL_1 0xE3C01BE2
#define HOB_LEVEL_2 0xD051C301
#define HOB_LEVEL_3 0xC22FFFD7
#define HOB_LEVEL_4 0xB9121B29
#define HOB_OFF     0x55303A3

// Falmec Hood codes, protocol 11
#define HOOD_ON      32699 
#define HOOD_LEVEL_1 32571  
#define HOOD_LEVEL_2 32443
#define HOOD_LEVEL_3 32315 
#define HOOD_LEVEL_4 32187 
#define HOOD_OFF     32763

RCSwitch rfTransmitter = RCSwitch(); 


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  rfTransmitter.enableTransmit(RF_SEND_PIN);
  rfTransmitter.setProtocol(11);
}

void loop() {
  if (IrReceiver.decode()) {
        IrReceiver.resume();

        switch (IrReceiver.decodedIRData.decodedRawData) {
        case HOB_ON:
            Serial.println("FAN on");
            rfTransmitter.send(HOOD_ON, 16);
            break;
        case HOB_LEVEL_1:
            Serial.println("FAN 1");
            rfTransmitter.send(HOOD_LEVEL_1, 16);
            break;
        case HOB_LEVEL_2:
            Serial.println("FAN 2");
            rfTransmitter.send(HOOD_LEVEL_2, 16);
            break;
        case HOB_LEVEL_3:
            Serial.println("FAN 3");
            rfTransmitter.send(HOOD_LEVEL_3, 16);
            break;            
        case HOB_LEVEL_4:
            Serial.println("FAN 4");
            rfTransmitter.send(HOOD_LEVEL_4, 16);
            break;    
        case HOB_OFF:
            Serial.println("FAN off");
            rfTransmitter.send(HOOD_OFF, 16);
            break;
        default:
            Serial.println("unknown Hob2Hood IR command");
            break;
        }
    }
}
