#pragma once
class Menu : public Phase
{
public:
    enum
    {
        // State menus

        STATE_MAIN = 0,     // Ecran principal (menu) initialis? ? 0
        STATE_SETTINGS,
        STATE_CREDITS,

        // Fonctionnalit?s du menu (main).

        MAIN_START_GAME = 0,
        MAIN_SETTINGS,
        MAIN_CREDITS,
        MAIN_QUIT,

        // Foncitonnalit?s du menu (settings)

        MUSIC_OFF = 0,
        MUSIC_ON,

    };
   Menu();
   virtual ~Menu();

   virtual int GetID() { return MENU; }

   void Init();
   void Uninit();
   void UpdateButtons();                   // Mise ? jour des boutons lors du d?placement

   virtual void OnEnter(int oldState);
   virtual void OnExit(int newState);
   virtual void OnExecute();
   virtual void OnExecuteMain();           // D?clarer la fonction d'?x?cution de l'?cran Main
   virtual void OnExecuteSettings();           // D?clarer la fonction d'?x?cution de l'?cran Settings
   virtual void OnUpdate();
   virtual void OnRender(sf::RenderTexture& rt);

   int GetPressedItem() { return selectedItemIndex; }      // D?finir le choix de l'utilisateur dans le menu et retourner son choix

protected:

    int selectedItemIndex;                                  // D?finir type du choix dans le menu (nombre entier)
    int m_maxItems;                                         // D?finir type du nombre max de cat?gorie dans le menu (nombre entier)
    int m_maxSettings;                                      // D?finir type du nombre max d'option  dans le Settings (nombre entier)

    // Cr?ation des classes SFML

    sf::Sprite m_sprite;
    sf::Text m_menu[MAX_NUMBER_OF_ITEMS];                   // Cr?ation texte et tableau pour le nombre max d'item dans le menu via SFML
    sf::Text m_settings[MAX_NUMBER_OF_ITEMS];               // Cr?ation texte et tableau pour le nombre max d'item dans le settings via SFML
    sf::Font m_font;
};

