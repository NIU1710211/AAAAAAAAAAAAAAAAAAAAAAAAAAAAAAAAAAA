#include "Joc.h"

using namespace std;

using namespace std;

int main()
{	
	const string nomFitxerTest = "test_gir_figura_2.txt";
	const string nomFitxerOut = "Tauler.txt";

	Joc joc;

	joc.inicialitza(nomFitxerTest);

	joc.escriuTauler(nomFitxerOut);


}
