#pragma once

#include <stdbool.h>



void initialize_tiles();
void cleanup_tiles();
void add_vertices_to_buffer(float x, float y, int ti);

typedef struct 
{
	float x1;
	float x2;
	float y1;
	float y2;

	float r;
	float g;
	float b;

	float lw;
} LineSegment;

typedef struct 
{
	LineSegment* ls;
	short int number_of_lines;
	bool collide;
} Tile;

typedef struct {
	float x, y; 
	float r, g, b; 
} Vertex;

Tile *tiles;