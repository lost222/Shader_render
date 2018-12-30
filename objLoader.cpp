//
// Created by 杨起 on 2018/12/29.
//

#include <iostream>
#include <sstream>
#include "objLoader.h"

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
    while (polygon.size() > 2) {
        std::vector<float> point1 = pointFirst;
        std::vector<float> point2 = polygon.back();
        polygon.pop_back();
        std::vector<float> point3 = polygon.back();
        // 求叉乘计算法向量
        std::vector<float> normal = cross_product(sub(pointFirst, point2), sub(pointFirst, point3));
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
        faceMesh.Draw(useshader);
    }
}