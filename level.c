#include "my.h"
#include "struct.h"
void my_putnbr(int nb);
void my_putchar(char c);

void Spriteres(sfMouseButtonEvent event, sfVector2f *position,
sfRenderWindow *window, struct_t *score)
{
	int i = rand() % 400 + 10;
	if (event.x >= position->x && event.x <= position->x + 222 &&
	event.y >= position->y && event.y <= position->y + 145)
	{
		position->x = -200;
		position->y = i;
		score->score = score->score + 10;
		score->i += 1;
	} else if (score->vie > 0) {
		score->vie = score->vie - 1;
	}
	if (score->vie == 0) {
		sfRenderWindow_close(window);
	}
}

void evt_SpritePressed(sfRenderWindow *window, sfEvent event, sfVector2f *position,
struct_t *score)
{
	sfRenderWindow_setFramerateLimit(window, 60);
	while (sfRenderWindow_pollEvent(window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		if (event.type == sfEvtMouseButtonPressed)
			Spriteres(event.mouseButton, position, window,
			score);
	}
}

struct_t bonus_score(void)
{
	struct_t score;
	score.score = 0;
	score.vie = 3;
	score.i = 4;
	return (score);
}

int set_position_S(sfVector2f *position, int i)
{
	position->x += i;
	if (position->x >= 1800) {
		i = -i;
	}
	if (position->x <= -200) {
		i = -i;
	}
	return (i);
}

sfVector2f position_S(sfVector2f position)
{
	int i = rand() % 400 + 10;
	position.x = -200;
	position.y = i;
	return (position);
}

void level(sfRenderWindow* window, sfEvent event)
{
    sfTexture *texturelvl = sfTexture_createFromFile("./wallscreen/lvl1.png", NULL);
    sfSprite *spritelvl = sfSprite_create();
    sfTexture *texturelvl2 = sfTexture_createFromFile("./sprite/p1.png", NULL);
    sfSprite *spritelvl2 = sfSprite_create();
    sfVector2f position = position_S(position);
    sfMusic* musiclvl = sfMusic_createFromFile("./music/menu.ogg");;
    sfClock *clock = sfClock_create();
    struct_t score = bonus_score();
    sfTime time;
    float temps;
    sfSprite_setTexture(spritelvl, texturelvl, sfTrue);
    sfSprite_setTexture(spritelvl2, texturelvl2, sfTrue);
    sfMusic_play(musiclvl);

    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        temps = time.microseconds / 100000.0;
        if (temps > 1) {
			sfClock_restart(clock);
		}
		score.i = set_position_S(&position, score.i);
        evt_SpritePressed(window, event, &position, &score);
     while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, spritelvl, NULL);
    sfRenderWindow_drawSprite(window, spritelvl2, NULL);
    sfSprite_setPosition(spritelvl2, position);
    sfRenderWindow_display(window);
    }
    sfMusic_destroy(musiclvl);
    sfSprite_destroy(spritelvl);
    sfTexture_destroy(texturelvl);
    sfSprite_destroy(spritelvl2);
    sfTexture_destroy(texturelvl2);
    sfRenderWindow_destroy(window);
}