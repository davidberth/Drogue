#pragma once

#include "tile.h"

short int *world;
Vertex* world_vertices;

int world_width;
int world_height;

void initialize_world(int width, int height);
void destroy_world();
void render_world();