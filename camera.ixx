module;

#include "constants.h"
#include <SDL2/SDL_opengl.h>

export module camera;

export struct Camera
{
	float x;
	float y;
	float zoom;
	float rotation;
};

export Camera camera;


export void initialize_camera()
{
	camera.x = 10.0f;
	camera.y = 10.0f;
	camera.zoom = 15.0f;
	camera.rotation = 0.0f;
}

export void set_camera_rotation(float rt)
{
	camera.rotation = rt;
}

export void move_camera(float x, float y)
{
	camera.x += x;
	camera.y += y;
}

export void set_camera_pos(float x, float y)
{

	camera.x = x;
	camera.y = y;
}

export void add_zoom(float z)
{
	camera.zoom += z;
}

export void camera_view(int window_width, int window_height)
{
	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, window_width / camera.zoom, 0, window_height / camera.zoom, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

