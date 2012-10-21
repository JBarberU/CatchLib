//
//  File:   GLRenderer20.cpp
//  Class:  GLRenderer20
//  Author: John Barbero Unenge
//          All code is my own except where credited to others.
//
//  Copyright (c) 2012 Catch22. All Rights Reserved.
//
//  Date:   17/9/2012.
//

//  Important note!
//  This class contains a lot of rendering code from
//  git@github.com:JBarberU/OpenGL-ES-Exercises.git which in
//  turn is taken from a book called iPhone 3D Programming
//  written by Philip Rideout. This class is not currently
//  used by this project.



#include "../Helper/Logger.hpp"
#include "GLRenderer20.hpp"
#include "../Helper/InputManager.hpp"

#include <cmath>

const char SIMPLE_VERTEX_SHADER[] = 
    "attribute vec4 Position;\n"
    "attribute vec4 SourceColor;\n"
    "varying vec4 DestinationColor;\n"
    "uniform mat4 Projection;\n"
    "uniform mat4 Modelview;\n"
    "void main(void)\n"
    "{\n"
    "DestinationColor = SourceColor;\n"
    "gl_Position = Projection * Modelview * Position;\n"
    "}\n"
;
const char SIMPLE_FRAGMENT_SHADER[] = 
    "varying lowp vec4 DestinationColor;\n"
    "void main(void)\n"
    "{\n"
        "gl_FragColor = DestinationColor;\n"
    "}\n";

float clearColor[] = {0.5f, 0.0f, 0.5f, 1.0f};

// Define the positions and colors of two triangles.
const Vertex Vertecies[] = {
    Vertex(-0.5f, -0.866f),
    Vertex(0.5f, -0.866f),
    Vertex(0,01),
    
    Vertex(-0.5f, -0.866f),
    Vertex(0.5f, -0.866f),
    Vertex(0, -0.4f),
};

IRenderer* CreateRendererWithOpenGL20()
{
    return new GLRenderer20();
}

GLRenderer20::GLRenderer20()
{
	Log(LOG_INFO, "GLRenderer20", "Constructed a GLRenderer!");
    Log(LOG_INFO, "GLRenderer20", (const char *)glGetString(GL_VERSION));
    
    // Create a renderbuffer and bind it
    glGenRenderbuffers(1, &m_renderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_renderbuffer);
    
    
    // Create the framebuffer object and attach the color buffer.
    m_framebuffer = 0; // Set framebufferID to default ID
    
    // Only generate a new framebuffer if running in iOS as
    // Android seems to have no support for this.
    #ifdef __APPLE__
        glGenFramebuffers(1, &m_framebuffer);
    #endif
    
    // Bind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, m_framebuffer);
    
    // Connect the framebuffer and the renderbuffer
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_renderbuffer);
    
}
GLRenderer20::~GLRenderer20()
{
	Log(LOG_INFO, "GLRenderer", "Destroyed a GLRenderer!");
}


void GLRenderer20::init(int width, int height, CLTexture* texture)
{
	Log(LOG_INFO, "GLRenderer", "Initialized GLRenderer");

    glViewport(0, 0, width, height);

    // Build shader program
    m_simpleProgram = BuildProgram(SIMPLE_VERTEX_SHADER, SIMPLE_FRAGMENT_SHADER);
    
    glUseProgram(m_simpleProgram);
    
    // Initialize the projection matrix.
    ApplyOrtho(2, 3);

    Log(LOG_INFO, "GLRenderer", "Done with init code.");
}

void GLRenderer20::render()
{
    glClearColor(clearColor[0],clearColor[1],clearColor[2],clearColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
    
    ApplyRotation(0);
    
    GLuint positionSlot = glGetAttribLocation(m_simpleProgram, "Position");
    GLuint colorSlot = glGetAttribLocation(m_simpleProgram, "SourceColor");
        
    glEnableVertexAttribArray(positionSlot);
    glEnableVertexAttribArray(colorSlot);
    
    GLsizei stride = sizeof(Vertex);
    const GLvoid* pCoords = &Vertecies[0].Position[0];
    const GLvoid* pColors = &Vertecies[0].Color[0];
    
    glVertexAttribPointer(positionSlot, 2, GL_FLOAT, GL_FALSE, stride, pCoords);
    glVertexAttribPointer(colorSlot, 4, GL_FLOAT, GL_FALSE, stride, pColors);
    
    GLsizei vertexCount = sizeof(Vertecies) / sizeof(Vertex);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    glDisableVertexAttribArray(positionSlot);
    glDisableVertexAttribArray(colorSlot);
}
void GLRenderer20::update(float dt)
{
    // Intentionally left empty
}
void GLRenderer20::onRotate(DeviceOrientation orientation)
{
    // Intentionally left empty
}
void GLRenderer20::addActor(Actor* actor)
{
    // Intentionally left empty
}
void GLRenderer20::removeActor(Actor* actor)
{
    // Intentionally left empty
}
void GLRenderer20::centerCameraOn(Vector2d point)
{
    // Intentionally left empty
}

GLuint GLRenderer20::BuildProgram(const char* vertexShaderSource, const char* fragmentShaderSource) const
{
    
    GLuint vertexShader = BuildShader(vertexShaderSource, GL_VERTEX_SHADER);
    GLuint fragmentShader = BuildShader(fragmentShaderSource, GL_FRAGMENT_SHADER);
    
    GLuint programHandle = glCreateProgram();
    glAttachShader(programHandle, vertexShader);
    glAttachShader(programHandle, fragmentShader);
    glLinkProgram(programHandle);
    
    GLint linkSuccess;
    glGetProgramiv(programHandle, GL_LINK_STATUS, &linkSuccess);
    if (linkSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetProgramInfoLog(programHandle, sizeof(messages), 0, &messages[0]);
        Log(LOG_ERROR, "OpenGLES", messages);
    }
    
    Log(LOG_INFO, "GLRenderer", "Built shader program.");
    return programHandle;
}

GLuint GLRenderer20::BuildShader(const char* source, GLenum shaderType) const
{
    
    GLuint shaderHandle = glCreateShader(shaderType);
    glShaderSource(shaderHandle, 1, &source, 0);
    glCompileShader(shaderHandle);
    
    GLint compileSuccess;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
    
    if (compileSuccess == GL_FALSE) {
        GLchar messages[256];
        glGetShaderInfoLog(shaderHandle, sizeof(messages), 0, &messages[0]);
        Log(LOG_ERROR, "GLRenderer", "Failed to compile shader!");
    }
    Log(LOG_INFO, "GLRenderer", "Compiled shader.");
    return shaderHandle;
}

void GLRenderer20::ApplyOrtho(float maxX, float maxY) const
{
    float a = 1.0f / maxX;
    float b = 1.0f / maxY;
    float ortho[16] = {
        a, 0, 0, 0,
        0, b, 0, 0,
        0, 0, -1, 0,
        0, 0, 0, 1
    };
    
    GLint projectionUniform = glGetUniformLocation(m_simpleProgram, "Projection");
    glUniformMatrix4fv(projectionUniform, 1, 0, &ortho[0]);
}

void GLRenderer20::ApplyRotation(float degrees) const
{
    float radians = degrees * 3.14159f / 180.0f;
    float s = std::sin(radians);
    float c = std::cos(radians);
    float zRotation[16] = {
        c, s, 0, 0,
        -s, c, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    
    GLint modelviewUniform = glGetUniformLocation(m_simpleProgram, "Modelview");
    glUniformMatrix4fv(modelviewUniform, 1, 0, zRotation);
}

