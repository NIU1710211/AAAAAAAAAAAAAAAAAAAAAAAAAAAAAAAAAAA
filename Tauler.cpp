#include "Tauler.h"


Tauler::Tauler()
{
	for (int i = 0; i < TOTAL_FILES; i++)
		for (int j = 0; j < TOTAL_COLUMNES; j++)
			if (i >= INICI_FILES && i <= FINAL_FILES && j >= INICI_COLUMNES && j <= FINAL_COLUMNES)
				m_tauler[i][j] = COLOR_NEGRE;
			else
				m_tauler[i][j] = NO_COLOR;
}

bool Tauler::comprovaColisio(const Figura& figura) const
{
	bool movimentValid = true;
	for (int i = 0; i < figura.getTamanyFigura() && movimentValid; i++)
		for (int j = 0; j < figura.getTamanyFigura() && movimentValid; j++)
			if (figura.getFiguraPos(i, j) != NO_COLOR)
			{
				int fila = figura.getFila() + i;
				int col = figura.getCol() + j;

				if (m_tauler[fila][col] != NO_COLOR)
					movimentValid = false;
			}

	return true;
}

ifstream& operator>>(ifstream& input, Tauler& tauler)
{
	for (int i = INICI_FILES; i <= FINAL_FILES; i++)
		for (int j = INICI_COLUMNES; j <= FINAL_COLUMNES; j++)
		{
			int color;
			input >> color;
			tauler.setTaulerPos(i, j, (ColorFigura) color);
		}

	return input;
}