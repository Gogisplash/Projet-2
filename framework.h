// header.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets
//

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>    // Include librairie audio SFML


#include "targetver.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <set>
#include "Resource.h"

#define WNDSIZE_H							900
#define WNDSIZE_W							1600
#define RAD2DEG(r)							((r)*57.29577951f)

#define STATE_GAME_START					1
#define STATE_GAME_PLAY						2


#define STATE_GAME_START					1
#define STATE_GAME_PLAY						2

using namespace std; 


#include "Global.h"
#include "State.h"
#include "Phase.h"
#include "Sprite.h"
#include "Animation.h"
#include "Entity.h"
#include "Entity_manager.h"
#include "Camera.h"
#include "Controller.h"
#include "TileMap.h"
#include "Enemy.h"
#include "Player.h"
#include "Keys.h"
#include "Menu.h"
#include "Game.h"
#include "App.h"

