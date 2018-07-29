import pygame
import sys
import pygame.locals
import time
import click
pygame.init()
pygame.mixer.music.load("Doorbell.WAV")
while True:
    key = click.getchar()
    if key=="k":
        print(key)
        pygame.mixer.music.play()


time.sleep(20)
