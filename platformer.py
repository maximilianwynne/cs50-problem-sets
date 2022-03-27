import pygame
from sys import exit

def display_score():
    current_time = int(pygame.time.get_ticks() / 1000) - start_time
    score_surf = test_font.render(f'Time: {current_time}',False,(64,64,64))
    score_rect = score_surf.get_rect(center = (400,50))
    screen.blit(score_surf,score_rect)


pygame.init()
screen = pygame.display.set_mode((800, 400))
pygame.display.set_caption('Runner')
clock = pygame.time.Clock()
# correcting font / font type, font size
test_font = pygame.font.Font('Pixeltype.ttf', 50)
game_active = False
start_time = 0

sky_surface = pygame.image.load('sky.png').convert()
ground_surface = pygame.image.load('ground.png').convert()
# text info / anti-alias / colour

# score_surf = test_font.render('my game', False, (64, 64, 64))
# centre score text by using rectangles
# score_rect = score_surf.get_rect(center=(400, 50))

# set alpha values, respect white and black
snail_surf = pygame.image.load('snail1.png').convert_alpha()
snail_rect = snail_surf.get_rect(bottomright=(600, 300))

player_surf = pygame.image.load('player_walk_1.png').convert_alpha()
player_rect = player_surf.get_rect(midbottom=(80, 300))
player_gravity = 0

# intro screen
player_stand = pygame.image.load('player_stand.png').convert_alpha()
player_stand = pygame.transform.rotozoom(player_stand,0,2)
player_stand_rect = player_stand.get_rect(center = (400,200))

def create_surface_with_text(text, font_size, text_rgb, bg_rgb):
    """ Returns surface with text written on """
    font = pygame.freetype.SysFont("Runner", font_size, bold=True)
    return surface.convert_alpha()


while True:
    for event in pygame.event.get() :
        if event.type == pygame.QUIT :
            pygame.quit()
            exit()
        # make character jump when clicked on
        # check for mouse button press
        if game_active:
            if event.type == pygame.MOUSEBUTTONDOWN:
                if player_rect.collidepoint(event.pos) and player_rect.bottom >= 300:
                    player_gravity = -20
            # check mouse position
            # check if mouse is over player rectangle
            # if event.type == pygame.MOUSEMOTION:
            # if player_rect.collidepoint(event.pos): print('collision')
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and player_rect.bottom >= 300:
                    player_gravity = -20
        else:
            # restart game
            if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
                game_active = True
                snail_rect.left = 800
                start_time = int(pygame.time.get_ticks() / 1000)

    if game_active:
        screen.blit(sky_surface, (0, 0))
        screen.blit(ground_surface, (0, 300))
        # draw rectangle
        # pygame.draw.rect(screen, '#c0e8ec', score_rect)
        # pygame.draw.rect(screen, '#c0e8ec', score_rect, 10)
        # pygame.draw.ellipse(screen,'Brown',pygame.Rect(50,200,100,100))
        # pygame.draw.line(screen,'Gold',(0,0),pygame.mouse.get_pos(),10)
        # screen.blit(score_surf, score_rect)
        display_score()

        snail_rect.x -= 4
        # move back to right of screen
        if snail_rect.right <= 0 : snail_rect.left = 800
        screen.blit(snail_surf, snail_rect)

        # player
        player_gravity += 1
        player_rect.y += player_gravity
        # keep player grounded, keep above 300
        if player_rect.bottom >= 300 : player_rect.bottom = 300
        screen.blit(player_surf, player_rect)

        # collision
        if snail_rect.colliderect(player_rect):
            game_active = False
    else:
        screen.fill((94,129,162))
        screen.blit(player_stand,player_stand_rect)


    mouse_pos = pygame.mouse.get_pos()
    if player_rect.collidepoint(mouse_pos):
        print(pygame.mouse.get_pressed())

    pygame.display.update()
    clock.tick(60)
