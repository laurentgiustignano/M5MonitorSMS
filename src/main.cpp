/*
    Description: Use SIM800L module to send SMS . before compile pls change the
   SMS center number and the Send number. ps: Module reset resistance is not
   soldered. if necessary, weld it yourself.
*/
#include <M5Stack.h>

#define RX_PIN    16
#define TX_PIN    17
#define RESET_PIN 5  // pin to the reset pin Sim800L



void header(const char *string, uint16_t color) {
    M5.Lcd.fillScreen(color);
    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(TFT_MAGENTA, TFT_BLUE);
    M5.Lcd.fillRect(0, 0, 320, 30, TFT_BLUE);
    M5.Lcd.setTextDatum(TC_DATUM);
    M5.Lcd.drawString(string, 160, 3, 4);
}




void setup() {
    M5.begin();
    M5.Power.begin();
    header("SIM800L Send message", TFT_BLACK);
    M5.Lcd.setTextFont(2);
    M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
    M5.Lcd.drawString("Please use serial port to view data.", 0, 35, 2);

    Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1, 16, 17, false);
    pinMode(5, OUTPUT);

    // delay for SIM800L power on
    delay(1000);
/*


    _sendSms();*/
}

void loop() {
    String str;

    while (Serial.available()) {
        if (Serial.available() > 0) {
            str += (char)Serial.read();
        }
    }
    Serial2.print(str);


    while (Serial2.available()) {
        if (Serial2.available() > 0) {
            str += (char)Serial2.read();
        }
    }
    Serial.print(str);

    delay(500);
}