#include <iostream>

#include "AussieVote.h"

#include <cstring> // std::strcmp, std::strcpy
#include <sstream>  // istringstream
#include <queue>
#include <limits>
#include <cassert>
#include <climits>
#include <cstdlib> // abs
#include <string>
#include <iostream>

using namespace std;

#ifndef DEBUG
#define DEBUG 0
#endif

void error(std::string msg)
{
}

// ------------
// aussie_vote_read2
// ------------

pair<int, int> aussie_vote_read2 (const string& s) {
    istringstream sin(s);
    int n;
    int m;
    sin >> n >> m;
    return make_pair(n, m);}

// ------------
// aussie_vote_read3
// ------------

tuple<int, int, int> aussie_vote_read3 (const string& s) {
    istringstream sin(s);
    int a;
    int b;
    int w;
    sin >> a >> b >> w;
    return make_tuple(a, b, w);}

// -------------
// aussie_vote_solve
// -------------

#define N_CONN 0
#define N_WGHT 1
#define N_IDX  2
#define N_VIS  2

typedef std::tuple<int, int, int> quadruple_t;

void aussie_vote_solve (istream& r, ostream& w) {
    static vector<string> names(20);
    static vector<bool> in(20);
    static int votes[20][20];
    static int candidates;
    static int rounds;
    static int i;
    static int j;
    static int half;
    static bool done;

    r >> rounds;
    // skip a line
    r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cerr << "rounds=" << rounds << endl;
    while (rounds--) {
        r >> candidates;
        std::fill (in.begin(),in.begin()+candidates, true);
        cerr << "candidates=" << candidates << endl;

        // http://stackoverflow.com/questions/477408/ifstream-end-of-line-and-move-to-next-line
        r.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //cerr << "candidates=" << rounds << endl;

        for(i = 0; i<candidates; ++i) {
            getline(r, names[i]);
            cerr << "names[" << i << "]=" << names[i] << endl;
        }
        int voters=0;
        while (r.peek() != '\n') {
            for (i = 0; i < candidates; ++i) {
                r >> j;
                ++votes[i][j];
            }
            r.get();
            ++voters;
        }
        /*
        half = voters/2;
        cerr << "voters=" << voters << endl;
        int tmax=0, tmin=0;
        for (i=0; i<candidates; ++i) {
            for (j=0; j<candidates; ++j) {
                if (in[j]) {
                    votes[i][j] += votes[i-1][j];
                } 
            }
        }
        */
        // fixme just for testing
        w << names[0] << endl;
    }
}

