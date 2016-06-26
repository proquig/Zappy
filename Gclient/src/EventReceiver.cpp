#include "EventReceiver.hh"

EventReceiver::EventReceiver()
{
  for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
    KeyIsDown[i] = false;
}

void	EventReceiver::handle()
{
  if (KeyIsDown[irr::KEY_ESCAPE])
    exit(EXIT_SUCCESS);
/*  if (KeyIsDown[irr::KEY_MENU] && KeyIsDown[irr::KEY_F4])
    exit(EXIT_SUCCESS);*/
}

bool    EventReceiver::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return (false);
}
