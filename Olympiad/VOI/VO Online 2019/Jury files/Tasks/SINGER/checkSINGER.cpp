#include "testlib_themis.h"
#include <cstdio>
using namespace std;

const string TASK_NAME = "SINGER";

int main(int argc, char * argv[])
{
    setName("compare two signed int%d's", 8 * int(sizeof(int)));

    #ifdef THEMIS
    registerTestlibThemis(TASK_NAME + ".inp", TASK_NAME + ".out");
    #else
    registerTestlibCmd(argc, argv);
    #endif // THEMIS

    int ja = ans.readInt();
    int pa = ouf.readInt();

    if (ja != pa)
        quitf(_wa, "expected %d, found %d", ja, pa);

    quitf(_ok, "answer is %d", ja);
}
