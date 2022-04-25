import pygame
import os
import random
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

#! defining the tile size at the beginning
TILE_SIZE = 32

#! it is best to load all images directly in the beginning of the code through pygame.image.load
CHARACTER_SIZE = TILE_SIZE // 1.25
MONSTER = pygame.transform.scale(pygame.image.load("images/monster_standing.png"), (TILE_SIZE, TILE_SIZE)).convert_alpha()
PLAYER = pygame.transform.scale(pygame.image.load("images/player_standing.png"), (TILE_SIZE // 1.15, TILE_SIZE // 1.15)).convert_alpha()

# create character / test walks
# i need the actual pngs
class Character(pygame.sprite.Sprite):
    def __init__(self, type): #! always define the coordinates in the __init__ function
        super().__init__()
        self.walk_animation = [
            pygame.image.load(os.path.join("images", f"{type}_standing.png")).convert_alpha(),
            # pygame.game.load(os.path.join(type, f"{type}_L.png")).convert_alpha(),
            # pygame.game.load(os.path.join(type, f"{type}_standing.png")).convert_alpha(),
            # pygame.game.load(os.path.join(type, f"{type}_R.png")).convert_alpha(),
        ]
        self.walk_animation[0].set_colorkey((20, 20, 20))
        self.image = self.walk_animation[0]

    def update(self):
        # self.image = self.walk_animation[0]
        pass

class Player(Character):
    def __init__(self, x, y, img=PLAYER):
        Character.__init__(self, "player")
        # self.hurt = pygame.image.load(os.path.join("Assets", "Hero", "digdug_still.png")).convert_alpha()
        self.speed = 1
        #!
        self.x = x
        self.y = y
        self.img = img
        self.vel = 2 #! how fast the player moves
        self.rect = pygame.Rect(self.x, self.y, self.img.get_width(), self.img.get_height())
        self.can_move_down = True
        #!
        # resize character
        scaled_image = pygame.Surface([level.tile_size, level.tile_size])
        pygame.transform.scale(self.image, (level.tile_size,level.tile_size), scaled_image)
        self.image = scaled_image
        self.rect2 = self.image.get_rect()

    def update2(self): #! your function
        
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

    def draw(self): #! it is best to always draw such objects through an internal draw function which just blits the images at the given coordinates onto the screen
        screen.blit(self.img, (self.x, self.y)) #! you can also add animations to this later, if you are confused with something, just ask me

    def update(self): #! my updated function
        if not self.can_move_down: #! this is a little bit more efficient but also a little bit longer to write
            self.can_move_down = True
        self.rect = pygame.Rect(self.x, self.y, self.img.get_width(), self.img.get_height())
        keys = pygame.key.get_pressed()

        for x, row in enumerate(level.map): #! normal checking for collision
            for y, tile in enumerate(row):
                if tile != None:
                    if tile.is_obstacle:
                        rect = pygame.Rect(self.rect.x, self.rect.y + self.vel, self.rect.width, self.rect.height) #! new rect for future collision checking
                    else:
                        rect = self.rect
                    if rect.colliderect(tile.rect): #! no mask collision because rects work just fine too
                        if tile.is_obstacle:
                            self.can_move_down = False #! if player will collide with obstacle then he cant move in that direction (down)
                        else:
                            level.map[x][y] = None

        if self.x % level.tile_size >= 0 and self.x % TILE_SIZE <= TILE_SIZE - self.img.get_width(): #! same as your function, just changed the movement a litle bit
            if keys[pygame.K_UP]:
                self.y -= self.vel #! changing x, y directly, not in rect
                if self.y < 0:
                    self.y += self.vel
            elif keys[pygame.K_DOWN]:
                if self.can_move_down:
                    self.y += self.vel
                    if self.y > HEIGHT:
                        self.y -= self.vel
        if self.y % level.tile_size >= 0 and self.y % TILE_SIZE <= TILE_SIZE - self.img.get_height():
            if keys[pygame.K_RIGHT]:
                self.x += self.vel
                if self.x > WIDTH:
                    self.x -= self.vel
            elif keys[pygame.K_LEFT]:
                self.x -= self.vel
                if self.x < 0:
                    self.x += self.vel



class Monster(pygame.sprite.Sprite): #! your monster
    def __init__(self, pos):
        super().__init__()
        self.image = pygame.image.load(os.path.join("images","monster_standing.png")).convert_alpha()
        scaled_image = pygame.Surface([level.tile_size, level.tile_size])
        pygame.transform.scale(self.image, (level.tile_size, level.tile_size), scaled_image)
        self.image = scaled_image
        self.rect = self.image.get_rect()
        self.rect.x = pos[0]
        self.rect.y = pos[1]

        self.dir_x = 1
        self.dir_y = 1

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

        new_rect = self.rect.copy()
        new_rect.y += self.dir_y

        for column in level.map:
            for column_i in range(len(row)):
                tile = column[column_i]
                if tile is not None and new_rect.colliderect(tile):
                    new_rect = self.rect.copy()
                    break

        if new_rect == self.rect:
            self.dir_y = -self.dir_y

        self.rect = new_rect


class Monster2: #! my updated monster
    def __init__(self, x, y, movementx, movementy, img=MONSTER):
        self.x = x
        self.y = y
        self.ix = x
        self.iy = y
        self.movementx = movementx
        self.movementy = movementy
        self.img = img
        self.rect = pygame.Rect(self.x, self.y, self.img.get_width(), self.img.get_height())

    def draw(self):
        screen.blit(self.img, (self.x, self.y))
    
    def move(self): #! moving directly through coordinates
        self.x += self.movementx
        self.y += self.movementy
        self.rect = pygame.Rect(self.x, self.y, self.img.get_width(), self.img.get_height())

        for x, row in enumerate(level.map):
            for y, tile in enumerate(row):
                if tile != None:
                    if self.rect.colliderect(tile.rect):
                        self.movementx = - self.movementx

        if self.x >= WIDTH - self.img.get_width() and self.movementx > 0 or self.x <= 0 and self.movementx < 0:
            self.movementx = - self.movementx

        if self.y >= HEIGHT - self.img.get_height()  and self.movementy > 0 or self.y <= 0 and self.movementy < 0:
            self.movementy = - self.movementy


    def offset(self, target): #! checking offset and moving based on it
        offsetx = self.ix - target.x
        offsety = self.iy - target.y
        if offsetx <= TILE_SIZE * 4 and offsetx > 0 and offsety <= TILE_SIZE * 3 and offsety > -TILE_SIZE * 4:
            if offsety > 0:
                multi = -offsety
            else:
                multi = offsety
            if self.x >= self.ix + TILE_SIZE * 1.5 + ((offsetx - TILE_SIZE * 4) // 2) - ((multi - TILE_SIZE * 4) // 10) and self.movementx > 0:
                self.movementx = -self.movementx
        if offsetx >= -TILE_SIZE * 4 and offsetx < 0 and offsety <= TILE_SIZE * 3 and offsety > -TILE_SIZE * 4:
            if self.x <= self.ix + TILE_SIZE and self.movementx < 0:
                self.movementx = -self.movementx

        return offsetx, offsety

    def player_collision(self, player):
        if self.rect.colliderect(player.rect):
            return True

        return False


# implementing tiles
class Tile(): #! I wont change the class here, there is nothing to change here, really.
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
        self.filename = filename
        self.map = self.load(self.filename)

    # display all tiles for each row
    def draw(self):
        for row in self.map:
            for tile in row:
                if tile is not None:
                    tile.draw(screen)

    def load(self, filename): #! I am too tired to rewrite a part of that now
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
                        x = tile_size_original * (number % 6) #! this is rather not efficient but since you run that only once in your code its fine
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
    screen.fill((0, 0, 0))
    #screen.fill(background_colour)
    #screen.blit(background, (0,0))
    level.draw()
    monster.draw()
    player.draw()
    pygame.display.flip()

next_obstacle = HEIGHT
for row in level.map:
    for tile in row:
        if tile != None:
            if tile.is_obstacle:
                next_obstacle = tile.rect.y
                break

player = Player(CHARACTER_SIZE // 8, CHARACTER_SIZE // 8)
monsterx = random.randrange(0, WIDTH - TILE_SIZE * 3, TILE_SIZE)
monstery = random.randrange(0, next_obstacle - TILE_SIZE * 3, TILE_SIZE)
monster = Monster2(monsterx, monstery, 1, 0)

level.map[0][0] = None
for x, row in enumerate(level.map):
    for y, tile in enumerate(row):
        if tile != None:
            if tile.rect.x == monsterx and tile.rect.y == monstery:
                level.map[x][y] = None
                if monster.movementy != 0:
                    level.map[x + 1][y] = level.map[x + 2][y] = None
                elif monster.movementx != 0:
                    level.map[x][y + 1] = level.map[x][y + 2] = None

clock = pygame.time.Clock()


running = True

# game loop / keep live
while running:
    clock.tick(60)
    #!
    player.update()
    monster.move()
    monster.offset(player)
    #!
    # loop through event queue
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False


    if monster.player_collision(player): #! game over if player collides with monster
        running = False

    draw()
