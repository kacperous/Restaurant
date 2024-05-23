#define BOOST_AUTO_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

struct TestConfig {

    TestConfig() {

    }

    ~TestConfig() {
    }
};

BOOST_GLOBAL_FIXTURE(TestConfig);
