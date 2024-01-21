module;

#include "constants.h"
import <stdlib.h>;
import <stdio.h>;
import <SDL2/SDL_opengl.h>;

export module world;
import tile;

Vertex* world_vertices;

int world_width;
int world_height;
short int* world;


export void initialize_world(int width, int height)
{
	printf("Initializing world\n");
	world = new short int[width * height];
	world_width = width;
	world_height = height;
	int index = 0;
	if (world)
	{
		for (int j = 0; j < height; ++j)
		{
			for (int i = 0; i < width; ++i)
			{
				int tile_type = rand() % 10;
				
				if (tile_type > 3)
				{
					tile_type = 0;
				}
				world[index] = tile_type;
				++index;
			}
		}
	}
	printf(" Done\n");
}

export void generate_vb()
{
}

export void render_world()
{

	// get the tile start and stop indices in each dimension
	/*
	int sx = (int)(minx / TILE_WIDTH);
	int sy = (int)(miny / TILE_HEIGHT);
	int ex = (int)(maxx / TILE_WIDTH) + 1;
	int ey = (int)(maxy / TILE_HEIGHT) + 1;

	if (sx < 0) sx = 0;
	if (sy < 0) sy = 0;
	if (ex >= world_width) ex = world_width - 1;
	if (ey >= world_height) ey = world_height - 1;
	*/
	glBegin(GL_LINES);
	
	for (int j = 0; j < world_height; ++j)
	{
		for (int i = 0; i < world_width; ++i)
		{
			int idx = j * world_width + i;
			int ti = world[idx];
			//draw_tile((float)i, (float)j, ti);
		}
	}
	glEnd();
	
}

export void destroy_world()
{
	delete world;
}