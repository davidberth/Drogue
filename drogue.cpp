#include <SDL2/SDL.h>
#include <SDL2/SDL_Opengl.h>
#include <SDL2/SDL_main.h>
#include <Windows.h>

#include <print>
#include <string>
#include <sstream>

#include "constants.h"


import world;
import tile;
import camera;

void print_information()
{
    std::println(PROJECT_NAME);
   
    std::println("Major Version {}", MAJOR_VERSION);
    std::println("Minor Version {}", MINOR_VERSION);
    std::string opengl_version = (const char*)glGetString(GL_VERSION);
    std::println("OPENGL Version {}", opengl_version);
    
}

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    SDL_DisplayMode DM;
    SDL_GetDesktopDisplayMode(0, &DM);

    std::stringstream buffer;

    int screen_width = DM.w;
    int screen_height = DM.h;

    int window_width = (int)(screen_width * WINDOW_WIDTH_RATIO);
    int window_height = (int)(screen_height * WINDOW_HEIGHT_RATIO);

    int window_startx = (int)((screen_width - window_width) / 2);
    int window_starty = (int)((screen_height - window_height) / 2);

    int32_t WindowFlags = SDL_WINDOW_OPENGL;

    
    SDL_Window* window = SDL_CreateWindow(PROJECT_NAME,
        window_startx, window_starty, 
        window_width, window_height, WindowFlags);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    buffer << PROJECT_NAME << " " << MAJOR_VERSION << ":" <<
        MINOR_VERSION << " OpenGL: " << 
        reinterpret_cast<const char*>(glGetString(GL_VERSION)) << 
        std::endl;

    bool fullscreen = false;
    bool running = true;
    SDL_SetWindowTitle(window,
        buffer.str().c_str());

    initialize_tiles();
    initialize_world(WORLD_WIDTH, WORLD_HEIGHT);

    initialize_camera();


    while (running)
    {
        SDL_Event Event;
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_KEYDOWN)
            {
                switch (Event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case 'f':
                    fullscreen = !fullscreen;
                    if (fullscreen)
                    {
                        SDL_SetWindowFullscreen(window, 
                            WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    else
                    {
                        SDL_SetWindowFullscreen(window, WindowFlags);
                    }
                    break;
                default:
                    break;
                }
            }
            else if (Event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        camera_view(window_width, window_height);
        render_world();

        SDL_GL_SwapWindow(window);

    }
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

    destroy_world();
    cleanup_tiles();

    return EXIT_SUCCESS;
}




