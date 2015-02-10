#include <RTTY.h>

void setup() {

  RTTY.attach(3);

}

void loop()
{

  RTTY.tx("3.141592654\n");
  delay(2000);

}
