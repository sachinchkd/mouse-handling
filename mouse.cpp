
#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char* argv[]){

    // Create a window data type
    // This pointer will point to the 
    // window that is allocated from SDL_CreateWindow
    SDL_Window* window=nullptr;
    SDL_Surface *windowSurface = nullptr;
    SDL_Surface *image1 = nullptr;
    SDL_Surface *image2 = nullptr;
    SDL_Surface *currentImage = nullptr;

    // Initialize the video subsystem.
    SDL_Init(SDL_INIT_VIDEO);

    // Request a window to be created for our platform
    // The parameters are for the title, x and y position,
    // and the width and height of the window.
    window = SDL_CreateWindow("SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN);
    windowSurface = SDL_GetWindowSurface(window);


    image1 = SDL_LoadBMP("image1.bmp");
    image2 = SDL_LoadBMP("image2.bmp");

    currentImage = image1;
    
    // Infinite loop for our application
    bool gameIsRunning = true;
    while(gameIsRunning){
        SDL_Event event;
        // Start our event loop
        while(SDL_PollEvent(&event)!=0){
            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning= false;
            }

            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
               
                if(event.button.button == SDL_BUTTON_LEFT)
                   { 
                        std::cout << "left button was pressed\n";
                        // windowSurface = SDL_LoadBMP( "image1.bmp" );
                        currentImage = image1;
                        
                    }

                else if(event.button.button == SDL_BUTTON_RIGHT)
                        {
                            // windowSurface = SDL_LoadBMP( "image2.bmp" );
                            std::cout << "right button was pressed\n";
                            currentImage = image2;
                        }
            }

            
            
            
        }

        SDL_BlitSurface(currentImage , NULL , windowSurface, NULL);
        SDL_UpdateWindowSurface(window);
    }

    SDL_FreeSurface(image1);
    SDL_FreeSurface(image2);
    
    // We destroy our window. We are passing in the pointer
    // that points to the memory allocated by the 
    // 'SDL_CreateWindow' function. Remember, this is
    // a 'C-style' API, we don't have destructors.
    SDL_DestroyWindow(window);
    

    // image1 = image2 = windowSurface = nullptr;
    // window = nullptr;
    // We safely uninitialize SDL2, that is, we are
    // taking down the subsystems here before we exit
    // We add a delay in order to see that our window
    // has successfully popped up.
   
    SDL_Quit();
    return 0;
}