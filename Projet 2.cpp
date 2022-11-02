// Projet 2.cpp : Définit le point d'entrée de l'application.
//
#include "framework.h"

App* g_pApp = NULL;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int  nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

#ifdef _DEBUG
    _CrtMemState memStateInit;
    _CrtMemCheckpoint(&memStateInit);
#endif

    g_pApp = new App;
    g_pApp->Init(hInstance);
    while (g_pApp->HasWindow())
    {
       
    }
    g_pApp->Uninit();
    delete g_pApp;


#ifdef _DEBUG
    _CrtMemState memStateEnd, memStateDiff;
    _CrtMemCheckpoint(&memStateEnd);
    if (_CrtMemDifference(&memStateDiff, &memStateInit, &memStateEnd))
    {
        //MessageBoxA(NULL, "MEMORY LEAKS", "DISCLAIMER", 0);
    }
#endif 

    return 0;
}