# 1.3 inch LCD HAT

This is an IPS LCD display HAT drivers and instructions for Raspberry Pi, 1.3inch diagonal, 
240x240 pixels, with embedded controller, communicating via SPI interface.

This repo is using the [WaveShare tutorial](https://www.waveshare.com/wiki/1.3inch_LCD_HAT).


## ⚙ How to build it?


- Open terminal, use command to enter the configuration page

    ```
    sudo raspi-config
    Choose Interfacing Options -> SPI -> Yes  to enable SPI interface
    ```
- Reboot Raspberry Pi：

    `sudo reboot`

Please make sure that SPI interface was not used by other devices, you can check in the `/boot/config.txt`.

### �� Install Libraries

- Install BCM2835 libraries

    ```
    wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.68.tar.gz
    tar zxvf bcm2835-1.68.tar.gz 
    cd bcm2835-1.68/
    sudo ./configure && sudo make && sudo make check && sudo make install
    ```

For more details, please refer to http://www.airspayce.com/mikem/bcm2835/.

- Install Python libraries

    ``` 
    sudo apt-get update
    sudo apt-get install ttf-wqy-zenhei
    sudo apt-get install python-pip 
    sudo pip install RPi.GPIO
    sudo pip install spidev
    ```

### �� Use the Examples

Open Raspberry Pi terminal, go to where is located the repository folder and run the following commands:

```
sudo chmod 777 -R 1.3-inch-LCD-HAT
cd 1.3-inch-LCD-HAT
```
    
### ▶ Run the demo

- **`C`**

    ``` 
    cd c
    make clean
    make
    sudo ./main
    ```

- For Raspberry Pi 4B and system version after raspbian_lite-2019-06-20, please set as following for normal input:

    `sudo nano /boot/config.txt`

And then add the following line at the end of the config.txt

`gpio=6,19,5,26,13,21,20,16=pu`


- **`python`**

```
    cd python
    sudo python main.py
    sudo python key_demo.py
```

## FBCP Transplant

The Framebuffer uses a memory area to store the display content, and changes the data in the memory to change the display content.

There is an open-source project on github: `fbcp-ili9341`. Compared with other fbcp projects, this project uses partial refresh and DMA to achieve a refresh rate of up to 60fps