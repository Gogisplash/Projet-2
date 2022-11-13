#pragma once
class Menu : public Phase
{
public:
    enum
    {
        // State menus

        STATE_MAIN = 0,     // Ecran principal (menu) initialisé à 0
        STATE_SETTINGS,
        STATE_CREDITS,

        // Fonctionnalités du menu (main).

        MAIN_START_GAME = 0,
        MAIN_SETTINGS,
        MAIN_CREDITS,
        MAIN_QUIT,

        // Foncitonnalités du menu (settings)

        MUSIC_OFF = 0,
        MUSIC_ON,

    };
   Menu();
   virtual ~Menu();

   virtual int GetID() { return MENU; }

   void Init();
   void Uninit();
   void UpdateButtons();                   // Mise à jour des boutons lors du déplacement

   virtual void OnEnter(int oldState);
   virtual void OnExit(int newState);
   virtual void OnExecute();
   virtual void OnExecuteMain();           // Déclarer la fonction d'éxécution de l'écran Main
   virtual void OnExecuteSettings();           // Déclarer la fonction d'éxécution de l'écran Settings
   virtual void OnUpdate();
   virtual void OnRender(sf::RenderTexture& rt);

   int GetPressedItem() { return selectedItemIndex; }      // Définir le choix de l'utilisateur dans le menu et retourner son choix

protected:

    int selectedItemIndex;                                  // Définir type du choix dans le menu (nombre entier)
    int m_maxItems;                                         // Définir type du nombre max de catégorie dans le menu (nombre entier)
    int m_maxSettings;                                      // Définir type du nombre max d'option  dans le Settings (nombre entier)

    // Création des classes SFML

    sf::Sprite m_sprite;
    sf::Text m_menu[MAX_NUMBER_OF_ITEMS];                   // Création texte et tableau pour le nombre max d'item dans le menu via SFML
    sf::Text m_settings[MAX_NUMBER_OF_ITEMS];               // Création texte et tableau pour le nombre max d'item dans le settings via SFML
    sf::Font m_font;
};

