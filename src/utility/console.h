#pragma once
#include "SDL.h"
#include <stdio.h>

class CConsole
{
public:
	struct InitDesc {
		int width  = 640;
		int height = 480;
	};

public:
	CConsole();
	~CConsole();

	int  Initialize(InitDesc& desc);
	void Finalize();
	bool Run();

private:
	bool          m_initialized = false;
	int           m_screen_w    = 0;
	int           m_screen_h    = 0;
	Uint32*       m_buffer      = NULL;
	SDL_Renderer* m_renderer    = NULL;
	SDL_Texture*  m_texture     = NULL;
	SDL_Window*   m_window      = NULL;
};
