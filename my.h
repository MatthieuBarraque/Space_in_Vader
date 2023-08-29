/*
** EPITECH PROJECT, 2022
** my.H
** File description:
** my.H
*/

#ifndef MY_H_
    # define MY_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window/Mouse.h>
    #include <stdio.h>
    #include <SFML/Audio.h>

    void level(sfRenderWindow* window, sfEvent event);
    void my_putnbr(int nb);
    void my_putchar(char c);

#endif