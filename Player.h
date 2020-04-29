class Player {
public:
	const unsigned short* facingRightTexture;
	const unsigned short* facingLeftTexture;
	const unsigned short* facingForwardTexture;
	int width;
	int height;

	int Xpos;
	int Ypos;
	int Xvel;
	int Yvel;
	
	int type; //0 for water, 1 for fire
	
	Player(int type, const unsigned short* rightTxtr, const unsigned short* leftTxtr, const unsigned short* forwardTxtr, int width, int height);
	
	void update(); 
	void drawMe();
};
