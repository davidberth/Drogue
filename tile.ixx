export module tile;

import <SDL2/SDL_opengl.h>;
import <stdio.h>;
import <stdlib.h>;

import "constants.h";


float tile_reds[] = { 0.0f, 0.7f, 0.0f, 0.0f };
float tile_greens[] = { 0.0f, 0.0f, 0.7f, 0.0f };
float tile_blues[] = { 0.0f, 0.0f, 0.0f, 0.7f };

const int num_tiles = 4;

struct LineSegment
{
	float x1;
	float x2;
	float y1;
	float y2;

	float r;
	float g;
	float b;

	float lw;
};

struct Tile
{
	LineSegment* ls;
	short int number_of_lines;
	bool collide;
};

export struct Vertex {
	float x, y;
	float r, g, b;
};

export Tile* tiles;

export void initialize_tiles()
{
	tiles = new Tile[num_tiles];
	tiles[0].ls = NULL;
	tiles[0].number_of_lines = 0;
	for (int i = 1; i < num_tiles; ++i)
	{
		tiles[i].ls = new LineSegment[4];
		tiles[i].number_of_lines = 4;
		tiles[i].ls[0].x1 = 0.05f;
		tiles[i].ls[0].y1 = 0.05f;
		tiles[i].ls[0].x2 = 0.95f;
		tiles[i].ls[0].y2 = 0.05f;

		tiles[i].ls[1].x1 = 0.95f;
		tiles[i].ls[1].y1 = 0.05f;
		tiles[i].ls[1].x2 = 0.95f;
		tiles[i].ls[1].y2 = 0.95f;

		tiles[i].ls[2].x1 = 0.95f;
		tiles[i].ls[2].y1 = 0.95f;
		tiles[i].ls[2].x2 = 0.05f;
		tiles[i].ls[2].y2 = 0.95f;

		tiles[i].ls[3].x1 = 0.05f;
		tiles[i].ls[3].y1 = 0.95f;
		tiles[i].ls[3].x2 = 0.05f;
		tiles[i].ls[3].y2 = 0.05f;

		for (int j = 0; j < 4; ++j)
		{
			tiles[i].ls[j].r = tile_reds[i];
			tiles[i].ls[j].g = tile_greens[i];
			tiles[i].ls[j].b = tile_blues[i];
		}

	}

}

export void draw_tile(float x, float y, int ti)
{
	if (tiles[ti].ls != NULL)
	{
		//printf("drawing tile at %i, %i \n", x, y);
		Tile* tl = &tiles[ti];

		for (int j = 0; j < 4; ++j)
		{
			LineSegment* ls = &tl->ls[j];

			glColor3f(ls->r, ls->g, ls->b);
			glVertex2f(ls->x1 + x, ls->y1 + y);
			glVertex2f(ls->x2 + x, ls->y2 + y);
		}

	}
}

export int get_num_vertices(int ti)
{
	return tiles[ti].number_of_lines * 2;
}


export void cleanup_tiles()
{
	for (int i = 1; i < num_tiles; ++i)
	{
		delete tiles[i].ls;
	}
	delete tiles;
}
