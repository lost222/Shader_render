//
// Created by 杨起 on 2018/12/29.
//
#include <vector>
#include "Shader.h"
#ifndef TEST_GLFW_OBJLOADER_H
#define TEST_GLFW_OBJLOADER_H






std::vector<std::vector<float> > split2triangle (std::vector<std::vector<float> > polygon);
std::vector<float> cross_product(const std::vector<float>& x, const std::vector<float>& y);
std::vector<float> sub(const std::vector<float>& x, const std::vector<float>& y);


struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;

};



class Mesh {
public:
    /*  Mesh Data  */
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    unsigned int VAO;

    /*  Functions  */
    // constructor
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
    {
        this->vertices = vertices;
        this->indices = indices;
        // now that we have all the required data, set the vertex buffers and its attribute pointers.
        setupMesh();
    }

    // render the mesh
    void Draw(Shader shader)
    {
        // bind appropriate textures
        unsigned int diffuseNr  = 1;
        unsigned int specularNr = 1;
        unsigned int normalNr   = 1;
        unsigned int heightNr   = 1;

        // draw mesh
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // always good practice to set everything back to defaults once configured.

    }

private:
    /*  Render data  */
    unsigned int VBO, EBO;

    /*  Functions    */
    // initializes all the buffer objects/arrays
    void setupMesh()
    {
        // create buffers/arrays
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // set the vertex attribute pointers
        // vertex Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        // vertex normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

        glBindVertexArray(0);
    }
};

class Face {
public:
    std::vector<std::vector<float> > piontsVec;
    std::vector<int> seq;
    std::vector<std::vector<float> > out_to_open_gl();
};

class Group {
    bool if_mesh;
public:
    Group(){if_mesh = false;}
    std::vector<Face> facesVec;
    std::string groupName;
    std::vector<Mesh> MeshsVec;
    void init_mesh();
    void draw(Shader useshader);
};



class objLoader {
    std::vector<Group> groups;
    Group *cur_group;
public:
    void read_obj(const char* Path);
    void Draw(Shader );
};

#endif //TEST_GLFW_OBJLOADER_H
