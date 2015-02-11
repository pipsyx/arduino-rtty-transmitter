#include <RTTY.h>

void setup() {

  RTTY.attach(3);

}

void loop()
{

  RTTY.tx("pi is 3.14159 correct to 5 decimal places.\n");
  delay(2000);

}
