#ifndef CSIMONCOLOR_H
#define CSIMONCOLOR_H

#include "Button.h"
#include "RGB.h"

class CSimonColor {
public:
  Button button;
  RGB rgb;
  
  CSimonColor(Button button, RGB rgb);
};

#endif
