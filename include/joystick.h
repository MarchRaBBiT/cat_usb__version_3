#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <Arduino.h>

#include "layer_control.h"
#include "layouts_manager_cat.h"
#include "events.h"



class Joystick {

public:

    void initialize();
    void read_joystick();

    Joystick() {
        _read_joystick[0] = &Joystick::read_joystick_key;
        _read_joystick[1] = &Joystick::read_joystick_mouse;
    }

private:
    void read_joystick_key();
    void read_joystick_mouse();
    void (Joystick::*_read_joystick[2])(void);
    int joystickValues[2];

    // declaring the joystick thresholds
    const int threshold_l1 = 1600;
    const int threshold_l2 = 50;
    const int threshold_h1 = 2300;
    const int threshold_h2 = 4045;
    
    // declaring the joystick events
                                    //  JF1, JF2, JB1,  JB2,  JL1,  JL2, JR1, JR2
    byte joystick_event_map[2][4] = {{33,  34,  35,  36},  {39,  40,  37,  38}};

    bool joystick_state[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    const signed char joystick_mouse_speeds[7][16] = {
        {-1, -1, -1, -1,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1},
        {-2, -2, -2, -1, -1, -1,  0,  0,  0,  0,  1,  1,  1,  2,  2,  2},
        {-3, -3, -2, -2, -1, -1,  0,  0,  0,  0,  1,  1,  2,  2,  3,  3},
        {-4, -3, -3, -2, -2, -1, -1,  0,  0,  1,  1,  2,  2,  3,  3,  4},
        {-5, -5, -4, -3, -2, -1, -1,  0,  0,  1,  1,  2,  3,  4,  5,  5},
        {-6, -5, -4, -3, -2, -1, -1,  0,  0,  1,  1,  2,  3,  4,  5,  6},
        {-7, -6, -5, -4, -3, -2, -1,  0,  0,  1,  2,  3,  4,  5,  6,  7}};

    void one_step();
    void two_step();

    void actuate_event(byte axis, byte axis_event);
    void deactuate_event(byte axis, byte axis_event);
};

extern Joystick joystick;
#endif


