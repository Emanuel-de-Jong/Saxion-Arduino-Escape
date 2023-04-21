// A button - color combination for the sequence in the Simon challenge

#ifndef CSIMONCOLOR_H
#define CSIMONCOLOR_H

#include "src/hardware/Button.h"
#include "src/RGB.h"

class CSimonColor
{
public:
  Button button;
  RGB rgb;

  CSimonColor();
  CSimonColor(Button button, RGB rgb);
};

#endif
