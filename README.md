# masters-htn README

## Installation Dev
sudo apt-get install libsdl1.2-dev  
sudo apt-get install libsdl-image1.2-dev  
sudo apt-get install libsdl-gfx1.2-dev  
sudo apt-get install libsdl-ttf2.0-dev

## Installaion Server
Used non-dev versions.  
sudo apt-get install libsdl1.2debian  
sudo apt-get install libsdl-image1.2  
sudo apt-get install libsdl-ttf2.0-0  
sudo apt-get install libsdl-gfx1.2-5  

Only needed if running on 16.04  
Had to copy the libSDL_gfx.so.13.9.1 to server and make a symbolic link to libSDL_gfx.so.13. Executable couldn't find that file.

## Config.json format
```
{
  "game_type": 0,
  "time_limit": 300000,
  "score_limit": 20,
  "map": "Maps/base.map",
  "iterations": 10,
  "team_one": {
    "ai_type": "R1",
    "num_bots": 9,
    "num_squads": 3,
    "respawn_time": 45
  },
  "team_two": {
    "ai_type": "R1",
    "num_bots": 9,
    "num_squads": 3,
    "respawn_time": 45
  }
}
```


## Running
./masters_fsm -cf config.json 2>&1 | tee Logs/catch-$(date +%Y%m%d_%H%M%S).log
