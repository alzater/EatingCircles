#pragma once

using namespace oxygine;

enum Hardness_enum {easy, hard};

struct GameSettings{
  int level;
  Hardness_enum hardness;
  int num_of_bots, num_of_stars;
};

struct GameResults{
  int levelPassed;
  int eated;
  float score;
  
  GameResults(int l, int e, float sc):
    levelPassed(l),
    eated(e),
    score(sc)
  {}
};
