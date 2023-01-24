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
 
// Hardware SPI connection
MD_Parola Mx = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
 
void setup(void)
{
  Mx.begin();         // instruksi untuk memulai 
  Mx.setIntensity(10); // instruksi untuk mengatur intensitas cahaya (0-15)
  Mx.setTextAlignment(PA_CENTER);
}
 
void loop(void)
{
  Mx.print("Hello");  // instruksi untuk menampilkan karakter
  delay(500);
  Mx.displayClear();
  Mx.print("World");  
  delay(500);
  Mx.displayClear();
}