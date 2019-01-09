#include "testlib_themis.h"

#include <string>

using namespace std;

const string TASK_NAME = "DANANG";

pattern pnum("0|-?[1-9][0-9]*");

bool isNumeric(const string& p)
{
    return pnum.matches(p);
}

int main(int argc, char * argv[])
{
    setName("compare two signed huge integers");

    #ifdef THEMIS
    registerTestlibThemis(TASK_NAME + ".inp", TASK_NAME + ".out");
    #else
    registerTestlibCmd(argc, argv);
    #endif // THEMIS

    string ja = ans.readWord();
    string pa = ouf.readWord();

    if (!isNumeric(ja))
        quitf(_fail, "%s is not a valid integer", compress(ja).c_str());

    if (!ans.seekEof())
        quitf(_fail, "expected exactly one token in the answer file");

    if (!isNumeric(pa))
        quitf(_pe, "%s is not a valid integer", compress(pa).c_str());

    if (ja != pa)
        quitf(_wa, "expected '%s', found '%s'", compress(ja).c_str(), compress(pa).c_str());

    quitf(_ok, "answer is '%s'", compress(ja).c_str());
}
