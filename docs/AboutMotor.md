# Understenging the Stepper Motor

In this file is described how the stepper motor work and how is made.


## About the 28BYJ-48

* The 28BYJ-48 is an unipolar stepper motor

<img src="https://github.com/DavideRuzza/Stepper_28BY48_ULN2003/blob/master/images/28BYJ-48-coil_scheme.png">


To turn the internal rotor shaft is required a cycle of **8** steps, than due to the gear reduction of **64:1** (_63.65..._) the steps are bring to **2048** which are the steps to do an entire revolution of the external motor shaft.

<img src="https://github.com/DavideRuzza/Stepper_28BY48_ULN2003/blob/master/images/GearRatio.png" height=300px>


## Stepping mode

There are three mode to drive this stepper motor:
  * `WAVE_DRIVE`, this mode is rarely used and it have not any specific features. (_**2048** steps by revolution_)
  * `FULL_STEP` , this mode is stronger than wave_drive because for the entire cycles, 2 coils are activated an so it has two times the power. (_**2048** steps by revolution_)
  * `HALF_STEP` , this mode has half power of full_step mode beacause only for the half of the time, 2 coils are activated, but in this mode the steps by revolutions are doubled. (_**4096** steps by revolution_)

<img src="https://github.com/DavideRuzza/Stepper_28BY48_ULN2003/blob/master/images/SteppingModes.png" height = 400px>
