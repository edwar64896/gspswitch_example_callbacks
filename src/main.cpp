#include <Arduino.h>
#include <gspswitch.h>

//Callbacks


/////////////////////////////////////////////////////////////////////////////
// TWO_POSITION_TOGGLE On/Off
/////////////////////////////////////////////////////////////////////////////
void  sw1_on() {
  Serial.println("you turn me on");
}

void sw1_off() {
  Serial.println("you turn me off");
}

gspSwitch sw1(1,sw1_on,sw1_off);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Active on release
/////////////////////////////////////////////////////////////////////////////
void pb1_activate_on_release () {
  Serial.println("You push me, activated on release");
}

gspSwitch pb1(2,pb1_activate_on_release);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Active on push
/////////////////////////////////////////////////////////////////////////////
void pb2_activate_on_push () {
  Serial.println("You push me, activated on push");
}

gspSwitch pb2(3,pb2_activate_on_push, 1);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Continuous Active on push
/////////////////////////////////////////////////////////////////////////////
void pb3_activate_continuously_on_push () {
  Serial.println("You keep pushing me");
}

gspSwitch pb3(4,pb3_activate_continuously_on_push, 2);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Latching with Long Push
/////////////////////////////////////////////////////////////////////////////
void pb4_on(){
  Serial.println("You turn me on");  
}

void pb4_off(){
  Serial.println("You turn me off");
}

void pb4_long(){
  Serial.println("You push me long time");  
}

gspSwitch pb4(5,pb4_on,pb4_off,pb4_long);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Latching with 2 Long Pushes
/////////////////////////////////////////////////////////////////////////////
void pb5_on(){
  Serial.println("You turn me on");  
}

void pb5_off(){
  Serial.println("You turn me off");
}

void pb5_long(){
  Serial.println("You push me long time");  
}

void pb5_verylong(){
  Serial.println("You push me for a very long time");  
}

gspSwitch pb5(6,pb5_on,pb5_off,pb5_long,pb5_verylong);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Multi-state push - Autoreset
/////////////////////////////////////////////////////////////////////////////
void pb6_statechange(uint8_t state) {
  switch(state) {
    case 0:
      Serial.println("auto reset back to state 0");
      break;
    case 1:
      Serial.println("change to state 1");
      break;
    case 2:
      Serial.println("change to state 2");
      break;
    case 3:
      Serial.println("change to state 3");
      break;
  }
}

gspSwitch pb6(7,4,pb6_statechange);

void holdoffReset() {
  pb6.counterAutoResetHoldoff();
  Serial.println("delaying autoreset");
}

gspSwitch pb6a(8,holdoffReset,1);

/////////////////////////////////////////////////////////////////////////////
// Momentary Pushbutton - Multi-state push - Manual Reset
/////////////////////////////////////////////////////////////////////////////
void pb7_statechange(uint8_t state) {
  switch(state) {
    case 0:
      Serial.println("manual reset back to state 0");
      break;
    case 1:
      Serial.println("change to state 1");
      break;
    case 2:
      Serial.println("change to state 2");
      break;
    case 3:
      Serial.println("change to state 3");
      break;
  }
}

gspSwitch pb7(9,4,pb7_statechange,1);

void resetme() {
  pb7.counterReset();
}

gspSwitch pb7a(10,resetme);

/////////////////////////////////////////////////////////////////////////////

void pb8_Tellme() {
  Serial.println("pb6 is in state " + String (pb6.getCounterValue());
  Serial.println("pb7 is in state " + String (pb7.getCounterValue());
}

gspSwitch pb8(11,pb8_Tellme);

/////////////////////////////////////////////////////////////////////////////
// Setup Function
/////////////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  gspGrouped::register_instance( & sw1 );
  gspGrouped::register_instance( & pb1 );
  gspGrouped::register_instance( & pb2 );
  gspGrouped::register_instance( & pb3 );
  gspGrouped::register_instance( & pb4 );
  gspGrouped::register_instance( & pb5 );
  gspGrouped::register_instance( & pb6 );
  gspGrouped::register_instance( & pb6a );
  gspGrouped::register_instance( & pb7 );
  gspGrouped::register_instance( & pb7a );
  gspGrouped::register_instance( & pb8 );
}

/////////////////////////////////////////////////////////////////////////////
// Loop Function
/////////////////////////////////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  gspSwitch::checkAll();
}