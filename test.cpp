/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

void person_test();
void elevator_test();

void start_tests() {
    // call your test functions here
    person_test();
    elevator_test();
    
    return;
}

// write test functions here



void person_test() {
    //initialize a person with targetFloor 5, anger 5
        Person p("0f0t5a5");
        cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 5" << endl;
        //simulate time being a multiple of TICKS_PER_ANGER_INCREASE
        bool exploded = p.tick(TICKS_PER_ANGER_INCREASE);
        cout << exploded << " Expected 0" << endl;
        cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;
        //simulate time not being a multiple
        p.tick(TICKS_PER_ANGER_INCREASE - 1);
        //no change
        cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;
        p.tick(TICKS_PER_ANGER_INCREASE); //7 after
        p.tick(TICKS_PER_ANGER_INCREASE); //8 after
        p.tick(TICKS_PER_ANGER_INCREASE); //9 after
        exploded = p.tick(TICKS_PER_ANGER_INCREASE);
        cout << exploded << " Expected 1" << endl;
    
    
    
       Person p2("10f10t10a10");
       cout << p2.getTargetFloor() << " " << p2.getAngerLevel() << " Expected 9 1" << endl;
       cout << p2.getCurrentFloor() << " " << p2.getTurn() << " Expected 9 3" << endl;
       cout << "Expected: f3t9a1, Actual: " << p2 << endl;
    
    
    Person p3("1f1t1a1");
    cout << p3.getTargetFloor() << " " << p3.getAngerLevel() << endl;
    cout << p3.getCurrentFloor() << " " << p3.getTurn() << endl;
    cout << p3 << endl;
    
    
    
    
    p2.tick(TICKS_PER_ELEVATOR_MOVE * 10);
    p2.tick(TICKS_PER_ELEVATOR_MOVE % 11);
    p2.tick(TICKS_PER_ELEVATOR_MOVE * -12);
    
    
    
    
}


void elevator_test() {
    
    Elevator e1;
    cout << e1.getTargetFloor() << " " << e1.getCurrentFloor() << endl;
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    
    Elevator e2;

    e2.serviceRequest(4);
    cout << e2.isServicing() << endl;
    e2.tick(TICKS_PER_ELEVATOR_MOVE);
    e2.tick(TICKS_PER_ELEVATOR_MOVE);
    e2.tick(TICKS_PER_ELEVATOR_MOVE);
    e2.tick(TICKS_PER_ELEVATOR_MOVE);
    e2.print(cout);
    
    

}


