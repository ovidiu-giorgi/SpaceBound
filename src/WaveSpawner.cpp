#include "WaveSpawner.h"
#include "GameTime.h"
#include "Asteroid.h"

#define INTERVAL 1200
#define WAVE_SIZE 8

WaveSpawner::WaveSpawner() :
  _interval(INTERVAL),
  _waveSize(WAVE_SIZE)
{
  _lastTimeMS = GameTime::GetTimeMS();
}

WaveSpawner::WaveSpawner(int interval, int waveSize) :
  _interval(interval),
  _waveSize(waveSize)
{
  _lastTimeMS = GameTime::GetTimeMS();
}

int WaveSpawner::GetInterval()
{
  return _interval;
}

void WaveSpawner::SetInterval(int interval)
{
  _interval = interval;
}

int WaveSpawner::GetWaveSize()
{
  return _waveSize;
}

void WaveSpawner::SetWaveSize(int waveSize)
{
  _waveSize = waveSize;
}

std::vector<GameObject*> WaveSpawner::GetWave()
{
  std::vector<GameObject*> spawned;

  if (GameTime::GetTimeMS() - _lastTimeMS >= _interval) {
    for (int i = 0; i < _waveSize; ++i) {
      bool found = false;
      while (!found) {
        found = true;
        GameObject* obj = new Asteroid();

        for (auto it : spawned) {
          if (it->Collide(obj)) {
            found = false;
            break;
          }
        }

        if (found) {
          spawned.push_back(obj);
          break;
        } else {
          delete obj;
        }
      }
    }
    _lastTimeMS = GameTime::GetTimeMS();
  }

  return spawned;
}

std::vector<GameObject*> WaveSpawner::GetWave(std::vector<GameObject*> avoid)
{
  std::vector<GameObject*> spawned;

  if (GameTime::GetTimeMS() - _lastTimeMS >= _interval) {
    for (int i = 0; i < _waveSize; ++i) {
      bool found = false;
      while (!found) {
        found = true;

        GameObject* obj = new Asteroid();

        for (auto it : spawned) {
          if (it->Collide(obj)) {
            found = false;
            break;
          }
        }

        if (found) {
          for (auto it : avoid) {
            if (it->Collide(obj)) {
              found = false;
              break;
            }
          }
        }

        if (found) {
          spawned.push_back(obj);
          break;
        } else {
          // delete obj;
        }
      }
    }
    _lastTimeMS = GameTime::GetTimeMS();
  }

  return spawned;
}