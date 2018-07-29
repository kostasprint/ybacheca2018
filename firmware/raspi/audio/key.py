from pynput import keyboard
import pygame
import sys
import pygame.locals
import time


pygame.init()
pygame.mixer.music.load("Doorbell.WAV")



def on_press(key):
    try: k = key.char # single-char keys
    except: k = key.name # other keys
    if key == keyboard.Key.esc: return False # stop listener
    if k in ['1', '2', 'left', 'right','k']: # keys interested
        # self.keys.append(k) # store ikgkt in global-like variable
        print('Key pressed: ' + k)
        pygame.mixer.music.play()


lis = keyboard.Listener(on_press=on_press)
lis.start()
lis.join() 
