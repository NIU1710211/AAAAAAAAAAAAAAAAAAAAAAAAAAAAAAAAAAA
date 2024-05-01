#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	llegeixTauler(nomFitxer);
}

void Joc::llegeixTauler(const string& nomFitxer)
{
	ifstream fitxer(nomFitxer);

	if (fitxer.is_open())
	{
		int fitxerTipusFigura;
		int fila, col;
		int nGirs;

		fitxer >> fitxerTipusFigura >> fila >> col >> nGirs;
		
		TipusFigura tipusFigura = (TipusFigura)fitxerTipusFigura;

		m_figuraActual = Figura(tipusFigura, fila, col, nGirs);

		fitxer >> m_tauler;
		fitxer.close();
	}
}
void Joc::escriuTauler(const string& nomFitxer) const
{
	ofstream fitxer(nomFitxer);

	if (fitxer.is_open())
	{
		fitxer << *this;
		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	Figura aux = m_figuraActual;
	aux.girar(direccio);

	if (m_tauler.comprovaColisio(aux))
	{
		m_figuraActual = aux;
		return true;
	}

	return false;
}


bool Joc::mouFigura(int dirX)
{
	Figura aux = m_figuraActual;
	aux.mouLateral(dirX);

	if (m_tauler.comprovaColisio(aux))
	{
		m_figuraActual = aux;
		return true;
	}

	return false;
}

int Joc::baixaFigura()
{
	/*POR HACER: FALTA POR TERMINAR*/

	return 0;
}

ofstream& operator<<(ofstream& output, const Joc joc)
{
	Figura figura = joc.getFiguraActual();
	Tauler tauler = joc.getTauler();

	for (int i = 0; i < TOTAL_FILES; i++)
	{
		for (int j = 0; j < TOTAL_COLUMNES; j++)
			if (i >= INICI_FILES && i <= FINAL_FILES && j >= INICI_COLUMNES && j <= FINAL_COLUMNES)
				if (figura.getFila() + INICI_FILES <= i && i < figura.getFila() + figura.getTamanyFigura() + INICI_FILES &&
					figura.getCol() + INICI_COLUMNES <= j && j < figura.getCol() + figura.getTamanyFigura() + INICI_COLUMNES)
					output << figura.getFiguraPos(i - figura.getFila() - INICI_FILES, j - figura.getCol() - INICI_COLUMNES) << " ";
				else
					output << tauler.getTaulerPos(i, j) << " ";
			else
				output << NO_COLOR << " ";

		output << endl;
	}

	return output;
}