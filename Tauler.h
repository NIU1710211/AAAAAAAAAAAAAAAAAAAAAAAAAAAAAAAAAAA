#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include <fstream>


const int MAX_FILA = 8;
const int MAX_COL = 8;

const int ESPAIS_LATERALS = 2;

const int TOTAL_FILES = MAX_FILA + ESPAIS_LATERALS * 2;
const int TOTAL_COLUMNES = MAX_COL + ESPAIS_LATERALS * 2;

const int INICI_FILES = ESPAIS_LATERALS;
const int INICI_COLUMNES = ESPAIS_LATERALS;

const int FINAL_FILES = TOTAL_FILES - ESPAIS_LATERALS - 1;
const int FINAL_COLUMNES = TOTAL_COLUMNES - ESPAIS_LATERALS - 1;

class Tauler
{
public:
	Tauler();
	ColorFigura getTaulerPos(int fila, int col) const { return m_tauler[fila][col]; }
	void setTaulerPos(int fila, int col, ColorFigura color) { m_tauler[fila][col] = color; }
	bool comprovaColisio(const Figura& figura) const;

private:
	ColorFigura m_tauler[TOTAL_FILES][TOTAL_COLUMNES];
};

ifstream& operator>>(ifstream& input, Tauler& tauler);

#endif // !1
