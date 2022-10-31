// header.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets
//

#pragma once
#include <SFML/Graphics.hpp>

#include "targetver.h"
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include "Resource.h"

#define WNDSIZE_U							1000
#define WNDSIZE_F							1000.0f
#define GRIDSIZE							100.0f

using namespace std; 

#include "Global.h"
#include "App.h"
#include "Camera.h"
#include "Controller.h"
#include "Enemy.h"
#include "Entity.h"
#include "Entity_manager.h"
#include "Game.h"
#include "Keys.h"
#include "Menu.h"
#include "Phase.h"
#include "Player.h"
#include "State.h"

