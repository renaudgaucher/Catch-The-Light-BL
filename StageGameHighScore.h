#ifndef DEF_STAGEGAMEHIGHSCORE
#define DEF_STAGEGAMEHIGHSCORE

#define DELAI_INITIAL 8000
#define ROUND_DURATION 30000
#define PAUSE_DURATION 15000

#include "Stage.h"



/*
	Jeu où le but n'est pas de dépasser l'autre mais tout simplement de faire un high score : les deux joueurs jounet sans interaction l'un avec l'autre.
	Le jeu se déroule en un nombre indéfini de manche, à chaque manche cela va plus vite.
	les lampes du tableau du joueur s'allument les unes après les autres, le joueur doit taper dessus pour les éteindre, cela lui fait des points. (fois le round au carré
	Si toutes les limuières du board sont allumées sauf 2, le joueur perd.
	La vitesse d'allumage de la prochaine lumière suit la formule :
	delai_base / sqrt (round) *(1 + (nb_light_allumees - nb_light_max)/nb_lights_max)) 
*/
class StageGameHighScore : public Stage
{
public:
	StageGameHighScore(Gameboard* gameboard);
	virtual byte run();
private:
	int score1;
	int score2;
	unsigned long timeBegin;
	unsigned long roundDuration=ROUND_DURATION;
	unsigned long pauseDuration=PAUSE_DURATION;
	byte currentRound = 0;

	byte gameState;
	byte lightsOn[20] = { 0 };

	void runRound();
	void runPause();

	void handleEvents();
	void printScore();
	void newLight();
	void shutDownLight(byte light);

	void animation();
};


#endif

