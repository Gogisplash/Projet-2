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
	// Cr�ation d'un texte
	sf::Text txt;
	// On r�gle toutes les propri�t�s
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
	// Couleur de la fen�tre
	m_window.clear(sf::Color::Black);

	// Dessiner � l'�cran
	m_window.draw(txt);

	// Dessiner � l'�cran tout les  �l�ments
	m_window.display();
	return true;
}

// Chargement de la police si elle est bien charg�e
void LoadFont()
{
	if (font.loadFromFile("x64/Debug/res/poorFront.ttf") == false)
	{
		//assert(0);
		// Check que la police est charg�e
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