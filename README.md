# stm32morse
This repository documents the details of Morse Code Transmitter project on an STM32F103C8T6 MCU using STM32CubeIDE, an open-source C/C++ development platform 
for STM32 microcontrollers and microprocessors.

In this project, we are required to transmit 3 different letters in Morse Code which represent 3 group members using the STM32. Since our group only consists of 2 members, we transmit two different letters in Morse Code repeatedly. We use the letters “AI” to represent our group members as the name of our first group member is Ashraf Aminin which starts with the letter “A” and the letter “I” for our second group member, Izzat. By using the STM32F103C8T6, stm32morse utilizes the onboard LED connected to the GPIOD - PIN 13 to transmit Morse Code. Even though we only need to transmit 2 letters, the project that we build supports 26 alphabets and 10 numerals to make it flexible. A C code is included in this repository for reference.

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

stm32morse follows the rules of Morse Code shown in the diagram above in which we are using 200ms for 1 unit. Shown in the following table is the duration for the morse that we implement in the stm32morse.
| Duration | Time (ms) |
| --------------- | --------------- |
| Dot | Row 1 Column 2 |
| Dash | Row 2 Column 2 |
|  | Row 3 Column 2 |

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
1. Understanding morse code: https://www.britannica.com/topic/Morse-Code
