#include "Graphics.h"
#include <SDL.h>

Graphics::Graphics()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Graphics::CreateWindow(const char* title, int x, int y)
{
    // Create a window
    m_window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        x,
        y,
        SDL_WINDOW_SHOWN);

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

void Graphics::Clear()
{
    SDL_SetRenderDrawColor(m_renderer, 200, 0, 180, 255);
    SDL_RenderClear(m_renderer);
}

void Graphics::Present()
{
    SDL_RenderPresent(m_renderer);
}

void Graphics::SetColor(const glm::vec4& color)
{
    glm::ivec4 icolor;
    icolor.r = (int)(color.r * 255);
    icolor.g = (int)(color.g * 255);
    icolor.b = (int)(color.b * 255);
    icolor.a = (int)(color.a * 255);

    SDL_SetRenderDrawColor(m_renderer, icolor.r, icolor.g, icolor.b, icolor.a);
}

glm::ivec4 Graphics::ConvertColor(const glm::vec4& color)
{
    return glm::ivec4();
}

void Graphics::DrawPoint(const glm::ivec2& point, const glm::vec4& color)
{
    SetColor(color);
    SDL_RenderDrawPoint(m_renderer, point.x, point.y);
}

void Graphics::DrawLine(const glm::ivec2& start, const glm::ivec2& end, const glm::vec4& color)
{

}

void Graphics::DrawCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
}

void Graphics::DrawFilledCircle(const glm::ivec2& point, int radius, const glm::vec4& color)
{
}
