from machine import Pin, I2C # type: ignore
from lib.tactile_button import TactileButton
from lib.ssd1306 import ssd1306
import time # type: ignore

oled_needs_update = False

menus = [
    "Page 1",
    "Page 2",
    "Page 3"
]
menu_index = 0

def update_menu_index(index):
    global oled_needs_update, menu_index
    print(f"Old: {menu_index}, New: {index}")
    menu_index = index
    oled_needs_update = True

def on_left_pressed():
    print("Left pressed")

    if menu_index <= 0:
        update_menu_index(len(menus) - 1)
    else:
        update_menu_index(menu_index - 1)

def on_select_pressed():
    print("Select pressed.")

def on_right_pressed():
    print("Right pressed")

    if menu_index >= (len(menus) - 1):
        update_menu_index(0)
    else:
        update_menu_index(menu_index + 1)

PIN_BTN_LEFT=Pin(18, Pin.IN, Pin.PULL_DOWN)
PIN_BTN_SELECT=Pin(17, Pin.IN, Pin.PULL_DOWN)
PIN_BTN_RIGHT=Pin(16, Pin.IN, Pin.PULL_DOWN)

btn_left = TactileButton(PIN_BTN_LEFT, short_press_callback=on_left_pressed)
btn_select = TactileButton(PIN_BTN_SELECT, short_press_callback=on_select_pressed)
btn_right = TactileButton(PIN_BTN_RIGHT, short_press_callback=on_right_pressed)

i2c = I2C(0, scl=Pin(22), sda=Pin(21))
oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

def update_oled():
    global oled_needs_update
    menu_title = menus[menu_index]
    oled.fill(0)
    oled.text(menu_title, 10, 10)
    oled.show()
    oled_needs_update = False

def main():
    delta_time_ms = 0
    last_time_ms = time.time()

    oled_needs_update = True

    while True:
        delta_time_ms = time.ticks_ms() - last_time_ms
        last_time_ms = time.ticks_ms()

        btn_left.update(delta_time_ms)
        btn_select.update(delta_time_ms)
        btn_right.update(delta_time_ms)

        if oled_needs_update:
            update_oled()

        time.sleep_ms(1)

if __name__ == "__main__":
    main()
