/*
 * EternalStack.h
 * Created by Miguel Pachá, Sep 6, 2020.
 * 
 * License: LGPLv3
 */

#ifndef EternalStack_h
#define EternalStack_h

#include "Arduino.h"

#include <EEPROM.h>

class EternalStack
{
  public:
    EternalStack(int start_value);
    void push(int value);
    int pop(void);
  private:
    int stack_base;
    int stack_size;
};

#endif
