#include "ParticleTest.h"
#include "ForceTest.h"

using namespace std;

int main(int argc, char* argv[])
{
    Test* test = new ForceTest();
    test->Initialize();
    while (!test->IsQuit())
    {
        test->Run();
    }

    delete test;
   
    return 0;
}