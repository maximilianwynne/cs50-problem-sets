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
clock = pygame.time.Clock()

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
        self.image = self.walk_animation[0]

    def update(self):
        # self.image = self.walk_animation[0]
        pass

class Player(Character):
    def __init__(self):
        Character.__init__(self, "player")
        # self.hurt = pygame.image.load(os.path.join("Assets", "Hero", "digdug_still.png")).convert_alpha()
        self.speed = 1
        # resize character
        scaled_image = pygame.Surface([level.tile_size, level.tile_size])
        pygame.transform.scale(self.image, (level.tile_size,level.tile_size), scaled_image)
        self.image = scaled_image
        self.rect = self.image.get_rect()

    def update(self):
        # see if keys are being pressed
        keys = pygame.key.get_pressed()
        # check alignment with tile
        input_x = 0
        input_y = 0
        if keys[pygame.K_UP] or keys[pygame.K_DOWN]:
            input_y = 1 if keys[pygame.K_DOWN] else -1
        if keys[pygame.K_LEFT] or keys[pygame.K_RIGHT]:
            input_x = 1 if keys[pygame.K_RIGHT] else -1

        new_rect = self.rect.copy()

        # are we aligned with a column?
        if new_rect.x % level.tile_size == 0:
            # vertical movement
            new_rect.y += input_y * self.speed

        # are we aligned with a row?
        if new_rect.y % level.tile_size == 0:
            # horizontal movement
            new_rect.x += input_x * self.speed

        # check for collisions
        # row in tiled map
        for row in level.map:
            # selecting tiles
            for row_i in range(len(row)):
                tile = row[row_i]
                # if tile exists and you collide. if tile is dirt, remove dirt tile.
                if tile is not None and new_rect.colliderect(tile):
                    if tile.is_obstacle:
                        new_rect = self.rect.copy()
                    elif tile.is_dirt:
                        row[row_i] = None

        self.rect = new_rect

        super().update()

class Monster(pygame.sprite.Sprite):
    def __init__(self, pos):
        super().__init__()
        self.image = pygame.image.load(os.path.join("images","player_standing.png")).convert_alpha()
        scaled_image = pygame.Surface([level.tile_size, level.tile_size])
        pygame.transform.scale(self.image, (level.tile_size, level.tile_size), scaled_image)
        self.image = scaled_image
        self.rect = self.image.get_rect()
        self.rect.x = pos[0]
        self.rect.y = pos[1]

        self.dir_x = 1

    def update(self):
        new_rect = self.rect.copy()
        new_rect.x += self.dir_x

        for row in level.map:
            # selecting tiles
            for row_i in range(len(row)):
                tile = row[row_i]
                # if tile exists and you collide. if tile is dirt, remove dirt tile.
                if tile is not None and new_rect.colliderect(tile):
                    new_rect = self.rect.copy()
                    break

        # turn around when hitting obstacle
        if new_rect == self.rect:
            self.dir_x = -self.dir_x

        self.rect = new_rect



# implementing tiles
class Tile(pygame.sprite.Sprite):
    def __init__(self, image, x, y, is_obstacle, is_dirt):
        self.image = image
        # manual load in: self.image = pygame.image.Load(image)
        self.rect = self.image.get_rect()
        self.rect.x, self.rect.y = x, y
        self.is_obstacle = is_obstacle
        self.is_dirt = is_dirt

    # helper function: draw the tile
    def draw(self, surface):
        surface.blit(self.image, (self.rect.x, self.rect.y))


class TileMap():
    def __init__(self, filename):
        # initialise tile size
        self.tile_size = 32
        # self.map_w, self.map_h = x * self.tile_size, y * self.tile_size
        self.start_x, self.start_y = 0, 0
        self.tile_img = pygame.image.load("tile.png")
        self.map = self.load(filename)

    # display all tiles for each row
    def draw(self):
        for row in self.map:
            for tile in row:
                if tile is not None:
                    tile.draw(screen)

    def load(self, filename):
        tile_size_original = 16
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
                        x = tile_size_original * (number % 6)
                        y = tile_size_original * (number // 6)
                        tile_surface_original = pygame.surface.Surface((tile_size_original,tile_size_original))
                        tile_surface_scaled = pygame.surface.Surface((self.tile_size, self.tile_size))
                        tile_surface_original.blit(self.tile_img, (0, 0), Rect(x,y,tile_size_original,tile_size_original))
                        pygame.transform.scale(tile_surface_original, (self.tile_size,self.tile_size),tile_surface_scaled)
                        is_obstacle = number == 21 or 24 <= number <= 45
                        is_dirt = not is_obstacle
                        tile_row.append(Tile(tile_surface_scaled, screen_x, screen_y, is_obstacle, is_dirt))
                    else:
                        tile_row.append(None)
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
sprites.add(Monster((64,64)))

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
