#include <iostream>
#include "FSM.h"

struct StateFunction;

class MyFSM {
private:
    // All possible states
    StateFunction state_init();

    StateFunction state_run();

    StateFunction state_stop();

    // Current state function, referring to one of the above methods.
    StateFunction stateFunction = state_init(); // first state;

public:
    void update() { stateFunction = stateFunction(); }
};



StateFunction MyFSM::state_init() {

    std::cout << "In State INIT" << std::endl;
    return std::bind(&MyFSM::state_run, this);
}

StateFunction MyFSM::state_run() {
    std::cout << "In State RUN" << std::endl;
    return std::bind(&MyFSM::state_stop, this);
}

StateFunction MyFSM::state_stop() {
    std::cout << "In State STOP" << std::endl;
    return std::move(stateFunction);
}





int main() {

    MyFSM fsm;

    fsm.update();
    fsm.update();

    return 0;
}
