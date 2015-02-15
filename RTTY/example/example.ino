#include <RTTY.h>

void setup() {

  RTTY.attach(12);

}

void loop()
{
  delay(1000);
  RTTY.tx("\npi is 3.14159 correct to 5 decimal places.\n");
  RTTY.tx("\nThe quick brown fox jumps over the lazy dog\n");
  delay(2000);

}
