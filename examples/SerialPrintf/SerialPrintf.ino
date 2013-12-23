/*
 * Example program which showcases some of the abilities of StrPrintf
 *
 * The output to the serial port should be (this output was done while
 * running on a Teensy 3.1. On the AVR, I suspect that %u will produce
 * 65532 when passed -4):
 *
 *  In setup()
 *  >%d< >1< >%05d< >00002< >%5d< >    3<
 *  >%u< >1< >%05u< >00002< >%5u< >    3<
 *  >%u< >4294967292< >%d< >-4<
 *  >%o< >12< >%04o< >0013<
 *  >%x< >a< >%04x< >000b<
 *  >%X< >A< >%04X< >000B<
 *  >%b< >110< >%04b< >0111<
 *  >%s< >Test< >%c< >F<
 *  >%-8s< >abc     < >%8s< >     abc<
 *  Count = 0
 *  Count = 1
 *  Count = 2
 *  Count = 3
 *  Count = 4
 *  ...
 */


#include "StrPrintf.h"
#include <stdarg.h>

int SerialPrintFunc(void *param, int ch)
{
  if (ch == '\n') {
    Serial.print('\r');
  }
  Serial.print((char)ch);
}

void SerialPrintf(const char *fmt, ...)
{
  va_list  args;
  
  va_start(args, fmt);
  vStrXPrintf(SerialPrintFunc, nullptr, fmt, args);
  va_end(args);
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  SerialPrintf("In setup()\n");
  SerialPrintf(">%%d< >%d< >%%05d< >%05d< >%%5d< >%5d<\n", 1, 2, 3);
  SerialPrintf(">%%u< >%u< >%%05u< >%05u< >%%5u< >%5u<\n", 1, 2, 3);
  SerialPrintf(">%%u< >%u< >%%d< >%d<\n", -4, -4);
  SerialPrintf(">%%o< >%o< >%%04o< >%04o<\n", 10, 11);
  SerialPrintf(">%%x< >%x< >%%04x< >%04x<\n", 10, 11);
  SerialPrintf(">%%X< >%X< >%%04X< >%04X<\n", 10, 11);
  SerialPrintf(">%%b< >%b< >%%04b< >%04b<\n", 6, 7);
  SerialPrintf(">%%s< >%s< >%%c< >%c<\n", "Test", 'F');
  SerialPrintf(">%%-8s< >%-8s< >%%8s< >%8s<\n", "abc", "abc");
}

int count = 0;

void loop() {
  SerialPrintf("Count = %d\n", count++);
  delay(1000);
}
