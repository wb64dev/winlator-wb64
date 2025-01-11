class ShaderCompiler {
public:
    ShaderCompiler();
    ~ShaderCompiler();

    bool compileShader(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);
    GLuint getProgramID();

private:
    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    GLuint programID;
};

#endif  // SHADER_COMPILER_H

ShaderCompiler::ShaderCompiler() : vertexShaderID(0), fragmentShaderID(0), programID(0) {}

ShaderCompiler::~ShaderCompiler() {
    glDeleteProgram(programID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

bool ShaderCompiler::compileShader(const std::string& vertexShaderCode, const std::string& fragmentShaderCode) {
    // Create shaders
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Compile vertex shader
    const char* vertexShaderSource = vertexShaderCode.c_str();
    glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShaderID);

    // Check vertex shader compilation
    GLint compileStatus;
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileStatus);
    if (!compileStatus) {
        GLchar log[1024];
        glGetShaderInfoLog(vertexShaderID, 1024, NULL, log);
        std::cerr << "Vertex shader compilation error: " << log << std::endl;
        return false;
    }

    // Compile fragment shader
    const char* fragmentShaderSource = fragmentShaderCode.c_str();
    glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShaderID);

    // Check fragment shader compilation
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &compileStatus);
    if (!compileStatus) {
        GLchar log[1024];
        glGetShaderInfoLog(fragmentShaderID, 1024, NULL, log);
        std::cerr << "Fragment shader compilation error: " << log << std::endl;
        return false;
    }

    // Create program
    programID = glCreateProgram();

    // Attach shaders
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    // Link program
    glLinkProgram(programID);

    // Check program linking
    GLint linkStatus;
    glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus);
    if (!linkStatus) {
        GLchar log[1024];
        glGetProgramInfoLog(programID, 1024, NULL, log);
        std::cerr << "Program linking error: " << log << std::endl;
        return false;
    }

    return true;
}

GLuint ShaderCompiler::getProgramID() {
    return programID;
}
init Main() {
    // Initialize GLFW and GLEW
    glfwInit();
    glewInit();

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Shader Compiler", NULL, NULL);

    // Vertex shader code
    std::string vertexShaderCode = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )";

    // Fragment shader code
    std::string fragmentShaderCode = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
        }
    )";

    // Compile shaders
    ShaderCompiler compiler;
    if (!compiler.compileShader(vertexShaderCode, fragmentShaderCode)) {
        std::cerr << "Shader compilation failed." << std::endl;
        return 1;
    }

    // Get program ID
    GLuint programID = compiler.getProgramID();

    // Use program
    glUseProgram(programID);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
