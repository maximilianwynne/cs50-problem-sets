import pygame
import os

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


def draw():
    screen.fill(background_colour)
    screen.blit(background, (0,0))
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
