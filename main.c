#include "my.h"

void if_click(sfRenderWindow* window, sfEvent event)
{
    sfVector2i mousse = sfMouse_getPosition(window);
    if (mousse.x >= 499 && mousse.x <= 624) {
        if (mousse.y >= 287 && mousse.y <= 347) {
            if (event.type == sfEvtMouseButtonPressed)
                level(window, event);
        }
    }
}

int main()
{
    sfVideoMode mode = {1080, 527, 32};
    sfRenderWindow *window;
    sfTexture* texture;
    sfTexture* texture2;
    sfSprite* sprite;
    sfSprite* sprite2;
    sfMusic* music;
    sfFont* font;
    sfText* text;
    sfEvent event;
    sfVector2f position_text = {380, 200};
    sfVector2f position_B1 = {495, 250};
    //window
    window = sfRenderWindow_create(mode, "My hunter", sfResize | sfClose, NULL);
    if (!window)
    return EXIT_FAILURE;
    texture = sfTexture_createFromFile("./wallscreen/b1.jpg", NULL);
    if (!texture)
    return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    //bouton
    texture2 = sfTexture_createFromFile("./wallscreen/B1.png", NULL);
    if (!texture2)
    return EXIT_FAILURE;
    sprite2 = sfSprite_create();
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfSprite_setPosition(sprite2, position_B1);
    //police
    font = sfFont_createFromFile("./police/police.ttf");
    if (!font)
    return EXIT_FAILURE;
    //text
    text = sfText_create();
    sfText_setString(text, "MY HUNTER");
    sfText_setFont(text, font);
    sfText_setPosition(text, position_text);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 50);
    //music
    music = sfMusic_createFromFile("./music/menu.ogg");
    if (!music)
       return EXIT_FAILURE;
    
    //boucle fenetre
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
     while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    }
    if_click(window, event);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawSprite(window, sprite2, NULL);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfText_destroy(text);
    sfFont_destroy(font);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}