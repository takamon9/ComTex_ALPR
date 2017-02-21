#include "Comtex.h"

using namespace ComTex_ALPR;

[STAThreadAttribute]
int main()
{
	

	Comtex ^mf = gcnew Comtex();
	mf->ShowDialog();

	return 0;
}

