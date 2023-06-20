#include "DimmableLed.hpp"
#include "Button.hpp"
#include "UART.hpp"
#include "LedButton.hpp"

DimmableLed dimmableLed(12 , "led");
//Button<2> myLedButton("bouton",true);
LedButton<2> myLedButton(dimmableLed, true);
bool isPressed = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
    if (myLedButton.IsPressed()) {
    Serial.print("Allumer\n");
    dimmableLed.SwitchOn();
    if (!isPressed)
      myLedButton.OnButtonReleased(millis());
    isPressed = true;
  } else {
    Serial.print("Eteindre\n");
    dimmableLed.SwitchOff();
    if (isPressed) {
      isPressed = false;
      myLedButton.OnButtonPressed(millis());
    }
  }



  delay(100);

}
