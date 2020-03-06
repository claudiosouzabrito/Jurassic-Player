#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <iostream>
#include "functions.hpp"

int main()
{   
    // função pra instanciar a janela do GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //objeto janela
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // função glad para carregar a função do openGL

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
 

// loop de renderização
while(!glfwWindowShouldClose(window))
{
    // input
    processInput(window);
    // comandos de renderização

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // limpar o buffer com essa cor :)
        glClear(GL_COLOR_BUFFER_BIT);

   // verifica eventos e troca os buffers
    glfwSwapBuffers(window);
       glfwPollEvents();
}

  //limpar memoria
    glfwTerminate();
    return 0;

}