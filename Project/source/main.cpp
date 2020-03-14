
#include "functions.hpp"
using namespace std;
//VERTICES UTILIZADOS

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  

int main()
{   
    // função pra instanciar a janela do GLFW
    glfwInit();
    glwindowhint();

    //objeto janela
    GLFWwindow* window = glfwCreateWindow(800, 600, "janelinha da alegria", NULL, NULL);

    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // função glad para carregar a função do openGL

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }    
    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
    /* -------------------------------------------
        CLOUD NE */

    int vertexShader = glCreateShader(GL_VERTEX_SHADER); // criando um shader de vertice
    glVertexsourcecompile(vertexShader);

    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // criando frag shader
    glFragmentsourcecompile(fragmentShader);

    int shaderProgram = glCreateProgram();//criando programa shader
    glattachlink(shaderProgram, vertexShader, fragmentShader);

    
    unsigned int VBO, VAO;  //criando objetos vertice
    glGenBindvertexarray(&VAO);
  //  glGenBindvertexbuffer(&VBO, vertices);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //carregando vertices no buffer

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); //setando atributos de vertices
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 


    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // loop de renderização
while(!glfwWindowShouldClose(window))
{
    // input
    processInput(window);
    // comandos de renderização

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // limpar o buffer com essa cor :)
    glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3); //desenhando
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    //limpar memoria
    glfwTerminate();
    return 0;
}
