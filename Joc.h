#ifndef JOC_H
#define JOC_H
using namespace std;

#include "Tauler.h"

class Joc
{
public:
	Joc(): m_tauler(), m_figuraActual() {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void llegeixTauler(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer) const;
	Tauler getTauler() const { return m_tauler; }
	Figura getFiguraActual() const { return m_figuraActual; }

private:
	Tauler m_tauler;

	Figura m_figuraActual;
};

ofstream& operator<<(ofstream& output, const Joc joc);

#endif