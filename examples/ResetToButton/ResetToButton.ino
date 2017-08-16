/*   In this example is showed how to reset the position of stepper motor
 *   until a button is pressed.
 *   
 *   more information, documentation and schematics can be found to:
 *   https://github.com/DavideRuzza/28BYJ-48_ULN2003_ArduinoLibrary.git
*/

//include the stepper library
#include <Step_er.h>

/* initialize the stepper choosig one of three modes:
 *  HALF_STEP;
 *  FULL_STEP;
 *  WAVE_DRIVE;
 */
Step_er mystepper(HALF_STEP);

// the pin where is attached the button
int BtnPin = 6;

void setup() {

  //initialize the button
  pinMode(BtnPin, INPUT);
  
  //attach the stepper motor to its pin
  mystepper.attach(2,3,4,5);

  //choose true or false depending of direction
  //by default is setted to true.
  //so it can be avoided
  mystepper.resetTo(BtnPin, true);
}

void loop() {
}
