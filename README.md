# ChronoStopwatch
This is a simple stopwatch class written in C++ using the ``std::chrono::high_resolution_clock``.

# Usage
```C++
ChronoStopwatch csw;

csw.start(); //starts a timer
//... do stuff ...
std::cout << csw.stop(); //stop returns the last started timer

csw.start();//A
//... do stuff ...
csw.start();//B
//... do other stuff ...
csw.stop(); //stops B
csw.stop(); //stops A

size_t a = csw.start();//A
//... do stuff ...
size_t b = csw.start();//B
//... do other stuff ...
csw.stop();//stops B
csw.start();//C
//... do other stuff ...
csw.stop(a); //stops A
csw.stop(); //stops C
ChronoStopwatch::getFormatDuration(csw.getDuration(b)) //returns the duration of B in the HH:MM:SS.mmmm format
```

# Author
[psychofisch](https://twitter.com/psychofish_ "Twitter")
