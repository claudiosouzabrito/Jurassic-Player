#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <iostream>

//redimenciona a janela para a viewport
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

//entrada de controle 
void processInput(GLFWwindow *window)
{
    // função que recebe janela e tecla como entrada
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, true);
}