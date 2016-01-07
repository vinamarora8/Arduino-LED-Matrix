# Arduino-LED-Matrix

I made this for my dad's birthday. It's shown in this video https://www.facebook.com/savita.arora.75/videos/732964460170406/

I made a circuit for this which include a matrix of LEDs. A matrix is required to decrease the number of I/O pins required to control the circuit through the Arduino. If I would have connected the LEDs directly, I would need 175 I/O pins while in a matrix arrangement only 32 pins are required. This is also a high number. To reduce this, I use serial data to parallel data converters (called shift registers) which reduces the number of I/O pins to 5.

Now, to control these shift-registers we need serial and clock data which I provide through the I/O pins of an arduino. This required some programming which is shown in code.ino file. To show things on the display you also have to use tricks like cascading of columns.

The program I made makes it easy to make anything on the board.  For example, to make a letter 'H' you have to enter a design in the array made of 1's and 0's :

1 1 1 1 1 1 1 <br/>
0 0 0 1 0 0 0 <br/>
0 0 0 1 0 0 0 <br/>
0 0 0 1 0 0 0 <br/>
1 1 1 1 1 1 1 <br/>

Here are some more images of my project: https://drive.google.com/folderview?id=0B7vuRfvcCVVeXzVFd2JSbWs4Wms&usp=sharing

Also, this was my first project with an arduino and shift-registers.
