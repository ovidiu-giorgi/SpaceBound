#ifndef WAVESPAWNER_H
#define WAVESPAWNER_H

#include "GameObject.h"

#include <vector>

class WaveSpawner
{
public:
  WaveSpawner();
  WaveSpawner(int interval, int waveSize);
  ~WaveSpawner();

  int GetInterval();
  void SetInterval(int interval);

  int GetWaveSize();
  void SetWaveSize(int waveSize);
  
  std::vector<GameObject*> GetWave();

  /*
  Variant of the GetWave function that receives a vector
  of game objects that are to be avoided when spawning
  new ones.
  */
  std::vector<GameObject*> GetWave(std::vector<GameObject*> avoid);
  
private:
  uint32_t _lastTimeMS;
  int _interval;
  int _waveSize;
};

#endif