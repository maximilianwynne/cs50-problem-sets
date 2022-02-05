import pygame

width = 800
height = 600

background_colour = (234, 212, 252)

pygame.init()
width, height = 640, 480
screen = pygame.display.set_mode((800, 600))

pygame.display.set_caption('Mr Dig')

screen.fill(background_colour)
pygame.display.flip()
running = True

# game loop / keep live
while running:
    # loop through event queue
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

# set blank screen
def main():
    pygame.display.init()
    screen = pygame.display.set_mode((800, 600))

class Player(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.images = ['hero.png']

        charimage = pygame.image.load(os.path.join(os.path.sep, 'hero.png')).convert()

def move():
    if event.type == pygame.KEYDOWN:
        if event.key == pygame.K_LEFT or event.key == ord('a'):
            print('left')
        if event.key == pygame.K_RIGHT or event.key == ord('d'):
            print('right')
        if event.key == pygame.K_UP or event.key == ord('w'):
            print('jump')

    if event.type == pygame.KEYUP:
        if event.key == pygame.K_LEFT or event.key == ord('a'):
            print('left stop')
        if event.key == pygame.K_RIGHT or event.key == ord('d'):
            print('right stop')
        if event.key == ord('q' or 'e'):
            pygame.quit()
            main = False

class Hero(Character)
    def __init__(self):
        Character.__init__(self, "Hero")
        self.hurt = pygame.image.load(os.path.join("Assets", "Hero", "digdug_hurt.png")).convert_alpha()
        self.rect = self.surface.get_rect(centre = (WIDTH/2, HEIGHT/2))
        self.xspeed = BASE_SPEED
        self.yspeed = BASE_SPEED
        self.health = BASE_HEALTH

# when character moves
    def move(self):
        # see if keys are being pressed
        pressed_keys = pygame.key.get_pressed()

        if self.rect.left > 0 and pressed_keys[K_LEFT]:
            self.rect.move_ip(-BASE_SPEED, 0):

# draw character frame

# create character / test walks
# i need the actual pngs
class Character(pygame.sprite.Sprite):
    def __init__(self, type):
        super().__init__()
        self.walk_animation = [
            pygame.game.load(os.path.join(type, f"{type}_standing.png")).convert_alpha(),
            pygame.game.load(os.path.join(type, f"{type}_L.png")).convert_alpha(),
            pygame.game.load(os.path.join(type, f"{type}_standing.png")).convert_alpha(),
            pygame.game.load(os.path.join(type, f"{type}_R.png")).convert_alpha(),
        ]
        self.surface = pygame.Surface(100, 150)
        self.direction = 1 #1 is 'right', 0 is 'left'
        self.step_count = 0

#
