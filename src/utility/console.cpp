#include "console.h"
#include "utility.h"
#include <iostream>

using namespace std;

CConsole::CConsole()
{
}

CConsole::~CConsole()
{
}

int CConsole::Initialize(InitDesc& desc)
{
    if (m_initialized) {
        return 0;
    }

    m_screen_w = desc.width;
    m_screen_h = desc.height;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }

    // initialize screen
    m_window = SDL_CreateWindow("Hello world !!", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, m_screen_w, m_screen_h, SDL_WINDOW_SHOWN);

    if (m_window == NULL) {
        SDL_Quit();
        return 2;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture  = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STATIC, m_screen_w, m_screen_h);

    if (m_renderer == NULL) {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return 3;
    }

    if (m_texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return 4;
    }

    // prepare memory
    m_buffer = new Uint32[m_screen_w * m_screen_h];
    memset(m_buffer, 0, m_screen_w * m_screen_h * sizeof(Uint32));

    // set every 4bytes as color into memory
    for (int i = 0; i < m_screen_w * m_screen_h; i++) {
        m_buffer[i] = 0x000000FF;
    }

    m_initialized = true;

    return 0;
}

bool CConsole::Run()
{
    if (m_initialized == false) {
        return false;
    }

    // update screen
    SDL_UpdateTexture(m_texture, NULL, m_buffer, m_screen_w * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);

    // update event
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        return false;
    }

    return true;
}

void CConsole::Finalize()
{
    if (m_initialized == false) {
        return;
    }

    SafeDeleteArray(m_buffer);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

    m_renderer    = NULL;
    m_texture     = NULL;
    m_window      = NULL;
    m_screen_w    = 0;
    m_screen_h    = 0;
    m_initialized = false;
}
