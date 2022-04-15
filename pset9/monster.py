import pygame
from pygame.sprite import Sprite

class Monster(Sprite):
    def __init__(self, screen, x, y):
        super(Monster, self).__init__()
        self.screen = screen
        self.surface = pygame.Surface((30, 30))
        self.surface.fill(self.settings.monster_colour)
        self.rect = self.surface.get_rect()
        self.rect.x, self.rect.y = x, y
        self.x, self.y = self.rect.x, self.rect.y
        self.destiny_number = 50
        self.destiny_right = self.rect.x + self.destiny_number
        self.destiny_left = self.rect.x - self.destiny_number

        self.destiny_top = self.rect.y + self.destiny_number
        self.destiny_bottom = self.rect.y - self.destiny_number
        self.direction_right = "right"
        self.direction_left = "left"
        self.direction_top = "top"

    def move_x(self):

        if self.direction_right == "right":
            if self.rect.x < self.destiny_right:
                self.x = self.x + 1
            else:
                self.direction_right = "left"

        else:
            if self.rect.x > self.destiny_left:
                self.x = self.x - 1
            else:
                self.direction_right = "right"

        self.rect.x = self.x

    def move_y(self):

        if self.direction_top == "top":
            if self.rect.y < self.destiny_top:
                self.y = self.y + 1
            else:
                self.direction_top = "down"

        else:
            if self.rect.y > self.destiny_bottom:
                self.y = self.y - 1
            else:
                self.direction_top = "top"

        self.rect.y = self.y

    def __blit__(self):
        self.screen.blit(self.surface, self.rect)