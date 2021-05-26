#include "ESP8266WiFi.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_I2CDevice.h>
#include <oled.h>

OLED display = OLED(4, 5, 16, 0x3C, 128, 64, true);

int timeLoad = random(27, 35);
int timeReboot = 0;
int randome = 0;

void normalFace()
{
  display.setCursor(20, 40);
  display.draw_circle(45, 20, 12, OLED::tFillmode::SOLID, OLED::tColor::WHITE);
  display.draw_circle(85, 20, 12, OLED::tFillmode::SOLID, OLED::tColor::WHITE);
}

void normalFace1(int location, int moveY)
{
  display.draw_rectangle(location, location - 15 + moveY,
                         location + 15, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_rectangle(location + 30, location - 15 + moveY,
                         location + 45, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);

  //Border top left of left eye
  display.draw_pixel(location, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location - 15 + moveY, OLED::tColor::BLACK);
  //Border top right of left eye
  display.draw_pixel(location + 15, location - 15 + moveY,
                     OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location - 15 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom left of left eye
  display.draw_pixel(location + 15, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location + 5 + moveY, OLED::tColor::BLACK);

  //Border top left of right eye
  display.draw_pixel(location + 30, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location - 15 + moveY, OLED::tColor::BLACK);

  //Border top right of right eye
  display.draw_pixel(location + 45, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location - 15 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location + 30, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location + 45, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location + 5 + moveY, OLED::tColor::BLACK);
}

void happyFace(int location, int moveY)
{
  display.draw_rectangle(location, location - 15 + moveY,
                         location + 15, location - 11 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_rectangle(location + 30, location - 15 + moveY,
                         location + 45, location - 11 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);

  //Border top left of left eye
  display.draw_pixel(location, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location - 15 + moveY, OLED::tColor::BLACK);
  //Border top right of left eye
  display.draw_pixel(location + 15, location - 15 + moveY,
                     OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location - 15 + moveY, OLED::tColor::BLACK);
  //Border top left of right eye
  display.draw_pixel(location + 30, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location - 15 + moveY, OLED::tColor::BLACK);

  //Border top right of right eye
  display.draw_pixel(location + 45, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location - 15 + moveY, OLED::tColor::BLACK);

  //bottom edge of left eye
  display.draw_line(location + 1, location - 11 + moveY, location + 14, location - 11 + moveY, OLED::tColor::BLACK);
  display.draw_line(location + 31, location - 11 + moveY, location + 44, location - 11 + moveY, OLED::tColor::BLACK);
}

void clipEyeMedium(int location, int moveY)
{
  display.draw_rectangle(location, location - 5 + moveY,
                         location + 15, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_rectangle(location + 30, location - 5 + moveY,
                         location + 45, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);

  display.draw_line(location + 1, location - 5 + moveY, location + 14, location - 5 + moveY, OLED::tColor::BLACK);
  display.draw_line(location + 31, location - 5 + moveY, location + 44, location - 5 + moveY, OLED::tColor::BLACK);
  //Border bottom right of left eye
  display.draw_pixel(location + 30, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location + 45, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom left of left eye
  display.draw_pixel(location + 15, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location + 5 + moveY, OLED::tColor::BLACK);
}

void closeEye(int location, int moveY)
{
  display.draw_rectangle(location, location + 2 + moveY,
                         location + 15, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_rectangle(location + 30, location + 2 + moveY,
                         location + 45, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_line(location + 1, location + 2 + moveY, location + 14, location + 2 + moveY, OLED::tColor::BLACK);
  display.draw_line(location + 31, location + 2 + moveY, location + 44, location + 2 + moveY, OLED::tColor::BLACK);
  //Border bottom right of left eye
  display.draw_pixel(location + 30, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location + 45, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom left of left eye
  display.draw_pixel(location + 15, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location + 5 + moveY, OLED::tColor::BLACK);
}

void openEyeMedium(int location, int moveY)
{
  display.draw_rectangle(location, location - 8 + moveY,
                         location + 15, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_rectangle(location + 30, location - 8 + moveY,
                         location + 45, location + 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);

  //Border top left of left eye
  display.draw_pixel(location, location - 8 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location - 7 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location - 8 + moveY, OLED::tColor::BLACK);
  //Border top right of left eye
  display.draw_pixel(location + 15, location - 8 + moveY,
                     OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location - 7 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location - 8 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom left of left eye
  display.draw_pixel(location + 15, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location + 5 + moveY, OLED::tColor::BLACK);

  //Border top left of right eye
  display.draw_pixel(location + 30, location - 8 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location - 7 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location - 8 + moveY, OLED::tColor::BLACK);

  //Border top right of right eye
  display.draw_pixel(location + 45, location - 8 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location - 7 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location - 8 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location + 30, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location + 5 + moveY, OLED::tColor::BLACK);

  //Border bottom right of left eye
  display.draw_pixel(location + 45, location + 5 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location + 4 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location + 5 + moveY, OLED::tColor::BLACK);
}

void openDownEye(int location, int moveY)
{
  display.draw_rectangle(location, location - 15 + moveY,
                         location + 15, location + 1 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_rectangle(location + 30, location - 15 + moveY,
                         location + 45, location + 1 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);

  //Border top left of left eye
  display.draw_pixel(location, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location - 15 + moveY, OLED::tColor::BLACK);
  //Border top right of left eye
  display.draw_pixel(location + 15, location - 15 + moveY,
                     OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location - 15 + moveY, OLED::tColor::BLACK);
  //Border top left of right eye
  display.draw_pixel(location + 30, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location - 15 + moveY, OLED::tColor::BLACK);

  //Border top right of right eye
  display.draw_pixel(location + 45, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location - 15 + moveY, OLED::tColor::BLACK);

  //bottom edge of left eye
  display.draw_line(location + 1, location + 1 + moveY, location + 14, location + 1 + moveY, OLED::tColor::BLACK);
  display.draw_line(location + 31, location + 1 + moveY, location + 44, location + 1 + moveY, OLED::tColor::BLACK);
}

void openUpEye(int location, int moveY)
{
  display.draw_rectangle(location, location - 15 + moveY,
                         location + 15, location - 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);
  display.draw_rectangle(location + 30, location - 15 + moveY,
                         location + 45, location - 5 + moveY,
                         OLED::tFillmode::SOLID,
                         OLED::tColor::WHITE);

  //Border top left of left eye
  display.draw_pixel(location, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 1, location - 15 + moveY, OLED::tColor::BLACK);
  //Border top right of left eye
  display.draw_pixel(location + 15, location - 15 + moveY,
                     OLED::tColor::BLACK);
  display.draw_pixel(location + 15, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 14, location - 15 + moveY, OLED::tColor::BLACK);
  //Border top left of right eye
  display.draw_pixel(location + 30, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 30, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 31, location - 15 + moveY, OLED::tColor::BLACK);

  //Border top right of right eye
  display.draw_pixel(location + 45, location - 15 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 45, location - 14 + moveY, OLED::tColor::BLACK);
  display.draw_pixel(location + 44, location - 15 + moveY, OLED::tColor::BLACK);

  //bottom edge of left eye
  display.draw_line(location + 1, location - 5 + moveY, location + 14, location - 5 + moveY, OLED::tColor::BLACK);
  display.draw_line(location + 31, location - 5 + moveY, location + 44, location - 5 + moveY, OLED::tColor::BLACK);
}
// 'face', 128x64px
void setup()
{
  display.begin();          // Instead of Serial.begin(9600)
  display.setTTYMode(true); // This set the TTY mode
  if (timeReboot != timeLoad)
  {
    display.printf(">_\tPowered by: \n\n");
    display.printf("\t[-Qiu Qiu Robotic-]\n\n\n");
    display.printf("\t  Version: 1.0.0");
    delay(4000);
    display.clear();
    display.printf("    [Deverlopers]\n\n > 1.Ng. Hoang Lam\n\n > 2. Ng. H Gia Luyn");
    delay(3000);
    display.clear();
    display.printf(" [Lauching the Tomo]\n");
    display.printf("\n>_ Starting");
    int loadingEffect = 0;

    for (timeReboot = 0; timeReboot < timeLoad; timeReboot++)
    {
      loadingEffect++;
      if (loadingEffect <= 3)
      {
        display.printf(".");
      }
      else
      {
        display.clear();
        display.printf(" [Lauching the Tomo]\n");
        display.printf("\n>_Open: Tomo_V1.sys\n");
        display.printf("\n>_ Starting");
        loadingEffect = 0;
      }
      delay(500);
    }
  }
}

void loop()
{
  int locationOfEyes = 45;
  int moveY = -10;
  display.clear();
  switch (randome)
  {
  case 0:
    closeEye(locationOfEyes, moveY);
    display.display();
    delay(2);
    clipEyeMedium(locationOfEyes, moveY);
    display.display();
    delay(5);
    openEyeMedium(locationOfEyes, moveY);
    display.display();
    delay(5);
    normalFace1(locationOfEyes, moveY);
    display.display();
    delay(random(3000, 5000));
    break;
  case 1:
    normalFace1(locationOfEyes, moveY);
    display.display();
    delay(random(200, 3000));
    display.clear();
    openDownEye(locationOfEyes, moveY);
    display.display();
    delay(5);
    display.clear();
    happyFace(locationOfEyes, moveY);
    display.display();
    delay(5000);
    break;
  default:
    break;
  }
  randome = random(0, 2);
  // Wait a bit before scanning again
}