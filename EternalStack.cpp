/*
 * EternalStack.cpp
 * Created by Miguel Pachá, Sep 6, 2020.
 * 
 * License: LGPLv3
 */

#include "Arduino.h"
#include "EternalStack.h"

EternalStack::EternalStack(int start_value)
{
  stack_base = start_value;
  stack_size = EEPROM.read(stack_base);
}

void EternalStack::push(int value){
  stack_size++;
  EEPROM.write(stack_base + stack_size, value);
  EEPROM.write(stack_base, stack_size);
}

int EternalStack::pop(){
  int ret = EEPROM.read(stack_base + stack_size + 1);
  stack_size--;
  EEPROM.write(stack_base, stack_size);
  return ret;
}

