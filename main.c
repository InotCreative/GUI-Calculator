#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    WNDCLASS windowProperties; // Properties of the window
    MSG message; // Message object
    HWND hWindow; // Main window handle

    // Initialize windowProperties class structures
    ZeroMemory(&windowProperties, sizeof(WNDCLASS)); // Initialize enough memor for the windowProperty and sets the memory to 0

    windowProperties.style = CS_HREDRAW | CS_VREDRAW; 
    windowProperties.lpfnWndProc = (WNDPROC)DefWindowProc; // Pointer to the window procedure for this window class
    windowProperties.hInstance = hInstance;
    windowProperties.hCursor = LoadCursor(NULL, IDC_ARROW); // Makes mouse visible on the window
    windowProperties.hbrBackground = (HBRUSH)(COLOR_BACKGROUND); // Sets the backgroud color of the window
    windowProperties.lpszClassName = "MyFirstWindow"; // Nmae of the class

    /*
    Defines the properties of the window object such as coloe.
    */

    if (RegisterClass(&windowProperties) == 0) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;

        /*
        Error Check to dtermine if the class could be registered, it not, display a message box printing
        the error.
        */
    }

    hWindow = CreateWindowEx(WS_EX_CLIENTEDGE,
                          "MyFirstWindow", 
                          /* 
                          As the class was named above to 'MyFirstWindow', the API knows the name of the class
                          that was just registerd, so, use the registed class to create a window that has those
                          class properties.
                          */   
                          "Photo To ASCII", // Name of the window on the top
                           WS_OVERLAPPEDWINDOW, // Style Parameter
                           CW_USEDEFAULT, 
                           CW_USEDEFAULT,
                           640, // Creates the length of the window
                           520, // Creates the width of the window
                           NULL,
                           NULL,
                           hInstance,
                           NULL);
    
    if(hWindow == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;

        /*
        If the window can't be made, create a message box that displays an error message.
        */
    }

    ShowWindow(hWindow, nShowCmd);
    UpdateWindow(hWindow);

    while(GetMessage(&message, NULL, 0, 0) > 0) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
    return 0;
}