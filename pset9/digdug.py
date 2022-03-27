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
        self.direction = -1 #-1 is 'right', 0 is 'left'
        self.step_count = 0
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
        if keys[pygame.K_UP] or keys[pygame.K_DOWN]:
            input_x = 1 if keys[pygame.K_DOWN] else -1
        input_y = 0
        if keys[pygame.K_LEFT] or keys[pygame.K_RIGHT]:
            input_y = 1 if keys[pygame.K_RIGHT] else -1
        if self.rect.x % level.tile_size == 0:
            # pressing down, input y = 1 - add 1 * 1 = speed
            self.rect.y += input_y * self.speed
        if self.rect.y % level.tile_size == 0:
            # pressing up, input x = 1 + add 1 // 1 = speed
            self.rect.x -= input_x // self.speed

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
        self.tile_size = 32
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
                        tile_row.append(Tile(tile_surface_scaled, screen_x, screen_y))
                    screen_x += self.tile_size
                map.append(tile_row)
                screen_y += self.tile_size
        return map


level = TileMap("map.csv")


# create black tiling
def create_black_ground(settings,screen,player,type):
    for x in range(15,45):
        x = x * 20
        for y in range(15,35):
            y = y * 20
            cell = map(x,y,settings,screen)
            map.add(cell)

    for item in map.sprites():
        if item.rect.x == 400 and item.rect.y == 520:
            map.remove(item)

        if item.rect.x == 400 and item.rect.y == 500:
            map.remove(item)


# make player collision
#def check_ground_collision(self, player):
    #collided = pygame.sprite.spritecollideany(player, map)
    #if collided:
        #self.remove(collided)

    # collision result
    #if player.colliderect(player_rect):
        #game_active = False
    #else:
        #screen.fill('Red')

    # mouse_pos = pygame.mouse.get_pos()
    # if player_rect.collidepoint(mouse_pos):
        # print(pygame.mouse.get_pressed())

    pygame.display.update()


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
