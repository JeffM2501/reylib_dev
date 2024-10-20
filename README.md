
**reylib is a simple and easy-to-use library to help people get into game developent**

reylib is highly inspired by raylib by Ramon Santamaria (@raysan5).

*NOTE for New Users: reylib is a code centric library for people who enjoy programming; It is not an engine, it has no fancy interface, no visual helpers, no debug button... just coding. Do not underestimate the work required*

---

Goals
-----
reylib is designed to be similar to raylib but using the SDL3 library to provide better cross platform support, as well as graphics API abstractions.
The reylib API is designed to be simple and easy to learn, but also contains more advanced options to allow people to grow.
Where the raylib API has basic and then 'pro' versions of functions, reylib reverses the concept, it contains API functions that take many options for advanced users as a default, and then has 'simple' versions of the functions for new users.
The reylib API is also designed to be modular and make it easy to include only the speific features that you need. This includes support for various file formats. A few basic formts are incldued in the core system, with other formats able to be droped in via extra headers.


Features
--------
  - C17 
  - Optional C++ extensions for common strucures
  - Uses the SDL3 backend for cross plaform compatability
  - Supports callback and game loop application styles
  - Prefixes to prevent conflicts
  - Modular file formats
  - **Free and open source**

Basic example
--------------
Work In Progress
```c
#include "reylib.h"

int main()
{

    rlInitAppSimple(800, 600, "TestWindow-loop", 0);
    
    // setup resources

    while (!rlWantExit())
    {
        rlBeginFrame();


        // update game

        // render game
        rlClearBackground(BLACK);
        rlEndFrame();
    }
    // cleanup resources

    rlShutdown();

}
```

build and installation
----------------------
reylib is currently only using a MSVC project file. It will be swapped over to premake at some point.


license
-------
reylib is licensed under an unmodified zlib/libpng license, which is an OSI-certified, BSD-like license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.
