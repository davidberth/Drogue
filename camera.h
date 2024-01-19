#pragma once

struct Camera
{
	float x;
	float y;
	float zoom;
	float rotation;
};

Camera camera;


void initialize_camera();
void set_camera_pos(float x, float y);
void set_camera_rotation(float rt);
void add_zoom(float z);
void camera_view(int window_width, int window_height);