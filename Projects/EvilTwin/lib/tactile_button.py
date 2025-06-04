from machine import Pin # type: ignore

class TactileButton:
    def __init__(self, pin: Pin, short_press_callback = None, long_press_callback = None, long_press_trigger_ms=3000):
        self.pin = pin

        self.short_press_callback = short_press_callback
        self.long_press_callback = long_press_callback

        self.long_press_timer_ms = 0
        self.long_press_trigger_ms = long_press_trigger_ms

        self.long_press_triggered = False
        self.prev_press_state = 0

    def is_pressed(self):
        return self.pin.value() != 0

    def is_released(self):
        return self.pin.value() == 0 and self.prev_press_state == 1 and not self.long_press_triggered

    def is_long_pressed(self):
        return self.pin.value() != 0 and self.long_press_timer_ms >= self.long_press_trigger_ms and not self.long_press_triggered

    def update(self, delta_time_ms):
        if self.is_long_pressed() and self.long_press_callback != None:
            self.long_press_callback()
            self.long_press_triggered = True

        if self.is_released() and self.short_press_callback != None:
            self.short_press_callback()

        if self.is_pressed():
            self.long_press_timer_ms += delta_time_ms
        else:
            self.long_press_timer_ms = 0
            self.long_press_triggered = False

        self.prev_press_state = self.pin.value()