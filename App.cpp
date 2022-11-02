#include "framework.h"

App::App()
{
	m_hInstance = NULL;
	m_pPhase = NULL;
}

App::~App()
{
}

// Chargement de la police si elle est bien charg�e
void App::LoadFont()
{
	// Chargement Font
	if (font.loadFromFile("ressource/Front/poorFront.ttf") == false)
	{
		// Check que la police est charg�e
		cout << "Erreur chargement font !" << endl;
	}
	// Cr�ation d'un texte
	sf::Text m_txt;
}

void App::SetText(sf::Text& txt, String str)
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

void App::Init(HINSTANCE hInstance)
{
	// Window
	m_window.create(VideoMode(WNDSIZE_W, WNDSIZE_H), "Titre", sf::Style::Close);
	//Activation du vsync
	m_window.setVerticalSyncEnabled(true);
	// On r�gle toutes les propri�t�s
	//SetText(txt, "Mon texte !"); Ecrire un texte
}

void App::Uninit()
{

}

bool App::HasWindow()
{
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
	//m_window.draw(txt);

	// Dessiner � l'�cran tout les  �l�ments
	m_window.display();
	return true;
}