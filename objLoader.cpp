//
// Created by 杨起 on 2018/12/29.
//

#include <iostream>
#include <sstream>
#include "objLoader.h"

std::vector<std::vector<float> > matirial_table = std::vector<std::vector<float> > {
        std::vector<float>{0.0215,0.1745,0.0215,0.07568,0.61424,0.07568,0.633,0.727811,0.633,6.0},
        std::vector<float>{0.135,0.2225,0.1575,0.54,0.89,0.63,0.316228,0.316228,0.316228,0.1},
        std::vector<float>{0.05375,0.05,0.06625,0.18275,0.17,0.22525,0.332741,0.328634,0.346435,0.3},
        std::vector<float>{0.25,0.20725,0.20725,1,0.829,0.829,0.296648,0.296648,0.296648,0.088},
        std::vector<float>{0.1745,0.01175,0.01175,0.61424,0.04136,0.04136,0.727811,0.626959,0.626959,12.0},
        std::vector<float>{0.1,0.18725,0.1745,0.396,0.74151,0.69102,0.297254,0.30829,0.306678,0.1},
        std::vector<float>{0.329412,0.223529,0.027451,0.780392,0.568627,0.113725,0.992157,0.941176,0.807843,0.21794872},
        std::vector<float>{0.2125,0.1275,0.054,0.714,0.4284,0.18144,0.393548,0.271906,0.166721,0.2},
        std::vector<float>{0.25,0.25,0.25,0.4,0.4,0.4,0.774597,0.774597,0.774597,0.6},
        std::vector<float>{0.19125,0.0735,0.0225,0.7038,0.27048,0.0828,0.256777,0.137622,0.086014,0.1},
        std::vector<float>{0.24725,0.1995,0.0745,0.75164,0.60648,0.22648,0.628281,0.555802,0.366065,4.0},
        std::vector<float>{0.19225,0.19225,0.19225,0.50754,0.50754,0.50754,0.508273,0.508273,0.508273,4.0},
        std::vector<float>{0.0,0.0,0.0,0.01,0.01,0.01,0.50,0.50,0.50,.25},
        std::vector<float>{0.0,0.1,0.06,0.0,0.50980392,0.50980392,0.50196078,0.50196078,0.50196078,.25},
        std::vector<float>{0.0,0.0,0.0,0.1,0.35,0.1,0.45,0.55,0.45,.25},
        std::vector<float>{0.0,0.0,0.0,0.5,0.0,0.0,0.7,0.6,0.6,.25},
        std::vector<float>{0.0,0.0,0.0,0.55,0.55,0.55,0.70,0.70,0.70,.25},
        std::vector<float>{0.0,0.0,0.0,0.5,0.5,0.0,0.60,0.60,0.50,.25},
        std::vector<float>{0.02,0.02,0.02,0.01,0.01,0.01,0.4,0.4,0.4,.078125},
        std::vector<float>{0.0,0.05,0.05,0.4,0.5,0.5,0.04,0.7,0.7,.078125},
        std::vector<float>{0.0,0.05,0.0,0.4,0.5,0.4,0.04,0.7,0.04,.078125},
        std::vector<float>{0.05,0.0,0.0,0.5,0.4,0.4,0.7,0.04,0.04,.078125},
        std::vector<float>{0.05,0.05,0.05,0.5,0.5,0.5,0.7,0.7,0.7,.078125},
        std::vector<float>{0.05,0.05,0.0,0.5,0.5,0.4,0.7,0.7,0.04,.078125}
};

static char mati_table[25][50] {
        "emerald",
        "jade",
        "obsidian",
        "pearl",
        "ruby",
        "turquoise",
        "brass",
        "bronze",
        "chrome",
        "copper",
        "gold",
        "silver",
        "black_plastic",
        "cyan_plastic",
        "green_plastic",
        "red_plastic",
        "white_plastic",
        "yellow_plastic",
        "black_rubber",
        "cyan_rubber",
        "green_rubber",
        "red_rubber",
        "white_rubber",
        "yellow_rubber"
};




template <class Container>
void split2(const std::string& str, Container& cont) {
    std::stringstream ssr(str);
    std::string token;
//    while (std::getline(ssr, token, delim)) {
    while (ssr>>token) {
        if (!token.empty()) {
            cont.push_back(token);
        }
    }
}






void objLoader::read_obj(const char *Path) {
    std::fstream ss;
    ss.open(Path, std::ios::in);
    std::string line;
    std::vector<std::vector<float> > points;
    // 第一个group
    this->cur_group = new Group();
    while (! ss.eof() ) {
        std::getline(ss, line);
        if (line[0] == '#') { continue ;}

        if (line[0] == 'v') {
            std::vector<std::string> ps;
            split2(line, ps);
            float x = std::stof (ps[1]);
            float y = std::stof (ps[2]);
            float z = std::stof (ps[3]);
            std::vector<float> p;
            p.push_back(x);p.push_back(y);p.push_back(z);
            points.push_back(p);
            int fuck_cpp = 8;
        }
        if(line[0] == 'f') {
            std::vector<std::string> ps;
            split2(line, ps);
            std::vector<int> seq;
            for(int i=1; i<ps.size(); i++) {
                seq.push_back(stoi(ps[i]));
            }
            Face *f = new Face();
            f->piontsVec = points;
            f->seq = seq;
            cur_group->facesVec.push_back(*f);
            points.clear();
            int fuck_cpp = 8;
        }
        if (line[0] == 'm' && line[1] == 'a') {
            std::vector<std::string> ps;
            split2(line, ps);
            cur_group->materialName = ps[1];
            int fuck_cpp = 8;
        }
        if(line[0] == 'g') {
            std::vector<std::string> ps;
            split2(line, ps);
            cur_group->groupName = ps[1];
            this->groups.push_back(*cur_group);
            cur_group = new Group();
        }
    }
    ss.close();
}

