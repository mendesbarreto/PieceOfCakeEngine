#ifndef __PC_EVENT__
#define __PC_EVENT__

#include "SDL.h"

class PCEvent
{
public:
	PCEvent(void);

	virtual void OnEvent(SDL_Event* event);
	virtual void OnInputFocus();
	virtual void OnInputBlur();
	virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
	virtual void OnMouseFocus();
	virtual void OnMouseBlur();
	virtual void OnMouseMove(int x, int y, int relX, int relY, bool left, bool right, bool middle);
	virtual void OnMouseWheel(bool up, bool down);
	virtual void OnLButtonDown(int x, int y);
	virtual void OnLButtonUp(int x, int y);
	virtual void OnRButtonDown(int x, int y);
	virtual void OnRButtonUp(int x, int y);
	virtual void OnMButtonDown(int x, int y);
	virtual void OnMButtonUp(int x, int y);
	virtual void OnJoyAxis(Uint8 which , Uint8 axis, Sint16 value);
	virtual void OnJoyButtonDown(Uint8 which, Uint8 button);
	virtual void OnJoyButtonUp(Uint8 which, Uint8 button);
	virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
	virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
	virtual void OnMinimize();
	virtual void OnRestore();
	virtual void OnResize(int w, int h);
	virtual void OnExpose();
	virtual void OnExit();
	virtual void OnUser(Uint8 type, int code, void * data1, void * data2);	

	virtual ~PCEvent(void);
};

#endif // !__PC_EVENT__