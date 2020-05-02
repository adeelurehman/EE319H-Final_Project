#ifndef VertPlath
#define VertPlath

class VertPlat {
public:
	int x;
	int y;
	int w;
	int h;
	
	VertPlat(int x, int y, int w, int h);
	void drawMe() const;

	//calculates if passed rect overlaps with self
	//false for overlap
	//true for no overlap
	bool testVP(int x, int y, int w, int h) const;
};

#endif
