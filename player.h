
struct Player
{
	float x;
	float y;
	float heading;
};

struct Player player;

void render_player();

void initialize_player();

void move_player(float x, float y);