/*   In this example are showed all functions to move the stepper motor
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


void setup() {
  
  //attach the stepper motor to its pin
  mystepper.attach(2,3,4,5);

  /* for all the function of movement
   * the boolean argument is the direction
   * which can be either true or false
   * by default is setted to true
   * so it can be avoided
  */

  //rotate the motor by step;
  mystepper.step_move(400, true);

  delay(200);
  
  //rotate the motor by angle;
  mystepper.ang_move(90, false);

  delay(200);
  
  //rotate the motor by complete revolutions
  //in this case 2 complete revolutions.
  mystepper.turn(2, true);

  delay(200);

  //optional function is "stepper.one(dir)"
  //that move turn the motor by one single step.
  
}

void loop() {

}
