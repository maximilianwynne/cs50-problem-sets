import pygame
import os
import csv
from pygame.rect import Rect

WIDTH = 800
HEIGHT = 600

background_colour = (234, 212, 252)
background = pygame.image.load("background.png")

pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))

pygame.display.set_caption('Dig Dug')

# create character / test walks
# i need the actual pngs
class Character(pygame.sprite.Sprite):
    def __init__(self, type):
        super().__init__()
        self.walk_animation = [
            pygame.image.load(os.path.join("images", f"{type}_standing.png")).convert_alpha(),
            # pygame.game.load(os.path.join(type, f"{type}_L.png")).convert_alpha(),
            # pygame.game.load(os.path.join(type, f"{type}_standing.png")).convert_alpha(),
            # pygame.game.load(os.path.join(type, f"{type}_R.png")).convert_alpha(),
        ]
        self.direction = 1 #1 is 'right', 0 is 'left'
        self.step_count = 0

    def update(self):
        self.image = self.walk_animation[0]

class Player(Character):
    def __init__(self):
        Character.__init__(self, "player")
        # self.hurt = pygame.image.load(os.path.join("Assets", "Hero", "digdug_still.png")).convert_alpha()
        self.rect = pygame.rect.Rect(100, 100, 50, 80)
        self.speed = 5

    def update(self):
        # see if keys are being pressed
        keys = pygame.key.get_pressed()
        if keys[pygame.K_UP]:
            self.rect.y -= self.speed
            backgroundcoord = 1
        if keys[pygame.K_DOWN]:
            self.rect.y += self.speed
        if keys[pygame.K_LEFT]:
            self.rect.x -= self.speed
        if keys[pygame.K_RIGHT]:
            self.rect.x += self.speed
        super().update()


# implementing tiles
class Tile(pygame.sprite.Sprite):
    def __init__(self, image, x, y):
        self.image = image
        pygame.sprite.Sprite.__init__(self)
        # manual load in: self.image = pygame.image.Load(image)
        self.rect = self.image.get_rect()
        self.rect.x, self.rect.y = x, y

    # helper function: draw the tile
    def draw(self, surface):
        surface.blit(self.image, (self.rect.x, self.rect.y))

class TileMap():
    def __init__(self, filename):
        # initialise tile size
        self.tile_size = 16
        # self.map_w, self.map_h = x * self.tile_size, y * self.tile_size
        self.start_x, self.start_y = 0, 0
        self.tile_img = pygame.image.load("tile.png")
        self.map = self.load(filename)

    # display all tiles for each row
    def draw(self):
        for row in self.map:
            for tile in row:
                tile.draw(screen)

    def load(self, filename):
        map = []
        with open(os.path.join(filename)) as file:
            data = csv.reader(file, delimiter=',')
            screen_y = self.start_y
            for row in data:
                screen_x = self.start_x
                tile_row = []
                for number in row:
                    number = int(number)
                    if number >= 0:
                        # get image corresponding from tile
                        x = self.tile_size * (number % 6)
                        y = self.tile_size * (number // 6)
                        tile_surface = pygame.surface.Surface((self.tile_size, self.tile_size))
                        tile_surface.blit(self.tile_img, (0, 0), Rect(x,y,self.tile_size,self.tile_size))
                        tile_row.append(Tile(tile_surface, screen_x, screen_y))
                    screen_x += self.tile_size
                map.append(tile_row)
                screen_y += self.tile_size
        return map

level = TileMap("map.csv")

def draw():
    screen.fill(background_colour)
    screen.blit(background, (0,0))
    level.draw()
    sprites.draw(screen)
    pygame.display.flip()


sprites = pygame.sprite.Group()
sprites.add(Player())

clock = pygame.time.Clock()

running = True

# game loop / keep live
while running:
    clock.tick(60)

    # loop through event queue
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    sprites.update()

    draw()
