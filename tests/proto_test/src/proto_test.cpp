#include "neuro.pb.h"
#include "catch2/catch_test_macros.hpp"

using namespace text_process;

TEST_CASE("Example of proto usage", "[proto]")
{
    NeuroRequest nr;
    nr.set_qid(123);
    nr.set_query("ABC");

    CHECK(nr.qid() == 123);
    CHECK(nr.query() == "ABC");
}
