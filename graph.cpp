#define _USE_MATH_DEFINES
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <limits>
#include <stack>

int scl=1;
int p = 1;
int start;
int end;
bool arr[600][800];
const int WIDTH = 800;
const int HEIGHT = 600;
int h = HEIGHT / scl;
int w = WIDTH / scl;
float values[480000];
int parent[480000];
bool vis[480000];
float dis[100];
float INF = std::numeric_limits<float>::max();
std::vector<std::pair<int, float> > G[480000];
std::vector<std::queue<int> > k(480000);
std::vector<std::pair<int, int> > v[480000];
void drawPoint(float x, float y) {
    glColor3f(0.5f, 1.0f, 1.0f);
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}
void drawLine(float x1, float y1, float x2, float y2) {
    glColor3f(0.5f, 1.0f, 1.0f);

    glBegin(GL_LINES); // Start drawing a line
    glVertex2f(x1, y1); // Specify the first point of the line
    glVertex2f(x2, y2); // Specify the second point of the line
    glEnd(); // End drawing the line
}

void maxing(int edges)
{
    for (int i = 1; i <= edges; i++)
    {
        values[i] = INF;
    }
}
void printShortestPath(int dest)
{
    std::vector<int> path;
    int cur = dest;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }
    for (int i = path.size() - 2; i >= 0; i--)
    {
        drawLine(path[i] % w * scl, path[i] / w * scl, path[i + 1] % w * scl, path[i + 1] / w * scl);
            //drawPoint(path[i] % w * scl, path[i] / w * scl);
    }
   // std::cout << std::endl;
}
void dijkstra(int edge)
{
    std::pair<int, int>Pair;
    std::priority_queue<std::pair<int, int> >q;
    values[edge] = 0;
    parent[edge] = -1;
    q.push(std::make_pair(0, edge));
    while (!q.empty())
    {
        int w = q.top().second;
        q.pop();
        for (int i = 0; i < G[w].size(); i++)
        {
            if (G[w][i].second + values[w] < values[G[w][i].first])
            { 
                values[G[w][i].first] = G[w][i].second + values[w];
                parent[G[w][i].first] = w;
                q.push(std::make_pair((-1) * values[G[w][i].first], G[w][i].first));
            }
        }
    }
}
void drawCircle(float x, float y, float radius) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float rad = i * M_PI / 180;
        glVertex2f(x + radius * cos(rad), y + radius * sin(rad));
    }
    glEnd();
}

int main() {

    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "jos_brat", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glViewport(0, 0, WIDTH, HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -700, 400);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glLineWidth(0.5f);

    int x1 = 0;
    int y1 = 200;
    int d1 = 155;
    int x2 = 300;
    int y2 = 0;
    int d2 = 200;
    int x3 = 400;
    int y3 = 300;
    int d3 = 150;
    int x4 = 250;
    int y4 = 400;
    int d4 = 130;
    int x5 = 450;
    int y5 = 600;
    int d5 = 140;
    int x6 = 680;
    int y6 = 550;
    int d6 = 80;
    int x7 = 680;
    int y7 = 400;
    int d7 = 80;
    int x8 = 630;
    int y8 = 270;
    int d8 = 80;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j*scl - x1) * (j*scl - x1) + (i*scl - y1) * (i*scl - y1));
            if (distance < d1) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j * scl - x2) * (j * scl - x2) + (i * scl - y2) * (i * scl - y2));
            if (distance < d2) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j * scl - x3) * (j * scl - x3) + (i * scl - y3) * (i * scl - y3));
            if (distance < d3) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j * scl - x4) * (j * scl - x4) + (i * scl - y4) * (i * scl - y4));
            if (distance < d4) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j * scl - x5) * (j * scl - x5) + (i * scl - y5) * (i * scl - y5));
            if (distance < d5) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j * scl - x6) * (j * scl - x6) + (i * scl - y6) * (i * scl - y6));
            if (distance < d6) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j * scl - x7) * (j * scl - x7) + (i * scl - y7) * (i * scl - y7));
            if (distance < d7) {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float distance = sqrt((j * scl - x8) * (j * scl - x8) + (i * scl - y8) * (i * scl - y8));
            if (distance < d8) {
                arr[i][j] = true;
            }
        }
    }
    maxing(480000);
   
    for (int i = 0; i <= p; i++) {
        dis[i] = sqrt(i*i+p*p+i);
    }
    bool s = false;
    for (int i = 1; i < h - 1; i++) {
        for (int j = 1; j < w - 1; j++) {
            if (!arr[i][j]) {
                if (!s) {
                    start = i * w + j;
                    s = true;
                }
                //horizontal
                for (int k = -p; k <= p; k++) {
                    if (i + p < h - 1 && j + k < w - 1) {
                        if (!arr[i + p][j + k]) {
                            G[i * w + j].push_back(std::make_pair((i + p) * w + j + k, dis[abs(k)]));
                        }
                    }
                    if (i - p >= 1 && j + k < w - 1) {
                        if (!arr[i - p][j + k]) {
                            G[i * w + j].push_back(std::make_pair((i - p) * w + j + k, dis[abs(k)]));
                        }
                    }
                   
                }
                //vertical
                for (int k = -p + 1; k < p; k++) {
                    if (i + k < h - 1 && j + p < w - 1) {
                        if (!arr[i + k][j + p]) {
                            G[i * w + j].push_back(std::make_pair((i + k) * w + j + p, dis[abs(k)]));
                        }
                    }
                    if (i + k < h - 1 && j - p >= 1) {
                        if (!arr[i + k][j - p]) {
                            G[i * w + j].push_back(std::make_pair((i + k) * w + j - p, dis[abs(k)]));
                        }
                    }
                }
                end = i * w + j;
                //corner 1
            }
        }
    }
    dijkstra(start);
    
    while (!glfwWindowShouldClose(window)) {
     
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE_LOOP);
        unsigned int vao = 0;
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        std::queue<int> c;
        glColor3f(0.5f, 1.0f, 1.0f);
        glColor3f(0.9f, 0.8f, 0.8f);
        drawCircle(x1, y1, d1-5);
        drawCircle(x2, y2, d2 - 5);
        drawCircle(x3, y3, d3 - 5);
        drawCircle(x4, y4, d4 - 5);
        drawCircle(x5, y5, d5 - 5);
        drawCircle(x6, y6, d6 - 5);
        drawCircle(x7, y7, d7 - 5);
        drawCircle(x8, y8, d8 - 5);

        printShortestPath(end);
       
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}