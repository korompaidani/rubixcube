#include "cube.h"

Cube::Cube() {
  srand(time(NULL));
  random_shuffle();
}

void Cube::random_shuffle() {
  for (int i = 0; i < 20; i++) {
    int which_rotation = rand() % 6;
    switch (which_rotation) {
    case 0:
      rotate_front();
      cout << ",F ";
      break;
    case 1:
      rotate_up();
      cout << ",U ";
      break;
    case 2:
      rotate_back();
      cout << ",B ";
      break;
    case 3:
      rotate_down();
      cout << ",D ";
      break;
    case 4 :
      rotate_left();
      cout << ",L ";
      break;
    case 5:
      rotate_right();
      cout << ",R ";
      break;
    }
  }
}

void Cube::fill_faces_to_cube() {
  faces_of_cube.clear();
  faces_of_cube.push_back(front);
  faces_of_cube.push_back(right);
  faces_of_cube.push_back(back);
  faces_of_cube.push_back(left);
  faces_of_cube.push_back(up);  
  faces_of_cube.push_back(down);  
}

void Cube::rotate_front() {
  trackback.push_back('F');
  int temp = front[0];
  front[0] = front[6];
  front[6] = front[8];
  front[8] = front[2];
  front[2] = temp;
  temp = front[1];
  front[1] = front[3];
  front[3] = front[7];
  front[7] = front[5];
  front[5] = temp;

  int temp0 = up[6];
  int temp1 = up[7];
  int temp2 = up[8];
  up[6] = left[8];
  up[7] = left[5];
  up[8] = left[2];
  left[2] = down[0];
  left[5] = down[1];
  left[8] = down[2];
  down[0] = right[6];
  down[1] = right[3];
  down[2] = right[0];
  right[0] = temp0;
  right[3] = temp1;
  right[6] = temp2;
}

void Cube::rotate_up() {
  trackback.push_back('U');
  int temp = up[0];
  up[0] = up[6];
  up[6] = up[8];
  up[8] = up[2];
  up[2] = temp;
  temp = up[1];
  up[1] = up[3];
  up[3] = up[7];
  up[7] = up[5];
  up[5] = temp;

  int temp0 = back[0];
  int temp1 = back[1];
  int temp2 = back[2];
  back[0] = left[0];
  back[1] = left[1];
  back[2] = left[2];
  left[0] = front[0];
  left[1] = front[1];
  left[2] = front[2];
  front[0] = right[0];
  front[1] = right[1];
  front[2] = right[2];
  right[0] = temp0;
  right[1] = temp1;
  right[2] = temp2;
}

void Cube::rotate_back() {
  trackback.push_back('B');
  int temp = back[0];
  back[0] = back[6];
  back[6] = back[8];
  back[8] = back[2];
  back[2] = temp;
  temp = back[1];
  back[1] = back[3];
  back[3] = back[7];
  back[7] = back[5];
  back[5] = temp;

  int temp0 = up[2];
  int temp1 = up[1];
  int temp2 = up[0];
  up[2] = right[8];
  up[1] = right[5];
  up[0] = right[2];
  right[8] = down[6];
  right[5] = down[7];
  right[2] = down[8];
  down[6] = left[0];
  down[7] = left[3];
  down[8] = left[6];
  left[0] = temp0;
  left[3] = temp1;
  left[6] = temp2;
}

void Cube::rotate_down() {
  trackback.push_back('D');
  int temp = down[0];
  down[0] = down[6];
  down[6] = down[8];
  down[8] = down[2];
  down[2] = temp;
  temp = down[1];
  down[1] = down[3];
  down[3] = down[7];
  down[7] = down[5];
  down[5] = temp;

  int temp0 = front[6];
  int temp1 = front[7];
  int temp2 = front[8];
  front[6] = left[6];
  front[7] = left[7];
  front[8] = left[8];
  left[6] = back[6];
  left[7] = back[7];
  left[8] = back[8];
  back[6] = right[6];
  back[7] = right[7];
  back[8] = right[8];
  right[6] = temp0;
  right[7] = temp1;
  right[8] = temp2;
}

void Cube::rotate_right() {
  trackback.push_back('R');
  int temp = right[0];
  right[0] = right[6];
  right[6] = right[8];
  right[8] = right[2];
  right[2] = temp;
  temp = right[1];
  right[1] = right[3];
  right[3] = right[7];
  right[7] = right[5];
  right[5] = temp;

  int temp0 = up[8];
  int temp1 = up[5];
  int temp2 = up[2];
  up[8] = front[8];
  up[5] = front[5];
  up[2] = front[2];
  front[8] = down[8];
  front[5] = down[5];
  front[2] = down[2];
  down[8] = back[0];
  down[5] = back[3];
  down[2] = back[6];
  back[0] = temp0;
  back[3] = temp1;
  back[6] = temp2;
}

void Cube::rotate_left() {
  trackback.push_back('L');
  int temp = left[0];
  left[0] = left[6];
  left[6] = left[8];
  left[8] = left[2];
  left[2] = temp;
  temp = left[1];
  left[1] = left[3];
  left[3] = left[7];
  left[7] = left[5];
  left[5] = temp;

  int temp0 = up[0];
  int temp1 = up[3];
  int temp2 = up[6];
  up[0] = back[8];
  up[3] = back[5];
  up[6] = back[2];
  back[8] = down[0];
  back[5] = down[3];
  back[2] = down[6];
  down[0] = front[0];
  down[3] = front[3];
  down[6] = front[6];
  front[0] = temp0;
  front[3] = temp1;
  front[6] = temp2;
}

void Cube::draw_cube() {
  fill_faces_to_cube();
  for (unsigned int i = 0; i < faces_of_cube.size(); i++) {
    for (unsigned int j = 0; j < faces_of_cube[i].size(); j++) {
      if (j % 3 == 0) {
        cout << endl;
      }
      cout << faces_of_cube[i][j] << " ";
    }
    cout << endl << endl;
  }
}

bool Cube::is_ready() {
  fill_faces_to_cube();
  for (int j = 0; j < faces_of_cube.size(); j++) {
    for (int i = 0; i < faces_of_cube[j].size(); i++) {
      if (faces_of_cube[j][i] != faces_of_cube[j][4]) {
        return false;
      }
    }
  }
  return true;
}

vector<int> Cube::get_vector_for_Lego() {
  fill_faces_to_cube();
  vector<int> for_lego;
  for (unsigned int i = 0; i < faces_of_cube.size(); i++) {
    for (unsigned int j = 0; j < faces_of_cube[i].size(); j++) {
      for_lego.push_back(faces_of_cube[i][j]);
    }
  }
  return for_lego;
}

Cube::~Cube() {
}
  
