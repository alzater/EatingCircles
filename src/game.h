#pragma once
#include "oxygine-framework.h"
#include <functional>
#include "circle.h"
#include "Polygon.h"
#include <vector>

using namespace oxygine;

class Game{
public:
    Game(int l);
    bool nextFrame();
    int getScore();
private:
    int level, score, num_of_bots;
    Vector2 stage_size;
    spCircle main_circle;
    std::vector <spCircle> circles;
    
    Vector2 getRandomCoords();
    void main_circle_turn();
    void make_turn();
    bool check_main_circle();
    void check_bots_positions();
    void renew_circle(spCircle& circle);
    void check_eaters();
    
    spPolygon poly;
};

static vertexPCT2 initVertex(const Vector2 &pos, unsigned int color)
	{
		vertexPCT2 v;
		v.color = color;
		v.x = pos.x;
		v.y = pos.y;
		v.z = 0;
		v.u = v.x / 100;
		v.v = v.y / 100;

		return v;
	}

	static vertexPCT2 getVertex(int i, int num)
	{
		float theta = 2.0f * MATH_PI / num * i;

		Vector2 dir = Vector2(scalar::cos(theta), scalar::sin(theta));
		float rad = getRoot()->getHeight() * 0.4f * (1 + scalar::sin(theta * 10)/10);
		Vector2 p = dir * rad;
		
		Color c = interpolate(Color(Color::Lime), Color(Color::Red), scalar::abs(scalar::sin(theta * 3)));
		return initVertex(p, c.rgba());
	}

	static vertexPCT2 *createVertices(int num)
	{
		int verticesCount = num * 4;

		vertexPCT2 * vertices = new vertexPCT2[verticesCount];

		vertexPCT2 *p = vertices;
		for (int n = 0; n < num; ++n)
		{
			//add centered vertex
			*p = initVertex(Vector2(0, 0), Color::White);
			++p;

			*p = getVertex(n, num);
			++p;

			*p = getVertex(n + 1, num);
			++p;

			//Oxygine uses "triangles strip" rendering mode 
			//dublicate last vertex (degenerate triangles)
			*p = getVertex(n + 1, num);
			++p;
		}

		return vertices;
	}
