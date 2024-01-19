#include "player.h"
#include "camera.h"
#include "constants.h"
#include "rlgl.h"
#include "raymath.h"

void render_player()
{
	Vector2 v1 = { 0.0f, 0.0f - PLAYER_SIZE};
	Vector2 v2 = { -PLAYER_SIZE, PLAYER_SIZE };
	Vector2 v3 = { PLAYER_SIZE, PLAYER_SIZE };

	Vector2 pl = { player.x, player.y };
	//pl = GetWorldToScreen2D(pl, camera);
	rlPushMatrix();

	rlTranslatef(player.x, player.y, 0.0f);
	rlRotatef(-player.heading, 0.0f, 0.0f, 1.0f);
	DrawTriangleLines(v1, v2, v3, RED);

	rlPopMatrix();
	
}

void initialize_player()
{
	player.x = 50.0f;
	player.y = 50.0f;
}

void move_player(float x, float y)
{
	Vector2 fr = { 0.0f, -1.0f };
	Vector2 rt = { 1.0f, 0.0f };
	Vector2 forward = Vector2Rotate(fr, -3.1415f * player.heading / 180.0f);
	Vector2 right = Vector2Rotate(rt, -3.1415f * player.heading / 180.0f);

	player.x += forward.x * y;
	player.y += forward.y * y;

	player.x += right.x * x;
	player.y += right.y * x;
	
}
