#pragma once
#include "SDL.h"
#include <stdio.h>

class CConsole
{
public:
	struct InitDesc {
		int width  = 800;
		int height = 600;
	};

public:
	CConsole();
	~CConsole();

	int  Initialize(InitDesc& desc);
	void Finalize();
	bool Run();

private:
	bool          m_initialized = false;
	Uint32*       m_buffer      = NULL;
	SDL_Renderer* m_renderer    = NULL;
	SDL_Texture*  m_texture     = NULL;
	SDL_Window*   m_window      = NULL;
};
