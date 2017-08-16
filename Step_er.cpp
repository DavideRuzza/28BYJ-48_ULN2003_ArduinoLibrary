#include "Step_er.h"

Step_er::Step_er(int mode){
  _mode = mode;
  if (_mode == 0 || _mode == 1){
    _Smax = 2048;
    _vel = 2000;
  } else {
    _Smax = 4095;
    _vel = 1000;
  }
}


void Step_er::attach(int IN1, int IN2, int IN3, int IN4) {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  _IN1 = IN1;
  _IN2 = IN2;
  _IN3 = IN3;
  _IN4 = IN4;

}

void Step_er::release() {
  digitalWrite(_IN1, LOW); 
  digitalWrite(_IN2, LOW);
  digitalWrite(_IN3, LOW);
  digitalWrite(_IN4, LOW);
}

void Step_er::resetTo(int btn, boolean dir){
  _dir = dir;
  pinMode(btn, INPUT);

  while(digitalRead(btn) != 1){
    _curMils = micros();
    if(_curMils-_ltime>=_vel){
      Stepping(1); 
      _ltime=micros();
      
    }
  }
}

void Step_er::step_move(int steps, boolean dir){
  _stepLeft = steps;
  _dir = dir;
  
  while(_stepLeft>0){
    _curMils = micros();
    if(_curMils-_ltime>=_vel){
      Stepping(1); 
      _ltime=micros();
      _stepLeft--;
    }
  }
}

void Step_er::one( boolean dir){
  _dir = dir;
  Stepping(1); 
  delay(5);
}

void Step_er::ang_move(float ang, boolean dir){
  _stepLeft = ang_to_step(ang);
  _dir = dir;
    
  while(_stepLeft>0){
    _curMils = micros();
    if(_curMils-_ltime>=_vel){
      Stepping(1); 
      _ltime=micros();
      _stepLeft--;
    }
  }
}

void Step_er::turn(int turns, boolean dir){
  _stepLeft = turns*_Smax;
  _dir = dir;
  
  while(_stepLeft>0){
    _curMils = micros();
    if(_curMils-_ltime>=_vel){
      Stepping(1); 
      _ltime=micros();
      _stepLeft--;
    }
  }
}

float Step_er::ang_to_step(float ang){
  return (ang * _Smax) / 360; 
}

void Step_er::Stepping(int xw){
  for (int x=0;x<xw;x++){
    digitalWrite(_IN1, _modes[_mode][_curStep][0]); 
    digitalWrite(_IN2, _modes[_mode][_curStep][1]);
    digitalWrite(_IN3, _modes[_mode][_curStep][2]);
    digitalWrite(_IN4, _modes[_mode][_curStep][3]);
  }
  SetDirection();
  delay(2);
}



void Step_er::SetDirection() {
  
  if(_dir==1){ 
    _curStep++;
  } else {
   _curStep--; 
  }
  
  if(_curStep>7){_curStep=0;}
  if(_curStep<0){_curStep=7;}
  //Serial.println(_curStep);
}



