#include "Opengl.hpp"
#include "Camera.hpp"
#include "Axes.hpp"
#include "Cube_drawer.hpp"
#include "User_input.hpp"

#include <iostream>
#define WIDTH 640
#define HEIGHT 480

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *screen;
  screen = SDL_CreateWindow("Rubic's  window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, /*SDL_WINDOW_FULLSCREEN |*/ SDL_WINDOW_OPENGL);
  SDL_GL_CreateContext(screen);

  Opengl opgl;
  Camera cam;
  Cube_drawer primitive;

  User_input ui(WIDTH, HEIGHT);
  opgl.opengl_init(WIDTH, HEIGHT);
  
  bool running = true;
  while (running) {
    ui.input_handler(running);
    opgl.opengl_sreenbuilder();
    cam.place_camera();
    cam.rotate_camera(ui.get_angle_x(), ui.get_angle_z());
    ///primitive.generate_tile_net(ui.get_repeat());
    //primitive.generate_map(-1, ui.get_repeat(), 0, 0, 'x', 0);
    primitive.draw_flattened_cube();

    opgl.opengl_display(screen);
  }

  SDL_Quit();
  return 0;
}