#ifndef EVENTRECEIVER_HH_
# define EVENTRECEIVER_HH_

#include "irrlicht.h"

using namespace irr;

class EventReceiver : public IEventReceiver
{
    bool    KeyIsDown[KEY_KEY_CODES_COUNT];
public:
    EventReceiver();
    ~EventReceiver() {};
    virtual bool OnEvent(const irr::SEvent &event);
    void    handle();
};

#endif