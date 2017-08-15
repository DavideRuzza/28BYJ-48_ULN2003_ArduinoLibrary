#ifndef sp
#define sp

#include "arduino.h"

#define WAVE_DRIVE 0
#define FULL_STEP 1
#define HALF_STEP 2

class Step_er {
  public:
    
    Step_er(int mode);
    void attach(int IN1, int IN2, int IN3, int IN4);
    void release();
    void resetb(int btn, boolean dir=true);
    void step_move(int steps, boolean dir=true);
    void ang_move(float ang, boolean dir=true);
    void turn(int turns, boolean dir=true);
    void one(boolean dir=true);
    
  private:

    void SetDirection();
    void Stepping(int xw);

    float ang_to_step(float ang);
    
    int _IN1, _IN2, _IN3, _IN4;
    int _mode;
    int _Smax;
    int _curStep = 0;
    int _step, _stepLeft;
    int _vel;
    int _turns;
    int _modes[3][8][4] = {
                          {{LOW, LOW, LOW, HIGH},{LOW, LOW, HIGH,LOW},{LOW, HIGH, LOW, LOW},{HIGH, LOW, LOW, LOW},{LOW, LOW, LOW, HIGH},{LOW, LOW, HIGH,LOW},{LOW, HIGH, LOW, LOW},{HIGH, LOW, LOW, LOW}},
                          {{LOW, LOW, HIGH, HIGH},{LOW, HIGH, HIGH, LOW},{HIGH, HIGH, LOW, LOW},{HIGH, LOW, LOW, HIGH},{LOW, LOW, HIGH, HIGH},{LOW, HIGH, HIGH, LOW},{HIGH, HIGH, LOW, LOW},{HIGH, LOW, LOW, HIGH}},
                          {{LOW, LOW, LOW, HIGH},{LOW, LOW, HIGH, HIGH},{LOW, LOW, HIGH, LOW},{LOW, HIGH, HIGH, LOW},{LOW, HIGH, LOW, LOW},{HIGH, HIGH, LOW, LOW},{HIGH, LOW, LOW, LOW},{HIGH, LOW, LOW, HIGH}}
                          };
    boolean _dir;
    unsigned long _ltime = 0;
    unsigned long _curMils;
};

#endif
