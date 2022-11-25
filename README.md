# stm32morse
This repository documents the details of Morse Code Transmitter project on an STM32F103C8T6 MCU using STM32CubeIDE, an open-source C/C++ development platform 
for STM32 microcontrollers and microprocessors.

We are required to program an STM32 MCU using open-source STM32CubeIDE in C language, so that the MCU blinks with a set interval corresponding to English alphabets 
in morse code. A C code is included in this repository for reference.

stm32morse contains the project that blinks an LED in responds to morse code from GPIOD - PIN 13 on the STM32F103C8T6.

<br/>

## Group Members (Driven Raven)
1. Ashraf Aminin bin Arman Alim
2. Izzat bin Idris

<br/>

## Project Prerequisites
1. STM32CubeIDE software
2. STM32 MCU

<br/>

## Understanding Morse Code 
The term Morse Code refers to either of two systems for representing letters of the alphabet, numerals, 
and punctuation marks by an arrangement of dots, dashes, and spaces. The codes are transmitted as electrical pulses 
of varied lengths or analogous mechanical or visual signals, such as flashing lights. 

![International_Morse_Code svg](https://user-images.githubusercontent.com/106621749/203897053-ebaad372-c052-4523-bc2b-d10e3b098975.png)

*Chart of the Morse code 26 letters and 10 numerals*

*Picture taken from [Wikipedia](https://en.wikipedia.org/wiki/Morse_code)*

<br/>

## Project Procedures
The procedures in this project is the exact same procedures done in this [repository](https://github.com/izzat138/stm32blinky) with the exception of the code 
used to program the STM32 MCU.

<br/>

# Project Demo

https://user-images.githubusercontent.com/106621749/203897294-4d677aeb-59d1-4c65-ba1b-8481b422ad20.mp4

*Youtube URL: https://youtu.be/DnbRLYfcMog*

<br/>
<br/>

# Reflections

This basic STM32 project creation facilitates us to understand the capabilities and utilities provided by STM32CubeIDE to program an STM32 MCU. 
This repository can be referred for any future project creations.

In addition, counterfeit ST-LINK is an ongoing issue being investigated by STMicroelectronics. In the recent releases of STM32CubeIDE, 
a counter measure is made by STMicroelectronics to prevent the programming of an STM32 MCU with a counterfeit ST-LINK. However, to overcome the difficulty 
of finding and owning an actual ST-LINK, STM32 ST-LINK Utility can be used to program STM32 MCU instead with a cloned ST-LINK.

<br/>
<br/>

# References
