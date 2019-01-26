import serial
import keyboard
from keymaps import default as keymap

serial_port_name = "/dev/ttyUSB0"


def main():
    print('Zaladowano. Mozesz zaczac pisac')
    port = serial.Serial(serial_port_name)
    while True:
        msg = int(port.readline()[0:-2].decode('UTF-8'))
        keyboard.press_and_release(keymap[msg])


if __name__ == '__main__':
    main()
