#include "PCEvent.h"
#include <SDL.h>

#define JUNK_TRHESHOLD 6200

PCEvent::PCEvent(void)
{
}


PCEvent::~PCEvent( void )
{

}

void PCEvent::OnEvent( SDL_Event* event )
{
	switch (event->type)
	{
	
	case SDL_WINDOWEVENT: 
		{
			case SDL_WINDOWEVENT_FOCUS_GAINED: 
			{
				OnInputFocus();
			
				break;
			}
			case SDL_WINDOWEVENT_FOCUS_LOST:
			{
				OnInputBlur();
				break;
			}

			case SDL_WINDOWEVENT_ENTER: 
			{
				OnMouseFocus();
				break;
			}

			case SDL_WINDOWEVENT_LEAVE: 
			{
				OnMouseBlur();
				break;
			}

			case SDL_WINDOWEVENT_MINIMIZED:    
			{
				OnMinimize();
				break;
			}

			case SDL_WINDOWEVENT_RESTORED:    
			{
				OnRestore();
				break;
			}
			
			default:
				SDL_Log("Window %d got unknown event %d", event->window.windowID, event->window.event);
				break;
		}

		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		//////////////////////     JOYSTICK EVENTS    ////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////// 
	
	
	case SDL_JOYAXISMOTION: 
		{
			// Axis checks and ignore threshold bellow of 32000
			if(event->jaxis.value < -JUNK_TRHESHOLD || event->jaxis.value > JUNK_TRHESHOLD)
			{
				OnJoyAxis(event->jaxis.which,event->jaxis.axis,event->jaxis.value);
			}
			
			break;
		}

	case SDL_JOYBALLMOTION: 
		{
			OnJoyBall(event->jball.which,event->jball.ball,event->jball.xrel,event->jball.yrel);
			break;
		}

	case SDL_JOYHATMOTION: 
		{
			OnJoyHat(event->jhat.which,event->jhat.hat,event->jhat.value);
			break;
	    }

	case SDL_JOYBUTTONDOWN: 
		{
			OnJoyButtonDown(event->jbutton.which,event->jbutton.button);
			break;
		}

	case SDL_JOYBUTTONUP: 
		{
			OnJoyButtonUp(event->jbutton.which,event->jbutton.button);
			break;
		}
		
		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		//////////////////////     KEYBOARD EVENTS    ////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////// 
	
	
	case SDL_KEYDOWN :
		{
			OnKeyDown(event->key.keysym, event->key.keysym.mod, event->key.keysym.scancode);
			break;
		}

	case SDL_KEYUP :
		{
			OnKeyUp(event->key.keysym, event->key.keysym.mod, event->key.keysym.scancode);
			break;
		}


		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		//////////////////////     MOUSE    EVENTS    ////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////// 

	case SDL_MOUSEMOTION :
		{
			OnMouseMove(event->motion.x, event->motion.y, event->motion.xrel,event->motion.yrel, (event->motion.state&SDL_BUTTON_LEFT)!= 0, (event->motion.state&SDL_BUTTON_RIGHT)!= 0, (event->motion.state&SDL_BUTTON_MIDDLE)!= 0);
			break;
		}

	case SDL_MOUSEBUTTONDOWN :
		{
			switch ( event->button.button)
			{

			case SDL_BUTTON_LEFT:
				{
					OnLButtonDown(event->button.x, event->button.y);
					break;
				}

			case SDL_BUTTON_RIGHT:
				{
					OnRButtonDown(event->button.x, event->button.y);
					break;
				}

			case SDL_BUTTON_MIDDLE :
				{
					OnMButtonDown(event->button.x, event->button.y);
					break;
				}
			}

			break;
		}

		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		//////////////////////     SDL      EVENTS    ////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////

	case SDL_QUIT:
		{
			OnExit();
			break;
		}

	case SDL_SYSWMEVENT:
		{
			break;
		}
	}
}

void PCEvent::OnInputFocus()
{

}

void PCEvent::OnInputBlur()
{

}

void PCEvent::OnMouseFocus()
{

}

void PCEvent::OnMouseMove( int x, int y, int relX, int relY, bool left, bool right, bool middle )
{

}

void PCEvent::OnMouseWheel( bool up, bool down )
{

}

void PCEvent::OnLButtonDown( int x, int y )
{

}

void PCEvent::OnLButtonUp( int x, int y )
{

}

void PCEvent::OnRButtonDown( int x, int y )
{

}

void PCEvent::OnRButtonUp( int x, int y )
{

}

void PCEvent::OnMButtonDown( int x, int y )
{

}

void PCEvent::OnMButtonUp( int x, int y )
{

}

void PCEvent::OnJoyAxis( Uint8 which , Uint8 axis, Sint16 value )
{

}

void PCEvent::OnJoyButtonDown( Uint8 which, Uint8 button )
{

}

void PCEvent::OnJoyButtonUp( Uint8 which, Uint8 button )
{

}

void PCEvent::OnJoyHat( Uint8 which, Uint8 hat, Uint8 value )
{

}

void PCEvent::OnJoyBall( Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel )
{

}

void PCEvent::OnMinimize()
{

}

void PCEvent::OnRestore()
{

}

void PCEvent::OnResize( int w, int h )
{

}

void PCEvent::OnExpose()
{

}

void PCEvent::OnExit()
{

}

void PCEvent::OnUser( Uint8 type, int code, void * data1, void * data2 )
{

}

void PCEvent::OnMouseBlur()
{

}

void PCEvent::OnKeyUp( SDL_Keysym sym, Uint16 mod, SDL_Keycode unicode )
{

}

void PCEvent::OnKeyDown( SDL_Keysym sym, Uint16 mod, SDL_Keycode unicode )
{

}
