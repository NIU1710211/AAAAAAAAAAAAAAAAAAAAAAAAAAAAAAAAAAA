#include "Figura.h"

Figura::Figura()
{
	m_tamanyFigura = 0;
}

Figura::Figura(TipusFigura figura, int fila, int col, int nGirs)
{
	m_fila = fila;
	m_col = col;

	switch (figura)
	{
	case FIGURA_O:
		m_tamanyFigura = 2;
		m_figura[0][0] = COLOR_GROC; m_figura[0][1] = COLOR_GROC;
		m_figura[1][0] = COLOR_GROC; m_figura[1][1] = COLOR_GROC;
		break;	
	case FIGURA_I:
		m_tamanyFigura = 4;
		m_figura[0][0] = COLOR_NEGRE;		m_figura[0][1] = COLOR_NEGRE;		m_figura[0][2] = COLOR_NEGRE;		m_figura[0][3] = COLOR_NEGRE;
		m_figura[1][0] = COLOR_BLAUCEL; m_figura[1][1] = COLOR_BLAUCEL; m_figura[1][2] = COLOR_BLAUCEL; m_figura[1][3] = COLOR_BLAUCEL;
		m_figura[2][0] = COLOR_NEGRE;		m_figura[2][1] = COLOR_NEGRE;		m_figura[2][2] = COLOR_NEGRE;		m_figura[2][3] = COLOR_NEGRE;
		m_figura[3][0] = COLOR_NEGRE;		m_figura[3][1] = COLOR_NEGRE;		m_figura[3][2] = COLOR_NEGRE;		m_figura[3][3] = COLOR_NEGRE;
		break;
	case FIGURA_T:
		m_tamanyFigura = 3;
		m_figura[0][0] = COLOR_NEGRE;		m_figura[0][1] = COLOR_MAGENTA;	m_figura[0][2] = COLOR_NEGRE;
		m_figura[1][0] = COLOR_MAGENTA; m_figura[1][1] = COLOR_MAGENTA; m_figura[1][2] = COLOR_MAGENTA;
		m_figura[2][0] = COLOR_NEGRE;		m_figura[2][1] = COLOR_NEGRE;		m_figura[2][2] = COLOR_NEGRE;
		break;
	case FIGURA_L:
		m_tamanyFigura = 3;
		m_figura[0][0] = COLOR_NEGRE;		m_figura[0][1] = COLOR_NEGRE;		m_figura[0][2] = COLOR_TARONJA;
		m_figura[1][0] = COLOR_TARONJA; m_figura[1][1] = COLOR_TARONJA; m_figura[1][2] = COLOR_TARONJA;
		m_figura[2][0] = COLOR_NEGRE;		m_figura[2][1] = COLOR_NEGRE;		m_figura[2][2] = COLOR_NEGRE;
		break;
	case FIGURA_J:
		m_tamanyFigura = 3;
		m_figura[0][0] = COLOR_BLAUFOSC; m_figura[0][1] = COLOR_NEGRE;		  m_figura[0][2] = COLOR_NEGRE;
		m_figura[1][0] = COLOR_BLAUFOSC; m_figura[1][1] = COLOR_BLAUFOSC; m_figura[1][2] = COLOR_BLAUFOSC;
		m_figura[2][0] = COLOR_NEGRE;		 m_figura[2][1] = COLOR_NEGRE;		  m_figura[2][2] = COLOR_NEGRE;
		break;
	case FIGURA_Z:
		m_tamanyFigura = 3;
		m_figura[0][0] = COLOR_VERMELL;	m_figura[0][1] = COLOR_VERMELL;	m_figura[0][2] = COLOR_NEGRE;
		m_figura[1][0] = COLOR_NEGRE;		m_figura[1][1] = COLOR_VERMELL;	m_figura[1][2] = COLOR_VERMELL;
		m_figura[2][0] = COLOR_NEGRE;		m_figura[2][1] = COLOR_NEGRE;		m_figura[2][2] = COLOR_NEGRE;
		break;
	case FIGURA_S:
		m_tamanyFigura = 3;
		m_figura[0][0] = COLOR_NEGRE;	 m_figura[0][1] = COLOR_VERD; m_figura[0][2] = COLOR_VERD;
		m_figura[1][0] = COLOR_VERD; m_figura[1][1] = COLOR_VERD; m_figura[1][2] = COLOR_NEGRE;
		m_figura[2][0] = COLOR_NEGRE;	 m_figura[2][1] = COLOR_NEGRE;	  m_figura[2][2] = COLOR_NEGRE;
		break;
	}

	/*POR HACER: ¿SE DEBE GIRAR AQUI O COMPROBAR LAS COLISIONES AL GENERAR LA FIGURA?*/

	for (int i = 0; i < nGirs; i++)
		girar(GIR_HORARI);
}

void Figura::girar(DireccioGir direccioGir)
{
	ColorFigura aux[MAX_TAMANY][MAX_TAMANY];

	//Copiar figura a aux
	for (int i = 0; i < m_tamanyFigura; i++)
		for (int j = 0; j < m_tamanyFigura; j++)
			aux[i][j] = m_figura[i][j];

	//Trasposar
	for (int i = 0; i < m_tamanyFigura; i++)
		for (int j = 0; j < m_tamanyFigura; j++)
			m_figura[i][j] = aux[j][i];

	switch (direccioGir)
	{
		case GIR_HORARI:
		{
			// Invertir columnes
			for(int i = 0; i < m_tamanyFigura; i++)
				for (int j = 0; j < m_tamanyFigura / 2; j++)
				{
					ColorFigura aux = m_figura[i][j];
					m_figura[i][j] = m_figura[i][m_tamanyFigura - 1 - j];
					m_figura[i][m_tamanyFigura - 1 - j] = aux;
				}
			break;
		}
		case GIR_ANTI_HORARI:
		{
			// Invertir files
			for (int i = 0; i < m_tamanyFigura / 2; i++)
				for (int j = 0; j < m_tamanyFigura; j++)
				{
					ColorFigura aux = m_figura[i][j];
					m_figura[i][j] = m_figura[m_tamanyFigura - 1 - i][j];
					m_figura[m_tamanyFigura - 1 - i][j] = aux;
				}
			break;
		}
	}
}