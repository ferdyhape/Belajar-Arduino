#include <MD_Parola.h>  // Library MD_Parola
#include <MD_MAX72xx.h> // Library MD_MAX72
#include <SPI.h>        // Library SPI
 
const uint16_t WAIT_TIME = 1000;
 
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
 
#define MAX_DEVICES 4  // Instruksi untuk mengatur berapa banyak dotmatrix yang digunakan
#define CLK_PIN   13   // Deklarasi CLK pada pin 13 Arduino
#define DATA_PIN  11   // Deklarasi Data pada pin 11 Arduino
#define CS_PIN    10   // Deklarasi CS pada pin 10 Arduino 

int i = 0;

textEffect_t texteffect[] =
{
  PA_PRINT,
  PA_SCAN_HORIZ,
  PA_SCROLL_LEFT,
  PA_WIPE,
  PA_SCROLL_UP_LEFT,
  PA_SCROLL_UP,
  PA_OPENING_CURSOR,
  PA_GROW_UP,
  PA_MESH,
  PA_SCROLL_UP_RIGHT,
  PA_BLINDS,
  PA_CLOSING,
  PA_RANDOM,
  PA_GROW_DOWN,
  PA_SCAN_VERT,
  PA_SCROLL_DOWN_LEFT,
  PA_WIPE_CURSOR,
  PA_DISSOLVE,
  PA_OPENING,
  PA_CLOSING_CURSOR,
  PA_SCROLL_DOWN_RIGHT,
  PA_SCROLL_RIGHT,
  PA_SLICE,
  PA_SCROLL_DOWN
};
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Setup for software SPI:
// #define DATA_PIN 2
// #define CLK_PIN 4
// MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  myDisplay.begin();
  myDisplay.setIntensity(0);
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setPause(1000);
  myDisplay.setSpeed(100);
  myDisplay.displayClear();
}

void loop() {
  if (myDisplay.displayAnimate()) {
    if (i < sizeof(texteffect)) {
      i++;
    }
    else {
      i = 0;
    }
    myDisplay.displayText("Hello", myDisplay.getTextAlignment(), myDisplay.getSpeed(), myDisplay.getPause(), texteffect[i], texteffect[i]);
    myDisplay.displayReset();
  }
}