std::vector<std::vector<float> > split2triangle (std::vector<std::vector<float> > polygon) {
    std::vector<std::vector<float> > result;
    std::vector<float> pointFirst = polygon[0];
    // 加速 : 一个面应该只有一个法向量
    polygon.erase(polygon.begin());
    while (polygon.size() > 1) {
        std::vector<float> point1 = pointFirst;
        std::vector<float> point2 = polygon.back();
        polygon.pop_back();
        std::vector<float> point3 = polygon.back();
        // 求叉乘计算法向量
        int test_l = polygon.size() % 2;
        std::vector<float> normal = cross_product(sub(pointFirst, point3), sub(pointFirst, point2));
        if (test_l == 1) {
            normal = cross_product(sub(pointFirst, point2), sub(pointFirst, point3));
        }
        // 法向量append加入每一个点
        point1.insert(point1.end(), normal.begin(), normal.end());
        point2.insert(point2.end(), normal.begin(), normal.end());
        point3.insert(point3.end(), normal.begin(), normal.end());
        // result append 三个点
        result.push_back(point1);
        result.push_back(point2);
        result.push_back(point3);
    }
    return result;
}

std::vector<std::vector<float> > Face::out_to_open_gl() {
    std::vector<std::vector<float> > useVec;
    int count_points = this->piontsVec.size();
    for(auto i:seq) {
        if (i < 0) {
            i += count_points;
        }
        useVec.push_back(piontsVec[i]);
    }
    std::vector<std::vector<float> > poly_tri = split2triangle(useVec);

    return poly_tri;
}

std::vector<float> cross_product(const std::vector<float>& x, const std::vector<float>& y)
{

    return std::vector<float>
            {
                    x[1]*y[2]-x[2]*y[1],
                    x[2]*y[0]-x[0]*y[2],
                    x[0]*y[1]-x[1]*y[0]
            };
    // uniform initialization, C++11新特性
}

std::vector<float> sub(const std::vector<float>& x, const std::vector<float>& y)
{

    return std::vector<float>
            {
                    x[0] - y[0],
                    x[1] - y[1],
                    x[2] - y[2]
            };
}


void Group::draw(Shader useshader) {
    if(!if_mesh) {
        init_mesh();
    }
    int mt_id=0;
    for(; mt_id <25 ;mt_id++) {
        if (strcmp(mati_table[mt_id], materialName.c_str()) == 0) {
            break ;
        }
    }
    if (mt_id >= 24) {
        mt_id = 18;
    }
    set_material(useshader, matirial_table[mt_id]);
    for(auto &mesh : MeshsVec) {
        mesh.Draw(useshader);
    }
}

void objLoader::Draw(Shader useone) {
    for (auto &i : groups) {
        i.draw(useone);
    }
}

void Group::init_mesh() {
    for(int i=0; i< this->facesVec.size(); i++) {
        // 为每个face新建一个mesh, mesh.draw
        std::vector<std::vector<float> > drawdata = facesVec[i].out_to_open_gl();
        //创造drawdata
        int row = drawdata.size();
        std::vector<Vertex> data;
        std::vector<unsigned int> ind;
        for(int j=0; j<row; j++) {
            Vertex V;
            V.Position = glm::vec3(drawdata[j][0], drawdata[j][1], drawdata[j][2]);
            V.Normal = glm::vec3(drawdata[j][3], drawdata[j][4], drawdata[j][5]);
            data.push_back(V);
            ind.push_back((unsigned int)j);
        }
        // 创造Mesh
        Mesh faceMesh = Mesh(data, ind);
        this->MeshsVec.push_back(faceMesh);
    }
    if_mesh = true;
}

void Group::set_material(Shader useshader, std::vector<float> m_vec) {
    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
    glm::vec3 lightColor(1.0f,1.0f,1.0f);
    glm::vec3 diffuseColor = lightColor * glm::vec3(0.5);// decrease the influence
    glm::vec3 ambientColor = lightColor * glm::vec3(0.2); // low influence
    useshader.setVec3("light.ambient", ambientColor);
    useshader.setVec3("light.diffuse", diffuseColor);
    useshader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);

    // material properties
    useshader.setVec3("material.ambient", m_vec[0], m_vec[1], m_vec[2]);
    useshader.setVec3("material.diffuse", m_vec[3], m_vec[4], m_vec[5]);
    useshader.setVec3("material.specular", m_vec[6], m_vec[7], m_vec[8]); // specular lighting doesn't have full effect on this object's material
    useshader.setFloat("material.shininess", m_vec[9]);
}