# Adafruit Feather M0 WiFi Microcontroller Applications

## Installation

### Mac OSX

Options:
  1. Brew Install

        ```shell
        brew install platformio
        ```

  2. Download and run get-platformio.py

        ```shell
        # Download get-platformio.py
        curl -O https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py

        # Install PlatformIO
        python3 get-platformio.py

        # Set PATH
        export PATH=$PATH:~/.platformio/penv/bin
        ```

### Ubuntu Linux

#### Install Prerequisite Packages

```shell
apt-get install python3-venv
```

Install `99-platformio-udev.rules`.
See : https://docs.platformio.org/page/faq.html#platformio-udev-rules

```shell
sudo service udev restart
```

#### Grant user access to USB device

```shell
sudo usermod -a -G dialout $USER
sudo usermod -a -G plugdev $USER
```
Log out and log back in for change to take effect

#### Install PlatformIO

```shell
curl -O https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py
python3 get-platformio.py
```

#### Set PATH to PlatformIO

```shell
# Add to ~/.bashrc

export PATH=$PATH:~/.platformio/penv/bin
```

## Create and Initialize a New Project

mkdir newappname
cd newappname
pio project init --board adafruit_feather_m0

## Build an Application

```shell
cd appname
make compile
```

## Upload Application to Microcontroller

```shell
cd appname
make compile upload
```

## Application Settings

#### Port Assignment

Edit platformio.ini file

Linux:
```shell
upload_port = /dev/ttyACM*
```

Mac OSX:
```shell
upload_port = /dev/cu.usbmodem*
```

#### Port Monitor Speed

```shell
monitor_speed = 115200
```

## References

- https://www.adafruit.com/product/3010
- https://docs.platformio.org/
- https://docs.platformio.org/en/latest/tutorials/espressif32/arduino_debugging_unit_testing.html
