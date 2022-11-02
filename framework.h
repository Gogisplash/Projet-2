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

#define WNDSIZE_H							900
#define WNDSIZE_W							1600

using namespace sf;
using namespace std; 


#include "Global.h"
#include "State.h"
#include "Phase.h"
#include "Entity.h"
#include "Entity_manager.h"
#include "Controller.h"
#include "Camera.h"
#include "Enemy.h"
#include "Keys.h"
#include "Player.h"
#include "Game.h"
#include "Menu.h"
#include "App.h"

