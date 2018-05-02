#ifndef COLOR_HPP
#define COLOR_HPP

struct  Color
{
	float r=0.0f;
	float h=0.0f;
	float g=0.0f;
	
	Color(float rhg ):
		r{rhg},
		h{rhg},
		g{rhg} {}
	Color(float r1, float h1, float g1):
		r{r1},
		h{h1},
		g{g1}  {}
};

#endif