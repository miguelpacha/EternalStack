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

EternalStack stack(0);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Boot");
  for (int i=0; i<10; i++){
    Serial.print(i);
    Serial.print(" ");
    Serial.print(EEPROM.read(i));
    Serial.print("\n");
  }
  stack.push(42);
}

void loop() {
  // put your main code here, to run repeatedly:
}
