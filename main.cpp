#include <iostream>
#include <vector>
#include <cstdlib>
#include "FiguraGeometrica.h"
#include "Interpretador.h"
#include "Sculptor.h"

int main(int argc, char* argv[]) 
{
    std::string path_script(argc > 1 ? argv[1] : "scripts/entrada.txt");
    std::string path_output(argc > 2 ? argv[2] : "output.off");

    Interpretador Inter;
    std::vector<FiguraGeometrica*> figs = Inter.compile(path_script);
    Sculptor *model = new Sculptor(Inter.getDimx(), Inter.getDimy(), Inter.getDimz());

    std::cout << "Criando modelo 3D" << std::endl;

    for (int i = 0; i < (int)figs.size(); i++) 
    {
        figs[i]->draw(*model);
    }

    model->writeOFF(path_output);

    for (int i = 0; i < (int)figs.size(); i++) 
    {
        delete figs[i];
    }

    delete model;

    return 0;
}
