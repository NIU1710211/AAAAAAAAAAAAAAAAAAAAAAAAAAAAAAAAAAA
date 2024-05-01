#ifndef FIGURA_H
#define FIGURA_H

#include <string>
#include <cstdlib> 
#include <iostream>

using namespace std;

const int MAX_TAMANY = 4;

typedef enum
{
	ESQUERRA = 0,
	DRETA
} DireccioMoviment;

typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;

typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
	Figura();
	Figura(TipusFigura figura, int fila, int col, int nGirs);
	void setFila(int fila) { m_fila = fila; }
	void setCol(int col) { m_col = col; }
	int getFila() const { return m_fila; }
	int getCol() const { return m_col; }
	void mouLateral(int dirX) { m_col += dirX; }
	int getTamanyFigura() const { return m_tamanyFigura; }
	ColorFigura getFiguraPos(int fila, int col) const { return m_figura[fila][col]; }

	void girar(DireccioGir direccioGir);
	bool movimentLateral(DireccioMoviment direccio);
	bool baixar();

private:
	int m_fila;
	int m_col;
	ColorFigura m_figura[MAX_TAMANY][MAX_TAMANY];
	int m_tamanyFigura;

};
#endif