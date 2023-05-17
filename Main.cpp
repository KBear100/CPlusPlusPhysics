#include "ParticleTest.h"
#include "ForceTest.h"
#include "JointTest.h"

using namespace std;

int main(int argc, char* argv[])
{
    Test* test = new JointTest();
    test->Initialize();
    while (!test->IsQuit())
    {
        test->Run();
    }

    delete test;
   
    return 0;
}