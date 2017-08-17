# This is the documentation file for of the library

In this file is described how to use the library and all its functions.


## Setup the library

To import the library:
```Ino
#include <Step_er.h>
```
Initialize the Step_er class:
```Ino
Step_er mystepper(_mode_);
```
The mode has to be choosed between **STEP_DRIVE**, **FULL_STEP**, **HALF_STEP** (_read more in the motor doc_ [Stepping mode](https://github.com/DavideRuzza/Stepper_28BY48_ULN2003/blob/master/docs/AboutMotor.md#stepping-mode)).

Initialize the stepper motor:
```Ino
void setup() {
  
  mystepper.attach(_IN1, _IN2, _IN3, _IN4);

}
```
**\_IN1**, **\_IN2**, **\_IN3**, **\_IN4** are the pin where the ULN2003 driver is atthacched to.

## Library Functions

There are different function to turn the motor:

In all function **\_direction** is a `boolean`, and is referred to the direction of the movement **_True_=clockwise** or **_False_=anticlockwise**.

- **Turn by steps**:
  ```Ino
  mystepper.step_move(_steps, _direction);
  ```
  **\_steps** is an `int`, and is referred to the number of steps to move by; 

- **Turn by angle**:
  ```Ino
  mystepper.ang_move(_angle, _direction);
  ```
  **\_angle** is a `float`, and is referred to the angle to move by; 

- **Turn by revolutions**:
  ```Ino
  mystepper.turn(_revolution, _direction);
  ```
  **\_revolutions** is an `int`, and is referred to the number of revolutions (full turn of 360°) to move by; 

- **Turn by a single step**:
  ```Ino
  mystepper.one(_direction);
  ```
  This function allow to move by a single step without calling the `.step_move` method.

### Special Functions

This library contain also other special function.

- **Reset Until Button is Pressed**:
  ```Ino
  mystepper.resetTo(_ButtonPin, _direction);
  ```
  **\_ButtonPin** is an `int`, and is referred to the pin where the button is attached. this function is mentioned in an example of the library [ResetToButton](https://github.com/DavideRuzza/Stepper_28BY48_ULN2003/tree/master/examples/ResetToButton) and the schematic can be found in the [images](https://github.com/DavideRuzza/Stepper_28BY48_ULN2003/tree/master/images) folder of the library or in the [ReadMe](https://github.com/DavideRuzza/Stepper_28BY48_ULN2003/blob/master/README.md#the-schematic).
  
Read the documentation of the motor at []

