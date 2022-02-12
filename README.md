# CPP-Project-SDL2-

Recreating jetpack joyride but with a twist!

## Screenshots
![Screenshot 2022-02-12 at 13-08-02 Report - Report _cp_grp28 pdf](https://user-images.githubusercontent.com/77527524/153702100-d86a7825-cea1-4fa4-9180-024897168c66.png)
![Screenshot 2022-02-12 at 13-08-19 Report - Report _cp_grp28 pdf](https://user-images.githubusercontent.com/77527524/153702098-d8afba97-8708-4d4c-a175-237b691423c5.png)
![Screenshot 2022-02-12 at 13-08-41 Report - Report _cp_grp28 pdf](https://user-images.githubusercontent.com/77527524/153702096-238aef28-d4bc-4040-bf0e-39345f0e5a3d.png)

## Controls
- <kbd> space </kbd> to jump
- <kbd> enter </kbd> to shoot bullets

## Installing the requirements
- Install a c++ compiler like `g++`.

### Install SDL
#### Linux ([Official Guide](https://wiki.libsdl.org/Installation)):
Install with :
```sh
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-mixer-dev
```
Include the following files :
```cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
```

#### Windows
Refer to [this tutorial](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php) to set up SDL on Windows.
Include the following files :
```cpp
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
```

## How to run
Simply clone the repository and run make.
```sh
git clone https://github.com/harsha-deep/CPP-Project-SDL2-.git
cd CPP-Project-SDL2-/
make
./a.out
```

