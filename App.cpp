#include "framework.h"

//const sf::Color sf::Color::Cyan;
//const sf::Color sf::Color::Black;

// Protopytes
void LoadFont();

void SetText(sf::Text &txt, String str);

sf::Font font;

App::App()
{
	m_hInstance = NULL;
	m_pPhase = NULL;
}

App::~App()
{
}

void App::Init(HINSTANCE hInstance)
{
	// Window
	m_window.create(VideoMode(WNDSIZE_W, WNDSIZE_H), "Titre", sf::Style::Close);

	//Activation du vsync
	m_window.setVerticalSyncEnabled(true);

}

void App::Uninit(){}

bool App::HasWindow()
{
	// Chargement Font
	LoadFont();
	// Création d'un texte
	sf::Text txt;
	// On règle toutes les propriétés
	SetText(txt, "Mon texte !");


	//--------------
	if (m_window.isOpen() == false)
		return false;

	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return false;
		}
	}
	// Couleur de la fenêtre
	m_window.clear(sf::Color::Black);

	// Dessiner à l'écran
	m_window.draw(txt);

	// Dessiner à l'écran tout les  éléments
	m_window.display();
	return true;
}

// Chargement de la police si elle est bien chargée
void LoadFont()
{
	if (font.loadFromFile("x64/Debug/res/poorFront.ttf") == false)
	{
		//assert(0);
		// Check que la police est chargée
		cout << "Erreur chargement font !" << endl;
		//WriteConsoleOutputW()
	}
}

void SetText(sf::Text &txt, String str )
{
	// Indication de la bonne police
	txt.setFont(font);
	// chaine de string
	txt.setString(str);
	// On indique la taille
	txt.setCharacterSize(26);
	// On donne la couleur
	txt.setFillColor(sf::Color::Cyan);
	// Modif du style
	txt.setStyle(Text::Bold | Text::Underlined);
}