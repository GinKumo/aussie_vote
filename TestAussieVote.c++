// --------------------------------
// TestAussieVote.c++
// Copyright (C) 2015
// Adrian Iley
// --------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "AussieVote.h"

using namespace std;

// -----------
// TestAussieVote
// -----------

// ----
// read
// ----

TEST(AussieVoteFixture, read2) {
    string s("1 10\n");
    const pair<int, int> p = aussie_vote_read2(s);
    ASSERT_EQ(1, p.first);
    ASSERT_EQ(10, p.second);}

TEST(AussieVoteFixture, read3) {
    int a,b,w;
    string s("1 10 100\n");
    const tuple<int, int, int> p = aussie_vote_read3(s);
    std::tie(a,b,w) = p;
    ASSERT_EQ(1,  a);
    ASSERT_EQ(10,   b);
    ASSERT_EQ(100, w);}

// -----
// solve
// -----


TEST(AussieVoteFixture, solve_1) {
    istringstream r("1\n\n3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n2 3 1\n1 2 3\n3 1 2\n\n");
    ostringstream w;
    aussie_vote_solve(r, w);
    ASSERT_EQ("John Doe\n", w.str());}

