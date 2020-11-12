# BouncingBalls
Bouncing Pong balls on the screen in C++

# Compilation
Make sure you have DOSBox installed and also have OpenWatcom installed.

# Automatic compilation
Just run BUILD.BAT.

# Manual compilation
Run these commands:
```
wpp ball.cpp
wlink name ball.exe file ball.obj
```

# Command line arguments
You can either run ball.exe without any command line arguments or specify how many balls to draw on the screen, eg:
```
ball 15
```
Note: Some large numbers may cause the program to crash as soon as it starts up. The largest numbe of balls I've tested so far that works is 128.
