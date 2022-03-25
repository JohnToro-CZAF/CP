from sense_hat import SenseHat
from random import randint, random, choice
import time
from time import sleep

GRID_SIZE = 8
SLEEP_TIME = 1
y = (255, 255, 0)
b = (0, 0, 0)
r = (255, 0, 0)
g = (0, 255, 0)
GRID = [b for _ in range(GRID_SIZE**2)]
cornors = [(0, 0), (0, 7), (7, 0), (7, 7)]
rotation = [0,90,180,270]
match = {'0': (0, -1), '90': (0,0), '180': (0,1), '270': (-1,0)}
def randomColorAndPosition():
    return ((randint(0, 255), randint(0, 255), randint(0, 255)), (randint(0, 7), randint(0,7)))

def generate(color):
    image_pixels = [b, b, b, b, b, b, b, b,
                     b, b, b, 'x', b, b, b, b,
                     b, b, 'x', 'x', 'x', b, b, b,
                     b, 'x', b, 'x', b, 'x', b, b,
                     b, b, b, 'x', b, b, b, b,
                     b, b, b, 'x', b, b, b, b,
                     b, b, b, 'x', b, b, b, b, 
                     b, b, b, b, b, b, b, b]
                     
    for i in range(len(image_pixels)):
        if image_pixels[i] == 'x':
            image_pixels[i] = color
    return image_pixels
# This is solution to exercise 5a
def a():
    sense = SenseHat()
    sense.set_pixels(GRID)
    x = 0
    colorAndPosition = []
    while x != 4:
        positions = [p[1] for p in colorAndPosition]
        t = randomColorAndPosition()
        if(t[1] in positions): continue
        # If the generated position is the same with the other positions then it will randomly choose
        # the poistion again 
        else:
            colorAndPosition.append(t)
            x += 1
    for i in cornors:
        sense.set_pixel(i[0], i[1], colorAndPosition[cornors.index(i)][0])
    sleep(SLEEP_TIME)
    sense.set_pixels(GRID)
    for i in colorAndPosition:
        sense.set_pixel(i[1][0], i[1][1], i[0])
    sleep(SLEEP_TIME)
    sense.clear()
    return

# This is solution to exercise 5b, 5c
# It will randomly choose 4 rotation and 4 different image with the same pattern but different color
def bc():
    sense = SenseHat()
    sense.set_pixels(GRID)
    sleep(SLEEP_TIME)
    for i in range(4):
        color = (randint(0, 255), randint(0, 255), randint(0, 255))
        sense.set_rotation(choice(rotation))
        sense.set_pixels(generate(color))
        sleep(SLEEP_TIME)
    sense.clear()
    return
# This is solution to exercise 5d
def d():
    sense = SenseHat()
    win = True
    num = 0
    allowTime = 1
    while win:
      angle = choice(rotation)
      sense.set_rotation(angle)
      sense.set_pixels(generate(g))
      time_end = time.time() + allowTime
      while time.time() < time_end:
        raw = sense.get_accelerometer_raw()
        x = round(raw['x'])
        y = round(raw['y'])
        # z = round(raw['z'])
        rota = match[str(angle)]
        if rota == (x, y):
          win = True
          print("You won")
          allowTime -= 0.1
          num += 1
          break
      else: 
        win = False
        sense.set_pixels(generate(r))
        print("You lost")
        sense.show_message("You won "+ str(num))
        return
      sleep(SLEEP_TIME)
      sense.clear()
    return

def main():
    while True:
        print("There are 3 functions for 4 exercises, named 'a', 'bc', 'd', Which's function you wanna choose ?")
        fun = input("Type your function name: ")
        if fun == 'a':
            a()
        if fun == 'bc':
            bc()
        if fun == 'd':
            d()
if __name__ == "__main__":
    main()



