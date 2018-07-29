import pygame, sys
import pygame.locals
import time

pygame.init()

pygame.mixer.music.load("Doorbell.mp3")

while True:
    for event in pygame.event.get():
        if event.key == pygame.K_p:
             pygame.mixer.music.play()#Do what you want to here
             pass
        if event.type == pygame.locals.QUIT:
             pygame.quit()
             sys.exit()

pygame.mixer.music.play()

time.sleep(10)
