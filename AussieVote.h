#ifndef __AUSSIE_VOTE
#define __AUSSIE_VOTE 1

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>   // vector
#include <map>      // map

using namespace std;

// ------------
// aussie_vote_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of numbers n and m, where n is the number of vertices and m is the number of edges.
 */
pair<int, int> aussie_vote_read2 (const string& s);

/**
 * read three ints
 * @param s a string
 * @return a three numbers a_i, b_i and w_i, where a_i, b_i are edge endpoints and w_i is the length of the edge.
 */
tuple<int, int, int> aussie_vote_read3 (const string& s);


// -------------
// aussie_vote_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void aussie_vote_solve (istream& r, ostream& w);


/**
 * @param src the beginning node
 * @param dst the goal node
 * @param map containing nodes and their edges with weights
 * @return a vector showing the nodes to travel for the shortest path or [ -1 ] if none.
 */
//vector<int> aussie_vote_eval (int src, int dst, map<int, vector< pair<int, int> > >& g);
vector<int>& aussie_vote_eval (int src, int dst, vector< vector< pair<int, int> > >& g);


#endif /* __AUSSIE_VOTE */
